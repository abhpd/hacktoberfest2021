#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool bipartite;

void color(int u, int curr)
{
    if (col[u] != -1 and col[u] != curr)
    {
        bipartite = false;
        return;
    }

    col[u] = curr;
    if (vis[u])
        return;
    vis[u] = true;
    for (auto i : adj[u])
    {
        color(i, curr xor 1);
    }
}

int main()
{
    bipartite = true;

    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n, false);
    col = vector<int>(n, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            color(i, 0);
        }
    }
    if (bipartite)
        cout << "Graph is bipartite";
    else
        cout << "Graph is not bipartite";
}