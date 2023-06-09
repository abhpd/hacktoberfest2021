#include<bits/stdc++.h>
using namespace std;
int i,j;
const int maxn=1000;
int dp[1000][1000];
string lps(string str1,string str2,int l,int r)
{
	 if(l==0||r==0) //base case
	 {
	 	return string("");
	 }
	 else if(str1[l-1]==str2[r-1]) //if the elements of string and its reverse are same
	 {
	 	return lps(str1,str2,l-1,r-1)+str1[l-1]; //then use recursive of size -1 for both
	 } //plus the character which are equal
	 else if(dp[l-1][r]>dp[l][r-1]) //else recurse for minimum of them.
	 {
	 	return lps(str1,str2,l-1,r); 
	 }
	 return lps(str1,str2,l,r-1);
}


int lps_l(string str1,string str2,int l,int r)	//to calclate length
{
	 if(l==0||r==0) //size is 0 then return 0 and assign 0
	 {
	 	dp[l][r]=0;
	 	return dp[l][r];
	 } 
	 if(dp[l][r]!=-1) //if value in the buffer then return it directly
	 {
	 	return dp[l][r];
	 } 
	 if(str1[l-1]==str2[r-1]) //if elements are same then assign value to dp[][]
	 {
	 	dp[l][r]=lps_l(str1,str2,l-1,r-1)+1;
	 	return dp[l][r];
	 }
	 else
	 {
	 	dp[l][r]=max(lps_l(str1,str2,l-1,r),lps_l(str1,str2,l,r-1)); //dp would be minimum of both then return
	 	return dp[l][r];
	 }
}
int main()
{
	 int n;
	 string s;
	 cout<<"Enter the string for finding longest palindrome subsequence:";
	 cin >> s;
	 n = s.length();
	 for(i=0;i<=n;i++)
	 {
		for(j=0;j<=n;j++)
		{
			dp[i][j]=-1;
		}
	 }
	
	 string rstr=s;
	 reverse(rstr.begin(),rstr.end());
	 int len=lps_l(s,rstr,n,n);
	 cout<<"The length of the longest palindromic subsequence is : "<<lps(s,rstr,n,n)<<"\nlength : "<<len<<endl;
	 return 0;
}
