/* This problem belongs to Linear DP Section.

Problem Statement: You are a professional robber planning to rob houses along a street.
Each house has some value stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Help the thief to maximize the value that he can rob tonight without alerting the police.
 
Logic: For every ith house there are two possibilities i.e either we can include it or not. 
If we include it, then we are not allowed to include (i-1)th house value as they are adjacent houses and this is the only constraint.

***dp[i] gives us the maximum value that thief can rob till ith house(0-indexing).

If we include the ith house: 
 ->val[i]+dp[i-2]
If we exclude it:
 ->dp[i-1]
dp[i]=max(val[i]+dp[i-2],dp[i-1])


Hence maximum value that this thief can rob in a street of n houses without alerting the police is max(val[n-1]+dp(n-2),dp(n-1)).

*/


#include<bits/stdc++.h>
using namespace std;


//function to calculate the maximum value that can be robbed by thief
int maxValue(vector<int>val,int n)
{
 int i,dp[n];
 dp[0]=val[0];
 for(i=1;i<n;i++)
 {
  if(i==1)
   dp[i]=max(val[i],dp[i-1]);
  else
   dp[i]=max(val[i]+dp[i-2],dp[i-1]);//Calculating the max value by including the current house and excluding it.
 }
 return dp[n-1];
}


int main()
{
 int n,i,x;
 vector<int>val;
 cout<<"Enter the total number of houses\n";
 cin>>n;
 cout<<"Enter the value of each house\n";
 for(i=0;i<n;i++)
 {
  cin>>x;
  val.push_back(x);
 }
 cout<<"\nMaximum value that the thief can rob is "<<maxValue(val,n)<<endl;
 return 0;
}
