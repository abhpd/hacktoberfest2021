#include <stdio.h>
int main() 
{
    printf("Kindly enter the number of elements: ");
    int n;
    int i=0;
    scanf("%d",&n);

    int arr[n];
    printf("Kindly enter the array elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    countingSort(arr,n);

    printf("\nSorted array is \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
    
void countingSort(int arr[], int n) {
    int arr1[10];

    int x = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
        x = arr[i];
    }

        
    int count_arr[10];

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }

        
    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
}