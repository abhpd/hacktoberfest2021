#include <stdio.h>

int main(){
    int n,i;
    printf("Welcome to Radix Sorting Algorithm\n");
    printf("You can sort the data elements here, I will help you in that\n");
    printf("So lets start with sorting integer datatypes\n");
    printf("So let me know the how much integer datatypes you want me to sort:\n");
    scanf("%d",&n);
    // Creating an array using calloc i.e. array for the user defined length
    int *array = (int *) calloc (n, sizeof(int));

    // Accepting the data elements for the array
    printf("Now you can enter the integers:\n");
    for ( i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    printf("Array before Radix Sort : \n");
    print(array, n);
    radixsort(array, n);
    printf("\nArray after Radix Sort : \n");
    print(array, n);

    return 0;
}


// This function returns the maximum element from the array
int getMax(int a[], int n){
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
// A function to do counting sort of arr[] 
void countSort(int arr[], int n, int exp){
    int output[n]; 
    int i, count[10] = { 0 };

    // storing the element frequency in count array
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    /*Change count[i] so that count[i] now contains actual
      position of this digit in output[]
    */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

void radixsort(int arr[], int n){
    
    int m = getMax(arr, n);
    /* m returns maximum element from array
       Do counting sort for every digit. Note that instead
       of passing digit number, exp is passed. exp is 10^i
       where i is current digit number
    */
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// The function to print array
void print(int arr[], int n){
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}
 
