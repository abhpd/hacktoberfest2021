#include<stdlib.h>
#include<stdio.h>

int BinarySearch(int arr[], int len, int elem);

int main()
{
    int i,elem,len=0;

    printf("\n\n\n\t\t\t\tBINARY SEARCH");
    printf("\n\nEnter array length : ");
    scanf("%d",&len);                       //inputting aray size

    int *arr = (int*) calloc(len,sizeof(int));

    printf("\n\nEnter array elements : ");
    for(i=0;i<len;i++){
       scanf("%d",&arr[i]);                 //inputting aray elements and array must be sorted to perform binary search
    }

    printf("\n\nEnter element to be searched : ");
    scanf("%d",&elem);                      //inputting element to be searched

    int foundAt = BinarySearch(arr,len,elem);

    if(foundAt==-1)
        printf("\n\n\t\tGiven element not found in the given array!");
    else
        printf("\n\n\t\tGiven element found in the given array at %d position",foundAt+1);

    return 0;
}

int BinarySearch(int arr[], int len, int elem){
    int beg=0;
    int last=len-1;
    int mid;
    while(beg<=last){
        mid=(beg+last)/2;
        if(arr[mid] == elem)
            return mid;
        else if(arr[mid] > elem)
            last=mid-1;
        else
            beg=mid+1;
    }
    return -1;
} 