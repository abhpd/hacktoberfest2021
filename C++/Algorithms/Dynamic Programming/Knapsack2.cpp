/*
Problem:
Problem Statement
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of w 
i
​
  and a value of v 
i
​
 .

Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10 
 
Input
Input is given from Standard Input.
Output
Print the maximum possible sum of the values of items that Taro takes home.

Sample Input 1
3 8
3 30
4 50
5 60
Sample Output 1 
90
Items 1 and 3 should be taken. Then, the sum of the weights is 3+5=8, and the sum of the values is 30+60=90.

Sample Input 2 
1 1000000000
1000000000 10
Sample Output 2 
10
Sample Input 3 
6 15
6 5
5 6
6 4
6 6
3 5
7 2
Sample Output 3 
Copy
17
Items 2,4 and 5 should be taken. Then, the sum of the weights is 5+6+3=14, and the sum of the values is 6+6+5=17.


*/

#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vmb;   /// Matrix boolean using vector
typedef vector<vll> vmll; /// Matrix long long using vector
 
const int INF = 1e9;
 
/// Top-down knapsack using Branch and bound approach
/// dp:     calculate subproblem
/// isDone:   if subproblem is calculated before
/// weight: weight of element
/// value:  value of element
/// n: length of array
/// i: index
/// j: weight
int tdkp01(vmll &dp, vmb &isDone, vi &weight, vi &value, int n, int i, int j)
{
    if (j <= 0)     /// Cant take more elements
        return 0;
 
    if (i == n)     /// End of array
        return INF;
 
    if (isDone[i][j]) /// If solved before
        return dp[i][j];
 
    isDone[i][j] = true; /// Solving Recursively
    return dp[i][j] = min(tdkp01(dp, isDone, weight, value, n, i + 1, j),
                          tdkp01(dp, isDone, weight, value, n, i + 1, j - value[i]) + weight[i]);
}

/// Finding max sum where total weight <= limit
int kp01(vmll &dp, vmb &isDone, vi &weight, vi &value, int n, int k, int vsum)
{
    vsum++;
    while (vsum--) /// Finding from limit -> 0 for faster ending
        if (tdkp01(dp, isDone, weight, value, n, 0, vsum) <= k)
            return vsum;
 
    return 0;
}
 
int main()
{
    int n, k;
    cin >> n >> k;
 
    vi weight(n), value(n);
    int vsum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> weight[i] >> value[i];
        vsum += value[i];
    }
 
    vmll dp(n + 1);
    vmb isDone(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        dp[i].assign(vsum, 0);
        isDone[i].assign(vsum, 0);
    }
 
    cout << kp01(dp, isDone, weight, value, n, k, vsum);
    return 0;
}
