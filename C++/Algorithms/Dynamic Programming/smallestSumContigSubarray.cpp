#include <bits/stdc++.h>
using namespace std;
 
int smallestSumSubarray(int arr[], int n)
{
    int min_ending_here = INT_MAX;
    int min_so_far = INT_MAX;
    for (int i=0; i<n; i++)
    {
        if (min_ending_here > 0)
            min_ending_here = arr[i];
        else
            min_ending_here += arr[i];
        min_so_far = min(min_so_far, min_ending_here);           
    }
    return min_so_far;
}
 
 
// Driver program to test above
int main()
{
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << smallestSumSubarray(arr, n);
    return 0;    
}