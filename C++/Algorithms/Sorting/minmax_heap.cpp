#include<bits/stdc++.h>
using namespace std;
 

void MaxHeapify(int arr[], int i, int n)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if (l < n && arr[l] > arr[i])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(arr, largest, n);
    }
}
void MinHeapify(int arr[], int i, int n)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if (l < n && arr[l] < arr[i])
         smallest= l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        MinHeapify(arr, smallest, n);
    }
}
 



void printArray(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

bool isMAXHeap(int arr[], int i, int n)
{
   
    if (i >= (n - 2) / 2)
        return true;
 
   
    if (arr[i] >= arr[2 * i + 1] &&
        arr[i] >= arr[2 * i + 2]
        && isMAXHeap(arr, 2 * i + 1, n)
        && isMAXHeap(arr, 2 * i + 2, n))
        return true;
 
    return false;
}
bool isMinHeap(int arr[], int i, int n)
{
   
   
    if (2*i + 2 > n) {
        return true;
    }
 
   
    bool left = (arr[i] <= arr[2*i + 1]) && isMinHeap(arr, 2*i + 1,n);
 
   
    bool right = (2*i + 2 == n) ||
            (arr[i] <= arr[2*i + 2] && isMinHeap(arr, 2*i + 2,n));
 
    
    return left && right;

}
 int maxmin(int arr[],int n)
 {
     bool p=isMAXHeap(arr,0,n);
     for (int i = (n-2)/2; i >= 0; --i)
        MinHeapify(arr, i, n);
        if(p==true)
        return 1;
        else 
        return 0;
     
 }
 int minmax(int arr[],int n)
 {
     bool p=isMinHeap(arr,0,n);
     for (int i = (n-2)/2; i >= 0; --i)
        MaxHeapify(arr, i, n);
        if(p==true)
        return 1;
        else 
        return 0;
     
 }
 

int main()
{
   
    int n;
    printf("\nEnter the size of the array ");
    scanf("%d",&n);
    
    int arr[n];
    cout<<"\nEnter the elements of the array ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"\nEntered array ";
    printArray(arr,n);
    int ch;
   cout<<"\nCase 1:Check whether max heap and convert into min heap.\nCase 2:Check whether min heap and convert into max heap.\nEnter your choice ";
   cin>>ch;
   switch(ch)
   {

case 1:
{
int ii=maxmin(arr,n);
if(ii==1)
cout<<"\nGiven array is MAX heap and converted into min heap ";
else
cout<<"\nGiven array is not a Max heap but array is converted into min heap ";
printArray(arr, n);
break;
}
case 2:
{
int jj=minmax(arr,n);
if(jj==1)
cout<<"\nGiven array is min heap and converted into max heap ";
else
cout<<"\nGiven array is not a min heap but array is converted into max heap ";
printArray(arr, n);
    break;
}
    default:
    cout<<"\nWrong choice!";
   }
 
    return 0;
}
