#include <iostream>
#include <climits>
using namespace std;

bool pairsum(int arr[], int n, int k)
{
    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n + 1; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << i << "  " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    
    
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;

    cout << pairsum(arr, 8, k) << endl;
    return 0;
}
