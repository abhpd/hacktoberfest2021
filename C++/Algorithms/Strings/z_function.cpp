#include<iostream>
#include<vector>

using namespace std;

vector<int> z_function(string &p,string &t)
{
	string s=p+'#'+t;
	int n=s.size(),l=0,r=0;					
	vector<int> z(n,0);
	for(int i=1;i<n;i++)
	{
		if(i<=r)
			z[i]=min(z[i-l],r-i+1);			

		while(i+z[i]<n && s[z[i]]==s[i+z[i]])	
			z[i]++;
		if(i+z[i]-1>r)						
			l=i,r=i+z[i]-1;
	}
	return z;
}

int main()
{
	string p,t;
	cout<<"\nEnter a pattern : ";
	cin>>p;
	cout<<"\nEnter a text to be searched for the pattern : ";
	cin>>t;
	vector<int> z=z_function(p,t);
	vector<int> ans;
	for(int i=0;i<z.size();i++)
		if(z[i]==p.size())
			ans.push_back(i-p.size()-1);
	cout<<"\nNumber of times the pattern matched is : "<<ans.size();
	if(ans.size())
	{
		cout<<"\nString found at index : ";
		for(auto x:ans)
			cout<<x<<" ";
	}
	cout<<endl;

return 0;
}
