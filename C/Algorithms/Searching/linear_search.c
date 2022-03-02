#include <stdio.h>

int linearSearch( int v[], int len, int term)
{
    for (int i = 0; i < len; i++)
        if (v[i] == term)
            return i;
    return -1;
}

int main()
{
    int i, n, term, arr[50];
    printf("Enter number of elements to be entered: ");
    scanf("%d", n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the term to search for: ");
    scanf("%d", &term);
    int found = linearSearch(arr, n, term);
    if (found == -1)
        printf("Element not present");
    else
        printf("Element found at index: %d", found);
    return 0;
}