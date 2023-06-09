class Solution {
public:
    int subsetCount(vector<int> nums,int s)
    {
        int n=nums.size();
        int ar[n+1][s+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(i==0) ar[i][j]=0;
                if(j==0) ar[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                if(nums[i-1]<=j)
                {
                    ar[i][j] = ar[i-1][j] + ar[i-1][j-nums[i-1]];
                }
                else{
                    ar[i][j] = ar[i-1][j];
                }
            }
        }
        return ar[n][s];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto x:nums)
            sum+=x;
        if((sum-target)%2 || target>sum) return 0;
        int s1 = (sum-target)/2;
        return subsetCount(nums,s1);
    }
};
