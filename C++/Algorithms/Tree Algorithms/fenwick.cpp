#include <bits/stdc++.h>
using namespace std;
void build_fenwick(vector<int> &fenwick)
{
	//find immediate parent 
	// 0101(5) ,1011
	// 011 , 101 -> 001 ,add 100
	for(int i=1;i<fenwick.size();i++)
	{
		int immediate_parent= i+ (i & (-i));
		if(immediate_parent<fenwick.size())
		{
			// cout<<i<<" "<<immediate_parent<<endl;
			fenwick[immediate_parent]+=fenwick[i];
		}
	}

}
int get_fenwick(vector<int> &fenwick,int idx)
{
	int ans=0;
	while(idx!=0)
	{
		ans+=fenwick[idx];
		idx-= idx&-idx;
	}
	return ans;
}
void update_fenwick(vector<int> &fenwick, int idx, int value_difference)
{
	//find immediate parent 
	// 0101(5) ,1011
	// 011 , 101 -> 001 ,add 100
	while(idx<fenwick.size())
	{
		fenwick[idx]+=value_difference;
		idx= idx+ (idx & (-idx));
		
	}

}
int main()
{
	
    int n;
    cin>>n;
    vector<int> a(n+1),fenwick(n+1);
    //remember start from 1, 0 is hard to deal with..
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	fenwick[i]=a[i];
    }
    build_fenwick(fenwick);
    for(int i=1;i<=n;i++)
    	cout<<fenwick[i]<<" ";

    cout<<endl;
    update_fenwick(fenwick,7, 1);
    for(int i=1;i<=n;i++)
    	cout<<fenwick[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    	cout<<get_fenwick(fenwick,i)<<endl;


    //build fenwick

}