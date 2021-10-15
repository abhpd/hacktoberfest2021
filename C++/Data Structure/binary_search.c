#include <stdio.h>

int main()
{
    int arr[50], size, num,low=0,mid,high;
    printf("Enter number of elements : ");
    scanf("%d", &size);
    printf("Enter Array Elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter value to find : ");
    scanf("%d", &num);
    high = size - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (arr[mid] < num)
        {
            low = mid + 1;
        }
        else if (arr[mid] == num)
        {
            printf("\n%d found at %d location..\n", num, mid + 1);
            break;
        }
        else
        {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    if (low > high)
    {
        printf("\nNot found! %d isn't present in the list", num);
    }
    return 0;
}
