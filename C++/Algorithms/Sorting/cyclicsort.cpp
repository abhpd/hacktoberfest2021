#include <iostream>
#include <stdio.h>

using namespace std;
void CyclicSort(int arr[], int n);
void Swap(int *arr, int i);

int main(void)
{
    int n;
    cout << "Enter the length of the array " << endl;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    CyclicSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}

void CyclicSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] != arr[i]-1)
        {
            Swap(arr, i);
        }
        else
        {
            i++;
        }
    }
}

void Swap(int *arr, int i)
{
    int temp = arr[i];
    int next = arr[i] - 1;

    arr[i] = arr[next];
    arr[next] = temp;
}