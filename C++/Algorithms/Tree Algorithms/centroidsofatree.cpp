#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> Centroid(vector<ll> g[], ll n) {
        vector<ll> centroid;
        vector<ll> sz(n);
        function<void (ll, ll)> dfs = [&](ll u, ll prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}
int main() {
    ll n;
    cout<<"Enter nodes: ";
    cin>>n;
    vector<ll> v[n];
    cout<<"Enter edges: ";
    for(ll i=0;i<n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        v[a].push_back(b);
    }
    cout<<" Centroids: \n";
    vector<ll> centroid=Centroid(v,n);
    for(ll i=0;i<centroid.size();i++)
        cout<<centroid[i]+1<<"\n";
	return 0;
}