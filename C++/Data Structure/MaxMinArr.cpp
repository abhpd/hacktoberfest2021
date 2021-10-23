#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << ("Enter Size of Array ");
    cin >> n;

    cout << ("Enter Elements ");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int Min = arr[0];
    int Max = arr[0];

    for (int j = 0; j < n; j++)
    {
        if (arr[j] >= Max)
        {
            Max = arr[j];
        }
        if (arr[j] <= Min)
        {
            Min = arr[j];
        }
    }
    cout << ("The Max Element in Array is ") << Max << endl;
    // cout << Max;
    // cout << endl;
    cout << ("The Min Element in Array is ") << Min;
    // cout << Min;

    return 0;
}
