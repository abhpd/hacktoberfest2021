#include <iostream>
using namespace std;
void swap(int arr[], int j, int k)
{

    int temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
}
void cyclicSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
            int correct = arr[i] - 1;
        if (arr[correct] != arr[i])
        {
            swap(arr, i, correct);
        }
        else
            i++;
    }
}

int main()
{

    int arr[] = {1,3,2,5,4,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cyclicSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    return 0;
}