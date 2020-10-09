#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[], int n);

void print(int a[], int n);

void main()
{
    int length, i;
    printf("Welcome to Insertion Sort!!\n");
    printf("You can sort the data elements here, I will help you in that\n");
    printf("So lets start with sorting integer datatypes\n");
    printf("So let me know the how much integer datatypes you want me to sort:\n");
    scanf("%d", &length);

    // Creating an array using calloc i.e. array for the user defined length
    int *a = (int *) calloc (length, sizeof(int));

    // Accepting the data elements for the array
    printf("Now you can enter the integers:\n");
    for ( i = 0; i < length; i++)
    {
        scanf("%d", &a[i]);
    }

    // Sorting the Array in Ascending Order by using Insertion Sort
    insertionSort(a, length);

    // Printing the Sorted Array
    print(a, length);

    printf("Thanks for investing time in Me!!");
}

void insertionSort(int a[], int n)
{
    int temp, i, j;
    printf("Started Sorting Your Array\n");
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i-1;

        while (temp < a[j] && j >= 0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;    
    }
    printf("Just Finised the Sorting Using Insertion sort\n");    
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