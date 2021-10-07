
#include<iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the size array: ";
    cin>>n;
    int arr[n];

    //Taking array input
    cout<<"Enter the array: ";
    for(int i = 0;i < n; i++){
        cin>>arr[i];
    }

    //SelectionSort method
    for(int i=0;i<5;i++){
        int min = 5;
        for(int j=i;j<5;j++){
           
           if(arr[j]<arr[min]){
               min = j;
           }

        }
        int temp = arr[i];
        arr[i]   = arr[min] ;
        arr[min] = temp;
    }

    //Printing array
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}