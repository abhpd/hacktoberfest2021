//There are two strings S and V and we need to find the length of shortest subsequence in S such that it is not a subsequence in V.

#include<bits/stdc++.h>
using namespace std;
int solve(string S, string V)
{
    int m = S.length();
    int n = V.length();
    int** dp = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        dp[i] = new int[n+1];
    }
    for(int i=0; i<=m; i++)
    {
        dp[i][n] = 1; 
    }
    for(int i=0; i<=n; i++)
    {
        dp[m][i] = 10001;
    }
    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            int k = j;
            for(; k<n; k++)
            {
                if(S[i]==V[k])
                    break;
            }
            if(k==n)
                dp[i][j] = 1;
            else
                dp[i][j] = min(dp[i+1][j], 1+dp[i+1][k+1]);
        }
    }
    return dp[0][0];
}

int main(){
	string s1, s2;
	
	cin>>s1;
	cout<<"Enter second string - ";
	cin>>s2;
	cout<<"Length of shortest subsequence - "<<solve(s1, s2)<<endl;
}
