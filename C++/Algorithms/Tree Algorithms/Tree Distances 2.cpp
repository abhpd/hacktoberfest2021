#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
vector<int> tree[200001];
ll subtreeAns[200001];
ll ans[200001];
int subtreeSize[200001];
 
void preprocessing(int src, int par)
{
    int numOfNodes = 1;
    ll ansForSubtree = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            preprocessing(child, src);
            numOfNodes += subtreeSize[child];
            ansForSubtree += subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[src] = numOfNodes;
    subtreeAns[src] = ansForSubtree;
}
 
 
 
void solve(int src, int par, ll par_ans, int& totalNodes)
{
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : tree[src])
    {
        if(child != par)
            solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}
 
int main() {
   fast_io;
   ll t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        int n;
        cin >> n;
        fr(0,n-1)
        {
            int u,v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        preprocessing(1, 0);
        solve(1, 0, 0, n);
        fr(1,n+1)
            cout << ans[i] <<' ';
   }
   return 0;
}