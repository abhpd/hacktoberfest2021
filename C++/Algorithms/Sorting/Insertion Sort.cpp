#include <bits/stdc++.h> 
using namespace std; 
  
void insertionSort(int arr[], int n)  
{  
    int i, j, key;  
    for(i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        //Move elements one position ahead till their value is greater than key
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        //insert key at correct position
        arr[j + 1] = key;  
    }  
}  
  
void printArray(int arr[], int n)  
{  
    int i; 
    cout<<"Sorted array is : ";
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
}  
  
int main()  
{  
    int n; 
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    
    insertionSort(arr, n);  
    printArray(arr, n);  
  
    return 0;  
} 