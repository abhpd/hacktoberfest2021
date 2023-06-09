#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#include "../debug.h"

int PickToys(string s, int k){
	int i=0, j=0;
	int ans = 0;
	map<char, int> mp;

	while(j<s.size()){
		mp[s[j]]++;

		if(mp.size() < k){
			j++;
		}
		else if(mp.size() == k){
			debug(j);
			ans = max(ans, j-i+1);
			j++;
		}
		else{
			while(mp.size() > k){
				mp[s[i]]--;
				if(mp[s[i]]==0)
					mp.erase(s[i]);
				i++;
			}
			j++;
		}
	}
	return ans;
}

int main(){
	// freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);
	freopen("../Error.txt", "w", stderr);
	string s = "abaccab";
	cout<<PickToys(s, 2);
}