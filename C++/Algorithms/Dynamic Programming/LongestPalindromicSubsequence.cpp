#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq (string A);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << longestPalinSubseq (s) << endl;
    }
}

 int dp[1001][1001];
int longestpal(string s, int i, int j){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) 
        return dp[i][j] = 2 + longestpal(s, i+1, j-1);
     return dp[i][j] = max(longestpal(s, i, j-1), longestpal(s, i+1, j));
    }

int longestPalinSubseq (string S)
{
    
    memset(dp, -1, sizeof(dp));
    int low = 0;
    int high = S.length()-1;
    int res = longestpal(S, low, high);
    return res;
}