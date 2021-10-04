#include <bits/stdc++.h>
using namespace std;

void printKMax(int arr[], int n, int k)
{

    deque<int> dq;

    int i;
    for (i = 0; i < k; ++i)
    {

        while ((!dq.empty()) && arr[i] >= (arr[dq.back()]))
        {

            dq.pop_back();
        }

        dq.push_back(i);
    }

    for (; i < n; ++i)
    {

        cout << arr[dq.front()] << " ";

        while ((!dq.empty()) && dq.front() <= (i - k))
        {

            dq.pop_front();
        }

        while ((!dq.empty()) && arr[i] >= (arr[dq.back()]))
        {

            dq.pop_back();
        }

        dq.push_back(i);
    }

    cout << arr[dq.front()];
}

int main()
{
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}