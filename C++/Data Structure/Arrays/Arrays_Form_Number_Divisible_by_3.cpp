#include <iostream>
#include <vector>
using namespace std;

void computeNumberFromSubarray(vector<int> arr, int k)
{

    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for (int j = k; j < arr.size(); j++)
    {
        if (found)
        {
            break;
        }

        sum = sum + arr[j] - arr[j - k];

        if (sum % 3 == 0)
        {
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "No such Subarray exists" << endl;
    }

    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr = {8, 23, 45, 12, 56, 4};
    int k = 3;

    computeNumberFromSubarray(arr, k);
    return 0;
}