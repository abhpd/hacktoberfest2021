/* An array of integers and a target is given.
You need to place + and - signs before those integers such that the total sum is equal to target 
Find the number of such expressions */
class Solution {
public:
    int subset(vector<int>&nums,int sum,int n,vector<vector<int>>&dp)
    {
        if(sum==0)
            return 1;
        else if(n==0)
            return 0;
        else if(dp[n][sum]!=-1)
            return dp[n][sum];
        else if(nums[n-1]==0)
            return dp[n][sum]=subset(nums,sum,n-1,dp);
        else if(nums[n-1]<=sum)
            return dp[n][sum]=subset(nums,sum-nums[n-1],n-1,dp)+subset(nums,sum,n-1,dp);
        else
            return dp[n][sum]=subset(nums,sum,n-1,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(nums[i]==0)
            count++;
        }
          
        int diff=(sum+target);
        if(diff==0 && target!=0 && count==0)
            return 1;
        if(diff%2!=0)
            return 0;
        else
            diff=diff/2;
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(diff+1,-1));
        subset(nums,diff,nums.size(),dp);
        if(dp[n][diff]!=-1)
        return dp[n][diff]*pow(2,count);
        else return pow(2,count);
    }
};

