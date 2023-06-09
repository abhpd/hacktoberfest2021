#include<bits/stdc++.h>
using namespace std;

// linear search algorithm
void linear(int arr[], int num){
	int i,found=1;
	for(i=0;i<7;i++) if(arr[i]==num) {
		cout<<"Founded at location: "<<i<<endl;
		found--;
		break;
	}
	if(found){
		cout<<"Element not present!!!"<<endl;
	}
}
// binary search algorithm
void binary(int array[], int size, int value) 
{   
    int first = 0,         // First array element       
    last = size - 1,       // Last array element       
    middle,                // Mid point of search       
    position = -1;         // Position of search value   
    bool found = false;        // Flag   
    while (!found && first <= last) 
    {      
        middle = (first + last) / 2;     // Calculate mid point      
        if (array[middle] == value)      // If value is found at mid      
    	{         
                found = true;         
                position = middle;      
        }      
        else if (array[middle] > value)  // If value is in lower half         
            last = middle - 1;      
        else         
            first = middle + 1;          // If value is in upper half   
    }   
    if(position == -1) cout<<"NOT Found!!!"<<endl;
    else cout<<"Found!!!"<<endl;
}

int main(){
	int t=1,arr[7],n,i,j,l,choise;
	while(t){
		cout<<"Welcome to Search counter!"<<endl;
		cout<<"Enter your array of 7 elements: "<<endl;
		for(i=0;i<7;i++){
			cin>>arr[i];
		}
		cout<<"Your entered array: "<<endl;
		for(j=0;j<7;j++){
			cout<<arr[j]<<endl;
		}
		int size = 7;
		cout<<"Enter element to be searched : "<<endl;
		cin>>l;
		cout<<"Enter your choise:/n1. Linear Search/n2. Binary Search"<<endl;
		cin>>choise;
		if(choise == 1) linear(arr,l);
		else if(choise == 2) binary(arr,size,l);
		else cout<<"Enter 1 for Linear implementation and 2. for Binary implementation"<<endl;
		cout<<"Want to enter more?[0/1]: "<<endl;
		cin>>t;
	}
}
