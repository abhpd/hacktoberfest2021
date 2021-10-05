// Bubble Sort == Reapetedly swap two adjacent elements if they are in wrong order
// For n elements in array == (n-1) iterations to get sorted array
// If ith iteration == Check upto (n-i)
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];


    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int counter = 1;
    while(counter < n-1)
    {
        for(int i=0;i<n-counter;i++)
        {
            if(arr[i]>arr[i+1])
            {
                // Swapping the numbers
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        counter++;
    }

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }





    return 0;
}
 