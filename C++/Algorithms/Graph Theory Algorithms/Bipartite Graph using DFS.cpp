/*
Author: Mohit Radadiya
Github Profile: https://github.com/radadiyamohit81
*/

#include<bits/stdc++.h>
using namespace std;
 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl "\n"
#define f_input freopen("inputs/input.txt", "r", stdin)
#define f_output freopen("inputs/output.txt", "w", stdout)

#define VI vector<int>
#define pb push_back

class Solution{
public:
	bool BipartiteGraph(int v, VI adj[]){
		VI color(v, -1);
		for (int i = 0; i < v; i++)
		{
			if(color[i] == -1){
				stack<int> s;
				s.push(i);
				
				color[i] = 1;
				while(!s.empty()){
					int node = s.top();
					s.pop();
					if(color[node] == -1) color[node] = 1;
					for(auto it: adj[node]){
						if(color[it] == -1){
							color[it] = 1 - color[node];
							s.push(it);
						}else if(color[it] == color[node]){
							return false;
						}
					}
				}
			}
		}
		return true;
	}
};

int main(){
	fast;
#ifndef ONLINE_JUDGE
	f_input;
	//~ f_output;
#endif
	
	int n, m;
	cin >> n >> m;
	VI adj[n+1];
	for (int i = 0; i < m; i++)
	{
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	
	Solution obj;
	bool result = obj.BipartiteGraph(n, adj);
	if(result)
		cout << "Graph is Bipartite!" << endl;
	else
		cout << "Graph is not Bipartite!" << endl;
	
	return 0;
}
