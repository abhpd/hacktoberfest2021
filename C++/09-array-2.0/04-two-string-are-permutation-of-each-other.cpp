#include<iostream>
#include <cstring>
using namespace std;

bool isPermutation(char a[], char b[]){ // char *a, char *b are same
	int la = strlen(a);
	int lb = strlen(b);
	int sum=0;
	if(la!=lb)
		return false;
	// check for frequency, a-z
	int frequency[26] = {0}; // count at index 0 represents numbers of 'a's and so on..
	for(int i=0;i<la;i++){
		frequency[a[i]-'a']++; // if frequency[0] it means a[i] was 'a' and we are inc. its count by 1
	}
	for(int i=0;i<lb;i++){
		frequency[b[i]-'a']--; // we are dec. the count of letters
	}
	//if after dec. the count become 0 then both have same frequency of char.
	for(int i=0;i<26;i++){
		if(frequency[i]!=0)
			return false;
	}
	return true;

}
int main(){
	char a[100] = "abbca";
	char b[100] = "abccb";
	if(isPermutation(a,b)){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}

	return 0;
}

/*
finding two arrays/strings are permutation of each other?

1. check both must have same length.
2. the frequency of char in both the array must be same.

=> in frequncy array a,b,c,d ... ,z are stored.
we can get index as
a=>0
b=>1
c=>2 ...

'a' -'a' => 0
'b' -'a' => 1
'c' -'a' => 2

*/