#include <bits/stdc++.h>
using namespace std;

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void sort012(int a[], int n)
{
    int high = n - 1, low = 0, mid = 0;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a, mid, low);
            mid++;
            low++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a, high, mid);
            high--;
        }
    }
}
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void sort012(int a[], int n)
{
    int high = n - 1, low = 0, mid = 0;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a, mid, low);
            mid++;
            low++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a, high, mid);
            high--;
        }
    }
}