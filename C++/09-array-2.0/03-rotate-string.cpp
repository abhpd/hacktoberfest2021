#include<iostream>
#include <cstring>
using namespace std;

char *rotate(char a[], int k){
	int i = strlen(a), s;
	int j=i;
	while(j>=0){
		a[j+k] = a[j];
		j--;
	}
	s=0;
	j=i;
	while(k--)
		a[s++] = a[j++];

	a[i] ='\0';

	return a;
}
int main(){
	char arr[100]="My Name is Danish";
	cout<<arr<<endl;
	cout<<rotate(arr,5)<<endl;
	return 0;
}

/*

1. shift array to right by k position
2. copy k element from n(array size) onwards to 0 onwards
3. set null at n(array size)


*/