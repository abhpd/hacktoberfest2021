#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
//recursively calling this function will make a BST starting from root node to leaf
    void createBST(vector<int>nums,int left,int right,vector<int>&res){
        if(left<=right){
        int mid=(left+right)>>1;
        res.push_back(nums[mid]);
        createBST(nums,left,mid-1,res);
        createBST(nums,mid+1,right,res);}
    }
    //funtion to convert array to BST
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int>res;
         createBST(nums,0,nums.size()-1,res);
         return res;
    }
};

//Driver Code Starts.
int main(){
	
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	
	return 0;
}  