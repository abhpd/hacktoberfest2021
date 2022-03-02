#include <stdio.h>

int binarySearch(int array[], int start_index, int end_index, int element)
{
    while (start_index <= end_index)
    {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    return -1;
}

int main()
{
    int i, n, term, arr[50];
    printf("Enter number of elements to be entered: ");
    scanf("%d", n);
    printf("Enter the elements in sorted manner: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the term to search for: ");
    scanf("%d", &term);
    int found = binarySearch(arr, 0, n-1, term);
    if (found == -1)
        printf("Element is not present.");
    else
        printf("Element is found at index: %d", found);
    return 0;
}