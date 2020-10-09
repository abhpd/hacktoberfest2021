//this algorithms assumes that edges are bidirectional and graph is connected

#include<iostream> 
#include<vector>
using namespace std;

vector<int> adjList[100005]; // max number of node is 10005

void dfs(int node,vector<bool> &vis) 
{
	cout<<node<<' ';
	vis[node] = 1; //vis[node] = true, mark node as visited
	for(int child: adjList[node])
	{
		//if child is not visited then only visit it
		if(!vis[child])
		{
			//now make dfs on child 
			dfs(child, vis);
		}
	}
}

int main() 
{

	int N,M; // N=number of nodes, M = number of edges
	cout<<"Enter number of Nodes ";
	cin>>N;
	cout<<"Enter number of Edges ";
	cin>>M;

  for(int i = 0; i<M; i++)
  {
  	int u,v;
  	//enter nodes which are directly connected
  	cin>>u>>v;

  	//make edge v->u
  	adjList[v].push_back(u);
  	//make edge u->v
  	adjList[u].push_back(v);
  }

  vector<bool> vis(N+1,false); //initially all nodes will be marked unvisited

  //perform dfs with picking node 1
  cout<<"\nPerforming dfs :";
  dfs(1,vis);
  return 0;

  /*
	----sample----

	Enter number of Nodes 4
	Enter number of Edges 5
	3 4
	4 2
	1 4
	3 1
	2 5

	Performing dfs :1 4 3 2 5

  */

}
