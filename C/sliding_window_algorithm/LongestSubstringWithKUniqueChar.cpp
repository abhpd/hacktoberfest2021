#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int Longest_Substring_With_K_Unique_Char(string s, int k){
	unordered_map<char, int> mp;

	int i=0, j=0;
	int ans=-1;

	while(j < s.size()){
		mp[s[j]]++;
		if(mp.size() == k){
			ans=max(ans,j-i+1);
			j++;
		}
		else if(mp.size() < k){
			j++;
		}
		else{
			while(mp.size() > k){
				mp[s[i]]--;
				if(mp[s[i]]==0){
					mp.erase(s[i]);
				}
				i++;
			}
			j++;
		}
		debug(ans);
	}
	return ans;
}

int main(){
	freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);

	string s = "aabacbebebe";
	int k = 3;

	// cin>>s>>k;

	// s = "hq";
	// k = 2;

	// s = "meayl";
	// k= 2;

	cout<<Longest_Substring_With_K_Unique_Char(s, k);
}