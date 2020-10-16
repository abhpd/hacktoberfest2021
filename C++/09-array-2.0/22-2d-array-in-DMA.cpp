#include<iostream>

using namespace std;

int main(){
	int n=3,m=4;// n rows, m columns

	int **arr = new int*[n];
	for(int i=0;i<n;i++){
		arr[i] = new int[m];
	}
	//insert
	int value =1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m; j++){
			arr[i][j] = value++;
		}
	}

	//show
	for(int i=0;i<n;i++){
		for(int j=0;j<m; j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	// delete secondary array
	for(int i=0;i<n;i++){
		delete []arr[i];
	}
	// delete primary array
	delete []arr;

	return 0;
}
/*
after deleting pointer is pointing to garbage value
*/