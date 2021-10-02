#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int LongestBand(vector<int> &v){
	unordered_map<int,int> mp;
	int n = v.size();
	for(int i=0; i<n; i++){
		mp[v[i]]=1;
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		int cnt = 1;
		if(mp[v[i]-1] == 0){
			int tmp = v[i];
			while(mp[tmp+1] != 0){
				cnt++;
				tmp++;
			}
		}
		ans=max(ans,cnt);
	}
	return ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	vector<int> v = {1,9,3,0,18,5,2,4,10,7,12,6};
	cout<<LongestBand(v);
}