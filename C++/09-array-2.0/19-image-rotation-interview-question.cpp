#include <iostream>
using namespace std;

int swap(int *a ,int *b){
 	int t = *a;
 	*a= *b;
 	*b = t;
    return 0;
 }


int main(){
	// rotate 2d matrix by 90deg, clock or anti-clock
	// o(1) space, inplace rotation.
	// take transpose, do not take any extra array. 
	// take mirror image, swap half row each
	int n,value=1;
	//cin>>n;// taking square matrix
	n=4;
	int a[4][4];

	// insert 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//cin>>a[i][j];
			a[i][j] = value++;
		}
	}
	// print
	cout<<"Original Matrix: \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	// take transpose
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		b[i][j]=a[j][i];
	// 	}
	// }
	

	// print
	cout<<"Transpose Matrix: \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
	// take mirror image
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			swap(&a[i][j], &a[i][n-j-1]);
		}
	}

	// print
	cout<<"Rotated by 90 degree: \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}

	return 0;

}