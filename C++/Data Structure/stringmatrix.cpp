#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
int stringsearch(string word,int r,int c,string str[],int row_count,int col_count,int index)
{
	int count=0;
	if(r>=0 && r<=row_count && c>=0)
	{
		if(c<=col_count && word[index]==str[r][c])
		{
			char res=word[index];
			index++;
			str[r][c]=0;
			if(word[index]==0)count=1;
			else
			{
				count+=stringsearch(word,r+1,c,str,row_count,col_count,index);
				count+=stringsearch(word,r-1,c,str,row_count,col_count,index);
				count+=stringsearch(word,r+1,c+1,str,row_count,col_count,index);
				count+=stringsearch(word,r+1,c-1,str,row_count,col_count,index);
			}
		}
	}
}

int findstring(string word,int r,int c,string str[],int row_count,int col_count)
{
	int count=0;
	for(int i=0;i<row_count;i++)
		for(int j=0;j<col_count;j++)
		{
			count+=stringsearch(word,i,j,str,row_count-1,col_count-1,0);
		}
}
main()
{
	string s = "MAGIC";
    string str[] = { "BBABBM",
                       "CBMBBA",
                       "IBABBG",
                       "GOZBBI",
                       "ABBBBC",
                       "MCIGAM"};
	int len=sizeof(str)/sizeof(str[0]);
	string inp[len+1];
	for(int i=0;i<len;i++)
	{
		inp[i]=str[i];
	}
	
	cout<<findstring(s,0,0,str,len,str[0].size());

return 0;
}


