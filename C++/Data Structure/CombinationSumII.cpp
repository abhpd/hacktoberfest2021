//https://leetcode.com/problems/combination-sum-ii/
//Leetcode 40

class Solution {
public:
    
    void combinations(int start,int target,vector<vector<int>>& all,vector<int>& c,vector<int>& temp)
    {
        if(target==0)
        {
            all.push_back(temp);
            return;
        }

        for(int i=start;i<c.size();i++)
        {
            if(c[i]>target) break;
            if(i!=start and c[i-1]==c[i] ) continue;
            temp.push_back(c[i]);
            combinations(i+1,target-c[i],all,c,temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> all;
        vector<int> combi;
        combinations(0,target,all,nums,combi);
        return all;
    }
};
