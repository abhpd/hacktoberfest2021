#include<stdio.h>
#include<stdlib.h>

void selectionSort(int a[], int n);
void print(int a[], int n);

void main() 
{   
    int length, i;
    printf("Welcome to the Selection Sort Algorithm!!\n");
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

    // Implemention the Selection Sort (in Ascending Order)
    selectionSort(array, length);
    
    // Printing the Sorted elements
    print(array, length);
}

void selectionSort(int a[], int n)
{
    int i, j, minimunIndex, temp;

    printf("Just started to sort Using the Selection Sort Algorithm\n");

    for ( i = 0; i < n; i++)
    {
        minimunIndex = i;

        for ( j = i + 1; j < n; j++)
        {
            if (a[minimunIndex] > a[j])
                minimunIndex = j;    
        }
        temp = a[i];
        a[i] = a[minimunIndex];
        a[minimunIndex] = temp;
    }

    printf("Ended Sorting using Selection Sort\n");
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