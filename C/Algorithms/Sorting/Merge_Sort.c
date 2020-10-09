#include<stdio.h>
#include<stdlib.h>

void mergeArray(int a[], int start1, int end1, int start2, int end2);
void mergeSort(int a[], int start, int end);
void print(int a[], int n);

void main()
{
    int length, start1, end1, end2, i;
    printf("Welcome to Merge Sort!!\n");
    printf("You can sort the data elements here, I will help you in that\n");
    printf("So lets start with sorting integer datatypes\n");
    printf("So let me know the how much total integer datatypes you want me to sort:\n");
    scanf("%d", &length);

    // Creating an array using calloc i.e. array for the user defined length
    int *a = (int *) calloc (length, sizeof(int));

    printf("So how are you going to break the array of %d length into?\n", length);
    printf("So let me know the length of the first array:\n");
    scanf("%d", &end1);     // Asking User to Break the Array into two parts as his/her wish

    // Checking the array is correctly divided into two parts
    while(end1 > length)
    {
        printf("Please enter a valid range!! You decided to create an array out of bound!!\nPlease enter an integer within %d:\n", length);
        scanf("%d", &end1);
    }

    end2 = length - end1;
    printf("Hence the length of the another array will be %d\n", end2);

    // Accepting the data elements for the array1
    printf("Now you can enter the elements for the first array:\n");
    for ( i = 0; i < end1; i++)
    {
        scanf("%d", &a[i]);
    }

    // Accepting the data elements for the array2
    printf("Now enter the elements for the Second array:\n");
    for ( i = end1; i < length; i++)
    {
        scanf("%d", &a[i]);
    }
    
    // Confirming the 1st array User Has entered
    printf("So you have entered the First array as follows:\n");
    print(a, end1);

    // Printing out the Whole array the User has entererd
    printf("And now the whole array entered by you is as follows {UNSORTED ARRAY} :\n");
    print(a, length);
    printf("The length of the full array is: %d\n", length);

    // Implementing the Merge Sort
    mergeSort(a, 0, length);
    
    // Printing the SORTED ARRAY
    print(a, length);

}

void mergeArray(int a[], int start1, int end1, int start2, int end2)
{
    int i, j, k;
    
    int *temp = NULL;
    // Creating an array according to the length passed as parameters
    temp = (int *) calloc ((end1+end2), sizeof(int));
    // Initializing the start of array1 to 'i' and array2 to 'j'
    i = start1;
    j = start2;
    // And Initializing the k variable for the Merged array (i.e. array1 + array2 {sorted})
    k = 0;

    while (i <= end1 && j <= end2)
    {   
        // Sorting in the ascending orde
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // If the array2 got exhausted then copy the remaining elements of array1 into the Merged array
    while( i <= end1 )
        temp[k++] = a[i++];
    
    // If the array1 got exhausted then copy the remaining elements of array2 into the Merged array
    while( j <= end2 )
        temp[k++] = a[j++];
    
    // Copying the Merged Sorted Array into the real one
    for(i = start1, j = 0; i <= end2; i++, j++)
        a[i] = temp[j];
}

void mergeSort(int a[], int start, int end)
{
    int middle;
    /* 
        Recrusively calling the mergeSort function to breakdown the array upto single elements
        And then start Merging in the Sorted Manner.
    */
    if(start < end)
    {   // Middle = start+end / 2
        middle = (start + end) / 2;

        // Breaking the array into n/2 (1st half)
        mergeSort(a, start, middle);

        // Breaking the array into n/2 (2nd half)
        mergeSort(a, middle + 1, end);

        // Merging the (half) Array's
        mergeArray(a, start, middle, middle+1, end);
    }
        
}

void print(int a[], int n)
{
    int i;
    printf("So now Printing the Array below:\n");

    for ( i = 0; i < n; i++)
    {
        printf("%c%4d%c\n", 221, a[i], 222);
    }    
}