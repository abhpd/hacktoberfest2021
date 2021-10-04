#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>>ans;
    vector<int>v;
    map<int,int>vis;
    void recursive(vector<int>& nums,int j,int ind)
    {
        if(j==nums.size())
        {
            ans.push_back(v);
            return ;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(vis[nums[i]]==0)
            {
                vis[nums[i]]=1;
                v.push_back(nums[i]);
                recursive(nums,j+1,i+1);
                v.pop_back();
                vis[nums[i]]=0;
            }
        }

    }

     vector<vector<int> > permute(vector<int> &nums) {

        recursive(nums,0,0);
        for(auto x:ans)
        {
            for(auto y:x)
            {
                cout<<y<<" ";
            }
             cout<<endl;
        }
    }
};

int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        Solution obj;
        vector<int>v;

        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            v.push_back(a);
        }

        obj.permute(v) ;  // function call
        break;

    }
    return 0;
}
