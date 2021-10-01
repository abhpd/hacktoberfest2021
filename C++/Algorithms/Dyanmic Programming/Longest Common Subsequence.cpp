

/*Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.*/

#include<bits/stdc++.h>
using namespace std;


  //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }

int main(){
  
 int n,m;
 cin>>n>>m;
 string s1,s2;
 cin>>s1>>s2;
 int ans=0;
 ans=lcs(n,m,s1,s2);
 cout<<"Longest Common Subsequence "<<ans<<"\n";

}