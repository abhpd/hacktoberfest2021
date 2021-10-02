class Solution {
public:
    vector<vector<int>> ans;
    
    void allper(vector<int>& nums,int pos,vector<bool>&used,vector<int>& cur){
        if(nums.size()==cur.size()){
            ans.push_back(cur);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++){
            if(used[i])continue;
            used[i]=true;
            cur.push_back(nums[i]);
            allper(nums,pos+1,used,cur);
            cur.pop_back();
            used[i]=false;
        }
    }    
        
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        vector<int> cur;
        allper(nums,0,used,cur);
        return ans;
    }
};
