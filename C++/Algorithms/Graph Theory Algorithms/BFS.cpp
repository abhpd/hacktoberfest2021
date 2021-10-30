#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;

public:
	Graph(int V){
		this->V = V;
		adj = new list<int>[V];
	}

	void addEdge(int s,int d){
		adj[s].push_back(d);
	}

	void BFS(int start){
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i] = false;

		int current;
		list<int> queue;
		queue.push_back(start);
		visited[start] = true;
		cout<<start<<endl;

		list<int>::iterator i;
		while(!queue.empty()){
			current = queue.front();
			queue.pop_front();

			for(i=adj[current].begin();i!=adj[current].end();i++){
				if(visited[*i]==false){
					visited[*i] = true;
					cout<<*i<<endl;
					queue.push_back(*i);
				}
			}


		}

	}
};
int main(){

	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
	return 0;
}