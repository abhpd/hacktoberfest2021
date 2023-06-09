#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007
vector <ll>ar[1000001];
vector<ll>res;
ll in[1000001];
int kahn(int n)
{
    priority_queue<ll,vector<ll>,greater<ll>>q;
    for(ll i=1;i<=n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        ll cur=q.top();
        res.push_back(cur);
        q.pop();
        for(int child:ar[cur])
        {
            in[child]--;
            if(in[child]==0)
            q.push(child);
        }
    }
    return res.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    // cin>>t;
     t=1;
    while(t--)
    {
       ll n,m;
       cin>>n>>m;
       while(m--)
       {
           ll x,y;
           cin>>x>>y;
           ar[x].push_back(y);
           in[y]++;
       } 
      if(kahn(n)!=n)
      cout<<"Impossible"<<endl;
      else
      {
        for(ll node:res)
       {
           cout<<node<<" ";
       }
      }
    }
    
    return 0;
}