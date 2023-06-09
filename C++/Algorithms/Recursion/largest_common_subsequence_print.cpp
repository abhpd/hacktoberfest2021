#include<iostream>
using namespace std;
string sub(string s, string g,int s1,int g1,string f)
{
	if(s1==0)
	{
		return f;
	}
	else if(g1==0)
	{
		return sub(s,g,s1-1,g.length(),f);
	}
	else if(s[s1-1]==g[g1-1])
	{
		f=f+s[s1-1];
		return sub(s,g,s1,g1-1,f);
	}
	else if(s[s1-1]!=g[g1-1])
	{
		return (sub(s,g,s1,g1-1,f));
	}
}
int main()
{
	string s="abcdgh";
	string g="abedfhr";
	string f;
	cout<<sub(s,g,s.length(),g.length(),f);
}
