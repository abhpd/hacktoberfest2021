#include<bits/stdc++.h>
using namespace std;
int vis[100000],adj[100000];
queue <int> q;

bfs (int x)
{
	vis[x]=1;
	queue <int> q;
	q.push_back(x);
	int k=adj[x].size;
	for (int i=0;i<k;i++)
	{
		q.push_back(adj[x][i]
	
int main () {
	int n,m;
	cin >>n>>m;
	for (int i=0;i<m;i++)
	{
		int u,v;
		cin >>u>>v;
		adj[u].push_back(v);
	}

	bfs(1);
	return 0;
	}	
