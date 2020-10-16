#include<iostream>

using namespace std;

int main(){
	int *p = new int(30);
	int *q = new int;
	int *arr = new int[5];
	int *arr1 = new int[5];

	cout<<*p<<endl;
	cout<<*q<<endl;//random/garbage value

	for(int i=0;i<5;i++){
		cin>>arr[i];
		arr1[i]=arr[i]*5;
	}

	for(int i=0;i<5;i++){
		cout<<arr[i]<<"=>"<<arr1[i]<<" ";
	}
	cout<<endl;

	// delete
	delete p;
	delete q;
	delete []arr;
	delete []arr1;

	return 0;
}
/*
after deleting pointer is pointing to garbage value
*/