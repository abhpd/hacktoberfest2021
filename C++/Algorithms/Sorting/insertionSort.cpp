#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    
    //Taking array Input
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int arr[7] = {2,15,42,26,39,92,30};
    
    //InsertionSort method
    for(int i=0;i<n;i++){
        for(int j = i+1;j>0;j--){
             if(arr[j] < arr[j-1]){

                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
              }
        
        }   
    }
     
    //Printing Method
    for(int i=0;i < n;i++){
           cout<<arr[i]<<" ";
    }
    return 0;
}