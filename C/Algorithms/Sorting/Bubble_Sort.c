#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[], int n);
void print(int a[], int n);

void main()
{
    int length, i;
    printf("Welcome to Bubble Sorting Algorithm\n");
    printf("You can sort the data elements here, I will help you in that\n");
    printf("So lets start with sorting integer datatypes\n");
    printf("So let me know the how much integer datatypes you want me to sort:\n");
    scanf("%d", &length);

    // Creating an array using calloc i.e. array for the user defined length
    int *array = (int *) calloc (length, sizeof(int));

    // Accepting the data elements for the array
    printf("Now you can enter the integers:\n");
    for ( i = 0; i < length; i++)
    {
        scanf("%d", &array[i]);
    }
    
    // Implementing the Bubble Sort (in Ascending Order)
    bubbleSort(array, length);
    // Printing the Sorted elements
    print(array, length);

    printf("Thanks for investing time in me!!\n");
}

void bubbleSort(int a[], int n)
{
    int i, j, temp;
    printf("So just Started Sorting the integers Using Bubble Sort Algorithm\n");

    for ( i = 0; i < n - 1; i++)
    {
        for ( j = 0; j < n - 1 - i; j++)
        {   
            // Sorting the array in ascending order
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        
    }
    
    printf("Just ended the Sorting of the elements\n");
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