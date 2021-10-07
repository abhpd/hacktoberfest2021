#include<stdlib.h>
#include <stdio.h>

int LinearSearch(int arr[], int len, int elem);

int main()
{
    int i,elem,len=0;
    
    printf("\n\n\n\t\t\t\tLINEAR SEARCH");
    printf("\n\nEnter array length : ");
    scanf("%d",&len);                       //inputting aray size
    
    int *arr = (int*) calloc(len,sizeof(int));
    
    printf("\n\nEnter array elements : ");
    for(i=0;i<len;i++){
       scanf("%d",&arr[i]);                 //inputting aray elements
    }
    
    printf("\n\nEnter element to be searched : ");
    scanf("%d",&elem);                      //inputting element to be searched
    
    int foundAt = LinearSearch(arr,len,elem);
    
    if(foundAt==-1)
        printf("\n\n\t\tGiven element not found in the given array!");
    else
        printf("\n\n\t\tGiven element found in the given array at %d position",foundAt+1);

    return 0;
}

int LinearSearch(int arr[], int len, int elem){
    for(int i=0;i<len;i++){
        if(arr[i] == elem){
            return i;
        }
    }
    return -1;
}