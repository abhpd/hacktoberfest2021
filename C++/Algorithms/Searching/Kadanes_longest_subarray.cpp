#include <iostream>
using namespace std;

int largestSubarraySum1(int arr[], int n)
{
    int cs = 0, ms = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cs += arr[i];
        if (cs < 0)
        {
            cs = 0;
        }
        sum = max(sum, cs);
    }
    return sum;
}

int main()
{
    //Array Containing
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    cout << largestSubarraySum1(arr, n) << endl;
    return 0;
}
