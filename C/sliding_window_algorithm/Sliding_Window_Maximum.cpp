// https://leetcode.com/problems/sliding-window-maximum/

#include<iostream>
#include<bits/stdc++.h>
#include "../debug.h"
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;

    list<int> lt;

    if(k==1)
        return nums;

    for(int i=0; i<k; i++){
        while(!lt.empty() && nums[i] > lt.back()){
            lt.pop_back();
        }
        lt.push_back(nums[i]);
    }
    ans.push_back(lt.front());


    for(int i=0; i<nums.size()-k; i++){        
        if(nums[i] == lt.front()){
            lt.pop_front();
        }

        while(!lt.empty() && nums[i+k] > lt.back()){
            lt.pop_back();
        }

        lt.push_back(nums[i+k]);
        ans.push_back(lt.front());
    }

    return ans;
}

int main(){
	// vector<int> v = {1,3,-1,-3,5,3,6,7};
	// int k = 3;

	// vector<int> v = {7,2,4};
	// int k = 2;

    // vector<int> v = {1,3,1,2,0,5};
    // int k = 3;

    vector<int> v = {9,10,9,-7,-4,-8,2,-6};
    int k = 5;

	freopen("../input.txt", "r", stdin);  
	// freopen("../output.txt", "w", stdout);
    #ifndef ONLINE_JUDGE
        freopen("../Error.txt", "w", stderr);
    #endif

	vector<int> ans = maxSlidingWindow(v, k);

	for(auto &x : ans)
		cout<<x<<" ";
}