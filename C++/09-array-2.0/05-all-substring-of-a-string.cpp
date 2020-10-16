#include<iostream>
#include <cstring>
using namespace std;

void substring(char a[]){

	for(int i=0; a[i]!='\0';i++){
		for(int j=i; a[j]!='\0';j++){
			//cout<<i<<", "<<j;
			for(int k=i;k<=j;k++)
				cout<<a[k];
			cout<<endl;
		}
	}
}

int main(){
	char a[] ="abc";
	substring(a);
	return 0;
}

/*

any consucutive sub-segment is sub string.
a
b
c
ab
bc
abc
all are substring of abc

*/