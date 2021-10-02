#include<iostream>
#include<bits/stdc++.h>
#include "../debug.h"
using namespace std;

int LargestSubarrayOfSumK(vector<int> &v, int k){
	int ans = 0;
	int sm = 0;
	int temp = 0;

	int i=0, j=0;

	while(j != v.size()+1){
		if(k > 0 ? sm < k : sm > k){
			// k > 0 ? sm += v[j] : sm -= v[j];
			sm += v[j];
			ans++;
			j++;

		}
		else if(sm == k){
			temp = max(temp, ans);
			// k > 0 ? sm -= v[i] : sm += v[i];
			sm -= v[i];
			i++;
			ans--;
		}
		else if(k > 0 ? sm > k : sm < k){
			// k > 0 ? sm -= v[i] : sm += v[i];
			sm -= v[i];
			i++;
			ans--;
		}
		debug(sm);
		// debug(ans);
	}
	return temp;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	#ifndef ONLINE_JUDGE
        freopen("../Error.txt", "w", stderr);
    #endif

	vector<int> v = {-4,-1,-1,-1,-2,-3,-5};
	int k = -2;

	// v = {1,2,3};
	// k=5;

	cout<<LargestSubarrayOfSumK(v, k);
}