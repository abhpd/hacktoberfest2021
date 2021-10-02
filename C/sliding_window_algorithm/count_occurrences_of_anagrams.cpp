#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int CountOccurrencesOfAnagrams(string s, string str){
	int s_a = 0, s_b = 0;
	int str_a = 0, str_b = 0;

	for(int i=0; i<str.size(); i++){
		if(str[i]=='a')
			s_a++;
		else
			s_b++;

		if(s[i]=='a')
			str_a++;
		else
			str_b++;
	}

	int i=0, j=str.size()-1;
	int ans = 0;

	while(j<s.size()){
		if(s_a == str_a && s_b == str_b)
			ans++;
		if(s[i]=='a')	
			s_a--;
		else
			s_b--;
		if(s[j+1]=='a')
			s_a++;
		else
			s_b++;
		i++;
		j++;
	}
	return ans;
}


int main(){
	freopen("../input.txt", "r", stdin);  
	freopen("../output.txt", "w", stdout);

	string s= "aabaabaa";
	string ptr = "aaba";
	cin>>s>>ptr;

	cout<<CountOccurrencesOfAnagrams(s, ptr);
}