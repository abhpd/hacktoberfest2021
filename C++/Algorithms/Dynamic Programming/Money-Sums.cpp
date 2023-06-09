// Quesiton : https://cses.fi/problemset/task/1745/ 

// You have n coins with certain values. Your task is to find all money sums you can create using these coins.

// Input
// The first input line has an integer n: the number of coins.
// The next line has n integers x1,x2,…,xn: the values of the coins.

// Output
// First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.

#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define sz(x) (ll)x.size()

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int n;
    cin >> n;
    vector<int> x(n);
    int mx = n * 1000; // Max Sum of the coins 
    bool dp[n + 1][mx + 1];
    memset(dp , 0 , sizeof(dp));
 
    for(int &e : x)
    cin >> e;
 
    dp[0][0] = 1;
 
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= mx; ++j)
        {
            dp[i][j] = dp[i-1][j];
            int left = j - x[i-1];

            if(left >= 0 and dp[i-1][left])
                dp[i][j] = 1;
        }
    }
    vector<int>ans;
    for(int i = 1; i <= mx; ++i)
        if(dp[n][i])
            ans.push_back(i);
 
    cout << sz(ans) << '\n';
    for(int e : ans)
    cout << e << ' ';
} 

// Input:
// 4
// 4 2 5 2

// Output:
// 9
// 2 4 5 6 7 8 9 11 13