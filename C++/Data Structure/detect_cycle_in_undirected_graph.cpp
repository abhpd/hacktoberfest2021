#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    vector<bool> vis;
bool ans;
void dfs(vector<int> adj[], int v, int p) {
    vis[v] = true;
    for (auto x : adj[v]) {
        if (x == p)continue;
        if (vis[x]) {
            ans = true;
            return;
        }
        else dfs(adj, x, v);
    }
}

    bool isCycle(int n, vector<int> adj[]) {
        // Code here
     vis.assign(n + 1, false);
    ans = false;
    for (int i = 0; i < n; i++)if (!vis[i])dfs(adj, i, -1);
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends