//total number of connected components
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int find(int x,vector<int>&p)
{
    if(p[x]==x)
    return x;
    else
    return p[x]=find(p[x],p);
}
void merge(int x,int y,vector<int>&r,vector<int>&p)
{
    x=find(x,p);
    y=find(y,p);
    if(x!=y)
    {
        if(r[x]<r[y])
        {
            p[x]=y;
            r[y]+=r[x];
        }
        else
        {
            p[y]=x;
            r[x]+=r[y];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;//number of vertices and number of edges
    vector<int>p(n);
    for(int i=0;i<n;i++)
    p[i]=i;
    vector<int>r(n,0);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        merge(u,v,r,p);
    }
    set<int>s;
    for(int i=0;i<n;i++)
    s.insert(p[i]);
    cout<<s.size();//total number of permutations
    return 0;
}
