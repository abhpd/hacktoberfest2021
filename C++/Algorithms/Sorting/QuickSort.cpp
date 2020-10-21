#include <stdio.h>
#include <iostream>


int partition(int *a,int start,int end)
{
    //last element
    int pivot=a[end];


    int PivIndex=start;
    int i,t; //t is temporary variable

    //if value is less or equal than pivot, swapping it at left side

    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[PivIndex];
            a[PivIndex]=t;
            PivIndex++;
        }
    }
    //Now exchanging value of
    //pivot and P-index
    t=a[end];
    a[end]=a[PivIndex];
    a[PivIndex]=t;

    //at last returning the pivot value index
    return PivIndex;
}
void quicksort(int *a,int start,int end)
{
    if(start<end)
    {
        int P_index=partition(a,start,end);
        quicksort(a,start,P_index-1); //recursive functions
        quicksort(a,P_index+1,end);
    }
}

int main()
{
    int v;
    std::cout << "Values to sort: "; std::cin >> v;
    int arr[v];
    for (int a = 0; a<v; a++) std::cin >> arr[a];
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, n-1);
    printf("Sorted array: \n");
    for (auto numb: arr) std::cout << numb << " ";
}
