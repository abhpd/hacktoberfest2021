#include<iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
	return a>b; // decending
}

int main(){
	int a[] ={1,5,4,3,2,61,8};
	int n = sizeof(a)/sizeof(int);

	// sort(startpointer, endpointer)
	sort(a,a+n); // start address, all emenets

	for(int i=0;i<n;i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;

	int b[] ={1,5,4,3,2,61,8};
	sort(b, b+5 ,compare); // start address, 5 elements, descending
	// only 5 elements will be sorted

	for(int i=0;i<n;i++){
		cout<<b[i]<<", ";
	}
	cout<<endl;
	

	return 0;
}

/*

sort using inbuilt function


*/