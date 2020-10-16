#include<iostream>
#include <cstring>
using namespace std;


int main(){
	string a[10] = {"Apple", "Mango", "Guava", "Banana", "Papayaa"};
	int n = 5;
	// sort
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i] > a[j]){
				string temp =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	// print
	for(int i=0;i<n-1;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}

/*

lexicographically-first letter first
bubble sort

*/