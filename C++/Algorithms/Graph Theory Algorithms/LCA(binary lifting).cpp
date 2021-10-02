#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define ld long double
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<ll> graph[N];
ll dp[N][(ll) log2(100005)], n, lvl[N];

void dfs(int source, int par, int level){
	dp[source][0] = par;
	lvl[source] = level;
	for(auto k : graph[source])
		if(k != par)
			dfs(k, source, level + 1);
}

void init(){
	dfs(1, -1, 0);
	for(int i = 1; i <= (log2(n)); ++i)
		for(int j = 1; j <= n; ++j)
			if(dp[j][i - 1] != -1)
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
}

ll LCA(int u, int v){
	if(lvl[u] > lvl[v]) swap(u, v);
	ll d = lvl[v] - lvl[u];
	while(d){
		int jump = log2(d);
		v = dp[v][jump];
		d -= pow(2, jump);
	}
	if(v == u) 
		return v;
	for(int i = log2(n); i >= 0; --i){
		if(dp[v][i] != -1 && dp[v][i] != dp[u][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[v][0];
}

int main(){
	fast;
	cin >> n;
	for(int i = 1; i <= n - 1; ++i){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(dp, -1, sizeof(dp));
	init();
	ll q;
	cin >> q;
	while(q--){
		ll a, b;
		cin >> a >> b;
		cout << LCA(a, b) << "\n";
	}
	return 0;
}
