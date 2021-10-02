#include<iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l+1, n2 = r-m;
    int left[n1];
    int right[n2];

    for(int i=0; i<n1; i++)
        left[i] = arr[l+i];
    
    for(int i=0; i<n2; i++)
        right[i] = arr[m+1+i];
    
    int i=0, j=0, k=l;

    while(i<n1 && j<n2)
    {
        if(left[i]<=right[i])
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    while(i<n1)
        arr[k++] = left[i++];
    while(j<n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l<r)
    {
        int m = (r+l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r); 
    }
}

void print(int arr[], int size)
{
    for(int i=0; i<size; i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int size;
    cout<<"Enter the Size of Array: ";
    cin>>size;

    int a[size];

    cout<<"\nEnteer elements of array one by one: ";
    for(int i=0; i<size; i++)
    {
        cout<<"\nEnter the elemet as "<<i+1<<" position: ";
        cin>>a[i];
    }
    cout<<"\n\nPerforming Merge Sort\n\n";

    int r = a[size-1];
    int l = 0;

    mergeSort(a, l, r);
    print(a, size);

    return 0;
}