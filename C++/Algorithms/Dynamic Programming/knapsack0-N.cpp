#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    int temp;
    vector<int> val;
    vector<int> wt;
    cout << "enter number of elements: ";
    cin >> n;
    cout << "Enter the knapsack value : ";
    cin >> W;
    cout << "Enter values : ";
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        val.push_back(temp);
    }
    cout << "Enter Weights : ";
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        wt.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        cout << val[i] << "  " << wt[i] << endl;
    }
    vector<int> dp(W + 1, 0);
    for (int i = 0; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - wt[j] >= 0)
                dp[i] = max(dp[i], val[j] + dp[i - wt[j]]);
        }
    }
    cout << dp[W];
    return 0;
}