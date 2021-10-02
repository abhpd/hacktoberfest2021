//Performing operations in array
#include <stdio.h>
#include <stdlib.h>
#define size 100

// reading array
create(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter the element a[%d]\n", i);
        scanf("%d", &a[i]);
    }
}

//insertion
int insert(int a[], int n, int ele, int pos)
{
    int i;
    if (n == size)
    {
        printf("Array Fall");
        return;
    }

    for (i = n; i >= pos + 1; i--)
        a[i] = a[i - 1];

    a[pos] = ele;
    n = n + 1;
    return n;
}

//delete by position
int delete_pos(int a[], int n, int pos)
{
    int i;
    if (n == 0)
    {
        printf("Array empty");
        return;
    }

    for (i = pos; i <= n - 2; i++)
        a[i] = a[i + 1];

    n = n - 1;
    return n;
}

//traverse
void trav(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// sorting

void sort(int a[], int n)
{
    int i, t, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

// search
int lsearch(int a[], int n, int ele)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        if (a[i] == ele)
        {
            return i;
        }
    }
    else if (i == n) return -1;
}

// main function
void main()
{
    int a[size] = {0};
    int n, menu, pos, ele, m;

    do
    {

        printf("1.Create\n2.Insert\n3.Delete by position\n4.Delete by element\n5.Search\n6.Sort\n7.Traverse\n8.Exit\n");
        scanf("%d", &menu);
        switch (menu)
        {

        case 1:
            printf("Enter the no. of elements");
            scanf("%d", &n);
            if (n < 0 || n > size)
            {
                printf("Enter another value!Thank you!!");
                exit(0);
            }
            create(a, n);
            trav(a, n);
            break;

        case 2:
            printf("Enter the element and the position to insert");
            scanf("%d %d", &ele, &pos);
            n = insert(a, n, ele, pos);
            trav(a, n);
            break;

        case 3:
            printf("Enter the position to delete");
            scanf("%d", &pos);
            n = delete_pos(a, n, pos);
            trav(a, n);
            break;

        case 4:
            printf("Enter the element to delete");
            scanf("%d", &ele);
            m = lsearch(a, n, ele);
            n = delete_pos(a, n, m);
            break;

        case 5:
            printf("Enter the element to search");
            scanf("%d", &ele);
            m = lsearch(a, n, ele);
            if (m == -1)
                printf("Not Found");
            else
                printf("Found");
            break;

        case 6:
            sort(a, n);
            trav(a, n);
            break;

        case 7:
            trav(a, n);
            break;

        case 8:
            printf("Thank You!!!Visit Again"); //exit condition
            exit(0);
            break;

        default:
            printf("Enter the menu number between 1 to 7\n");
        }
    } while (1);
}