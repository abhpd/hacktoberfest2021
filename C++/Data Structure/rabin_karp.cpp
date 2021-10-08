#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void rabincarp(char text[],char pat[])
{
	//cout<<"here";
	int m=sizeof(pat),n=sizeof(text),i=0,hashpat=0,hashtext,t=0,base=10;
		cout<<int(pat[0])<<endl;

	while(i<m)
	{hashpat+=pat[i]*pow(base,m-i-1); i++;}
	cout<<hashpat;
	for(i=0;i<n;i++)
	{
		if(i==0)
		while(t<m)
		{
			hashtext+=text[t]*pow(base,m-t-1);t++;
		}
		else
		{
			hashtext=(hashtext-(text[i]*pow(base,m-1))*base) + text[i+m];
		}
		
		if(hashtext==hashpat)
		{
			int flag=0,itr=0;
			while(itr<m)
			{
				if(text[i+itr]!=pat[itr]){flag++;break;}itr++;
			}
			if(flag==0)
			{
				cout<<"Pattern found at position "<<i<<endl;
			}
		}
	}
	
}

main()
{
	char text[]="aaaaa";char pat[]="a";
	//getline(text);
	//getline(pat);
//	cout<<text<<"  "<<pat;
rabincarp(text,pat);
//cout<<"leaving";
return 0;
}


