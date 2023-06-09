//KAHN'S ALGORITHM FOR TOPOLOGICAL SORT

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define mod 998244353

#define fasio ios_base::sync_with_stdio(false); cin.tie(NULL);


vector<ll> adj[10'005]; //Max no of nodes in a graph
vector<ll> in(10'005);  // Calculating indegree of nodes

void kahn(int n)
{
    queue<ll> q;
    for(ll i=0;i<n;i++)
    if(in[i]==0)                
    q.push(i);
    
    //for storing the order
    vector<ll> res;

    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        res.push_back(cur);

        for(auto i: adj[cur])
        {
            in[i]--;
            if(in[i]==0)
            q.push(i);
        }
    }

    if(res.size()!=n)                  //Cycle is present
    cout<<"Not possible"<<endl;
    else
    {for(auto i=res.begin();i!=res.end();i++)  //cycle is getting printed,may not be unique
    cout<<*i<<" ";
    cout<<endl;
    }
}



    void solve()
    {   
        
    ll n,m;
    cout<<"Enter no of Nodes"<<endl;
    cin>>n;
    
    cout<<"Enter no of edges"<<endl;
    cin>>m;

    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        in[y]++;
    }
    
    kahn(n);

    }

int main()
{   
    fasio
    solve();

    return 0;
}
    
    
/*----------------------

INPUT:
Enter no of Nodes
9
Enter no of edges
10

0 1
1 8
1 4
2 3
3 7
3 4
4 6
5 6
4 8

OUTPUT:
0 2 5 1 3 7 4 6 8


-----------------------*/