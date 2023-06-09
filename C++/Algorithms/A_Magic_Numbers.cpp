


#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<cstdlib>
using namespace std;

bool is_magic(string s)
{
	int len=s.length();
	for(int i=0;i<len;i++)
 
		if(s[i]!='4' && s[i]!='1')
 
			return false;
 
		if(s[0]=='4')
 
			return false;
 
		if(s.find("444")!=s.npos)
 
			return false;
 
 
		return true;
 
}
int main()
{
	string s;
	cin >> s;
	if(is_magic(s))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}