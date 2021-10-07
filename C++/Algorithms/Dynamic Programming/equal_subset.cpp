/*
    Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets 
    such that the sum of elements in both subsets is equal.

    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
*/

#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    long long sum = 0;
    for(auto i:nums) {
        sum += i;
    }
    if(sum%2 != 0) return false;
    
    long long sum_by_2 = sum/2;
    long long N = nums.size();
    long long dp[N+1][sum_by_2+1];
    
    memset(dp, -1, sizeof(dp));
    for(long i=0;i<=sum_by_2;i++) dp[0][i]=false;
    for(long i=0;i<=N;i++) dp[i][0]=true;
    
    for(long i=1;i<=N;i++) {
        for(long j=1;j<=sum_by_2;j++) {
            if(j<nums[i-1])
                dp[i][j]=dp[i-1][j];
            else {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    
    return dp[N][sum_by_2];
}

int main() {
    vector<int> nums = {1,5,11,5};
    if(canPartition(nums)) {
        cout<<"Array can be partitioned into equal subsets.";
    }
    else {
        cout<<"Array can not be partitioned into equal subsets.";
    }
    return 0;
}