/*
problem statement:-
Given a string s, find the length of the longest substring with unique characters.

test case:- 
s : given String

Output: 3
Explanation: The answer is "abc", with the length of 3.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
	cin>>s;
    
    map<char,int> mp;
        int n=s.size();
        if(n==0) return 0;
        int l=0,r=0,count=0;
        int ans=INT_MIN;
        while(l<n){
            mp[s[l]]++;
            if(mp[s[l]]==1)count++;
            
            while(r<l && count<l-r+1){
                mp[s[r]]--;
                if(mp[s[r]]==0)count--;
                r++;
            }
                ans=max(ans,l-r+1);
            l++;
        }
    
	cout<<"Length of longest substring with unique characters"<<ans<<endl;
	
    return 0;
}

// time complexity:-  O(N)
// space complexity:- O(N)