#include <iostream>
using namespace std;
int main(){
	int A[10]={1,2,3,4,5,6,7,8,9};
	//binary search 
	int l=A[0];
	int h=A[sizeof(A)-1];
	int mid;
	//suppose we want to search for element 5 
	int key=5;
	for(int i=0;i<sizeof(A)-1;i++){
		mid=l+h/2;
		if(A[i]==key)
		cout<<"Element found !";
		else if(key>A[i])
		{l=mid+1;	
		}
		else if(key<A[i])
		{h=mid-1;	
		}
		else
		cout<<"Element not found!";
	}
	return 0;
}
