//recursive + dynamic programming code for nth fibonacci number
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int fibonacci(int n,int dp[])
{
    if(n==0 || n==1)
    {
        return n;
    }
    else
    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;//input for n the asked fibonacci term
    int dp[n+1];
    int ans=fibonacci(n,dp);
    cout<<ans;
    return 0;
}
