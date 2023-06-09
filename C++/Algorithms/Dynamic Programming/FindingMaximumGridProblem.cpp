#include <iostream>
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// DP, Kadane's Algorithm

int MaxSumSubArray(vector<int> &list)
{
    int n = list.size();
    int sumNow = 0;
    int maxSum = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        sumNow = sumNow + list[i];
        if (sumNow < 0)
            sumNow = 0;
        if (maxSum < sumNow)
            maxSum = sumNow;
    }
    for (int i = 0; i < n; i++)
    {
        if (list[i] > maxSum)
            maxSum = list[i];
    }
    return maxSum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    // taking input
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            matrix[i][j] = num;
        }
    }
    int maxGridSum = 0;
    // making DP array
    // appending first column to it
    vector<int> DP(n, 0);
    // configuring L and R for grids
    for (int i = 0; i < m; i++)
    {
        DP.assign(n, 0);
        for (int j = i; j < m; j++)
        {
            for (int k = 0; k < n; k++)
            {
                DP[k] += matrix[k][j];
            }
            int calculate = MaxSumSubArray(DP);
            cout << "sum at : " << i << " and " << j << " : " << calculate << endl;
            if (calculate > maxGridSum)
                maxGridSum = calculate;
        }
    }
    // vector<int> arr{1, -4, 2, -9, 2};
    cout << maxGridSum << endl;
    return 0;
}
