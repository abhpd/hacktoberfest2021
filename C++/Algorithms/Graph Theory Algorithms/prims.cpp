#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
	int V;
	vector<pair<int,int>> *l;
public:
	Graph(int n)
	{
		V=n;
		l = new vector<pair<int,int> >[n];
	}

	void addEdge(int x,int y,int w)
	{
		l[x].push_back({y,w});
		l[y].push_back({x,w});
	}

	int prims_mst()
	{
		priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > Q;
		bool *visited = new bool[V]{0};
		int ans=0;

		Q.push({0,0}); //weight, node because greater function sorts in ascending order using the first value

		while(!Q.empty())
		{
			//take the edge with minimum weight
			auto best = Q.top();
			Q.pop();

			int to = best.second;
			int weight = best.first;

			if(visited[to])
			{
				//discard the edge and continue
				continue;
			}

			//otherwise take the current edge and add its weight to sum;
			ans += weight; 
			visited[to] = 1;

			//add the new edges in the queue
			for(auto i:l[to])
			{
				if(visited[i.first]==0)
				{
					Q.push({i.second,i.first});
				}
			}
		}
		return ans;
	}
};

int main()
{
	Graph g(4);
	g.addEdge(1,2,1);
	g.addEdge(1,3,2);
	g.addEdge(2,3,2);
	g.addEdge(2,4,2);
	g.addEdge(3,4,3);
	g.addEdge(1,4,2);
	cout<<g.prims_mst()<<endl;
}