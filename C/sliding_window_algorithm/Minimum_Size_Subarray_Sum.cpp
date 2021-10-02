// https://leetcode.com/problems/minimum-size-subarray-sum/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int MinimumSizeSubarraySum(vector<int> &v, int target){
	int ans = INT_MAX;
	int sm = 0;

	int i=0,j=0;
	while(j < v.size()){
		sm += v[j];
		while(sm >= target){
			ans = min(ans, j-i+1);
			sm -= v[i];
			i++;
		}
		j++;
	}
	return ans==INT_MAX ? 0 : ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {2,3,1,2,4,3};
	int target = 7;

	v = {1,4,4};
	target = 10;

	cout<<MinimumSizeSubarraySum(v, target);
}