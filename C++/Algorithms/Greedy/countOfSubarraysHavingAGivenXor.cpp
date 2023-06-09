//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jets();
    int n,k;
    cin>>n>>k;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
    	cin>>vec[i];
    }
    int xo=0,count=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
    	xo^=vec[i];
    	if(xo==k)
    		count++;
    	int temp=xo^k;
    	auto it=mp.find(temp);
    	if(it!=mp.end()){
    		count+=it->second;
    	}
    	mp[xo]++;
    }
    cout<<count<<endl;


    return 0;
}