#include<bits/stdc++.h>
using namespace :: std;

class Graph{
    public:
        int v;
        vector<int> * adjList;

        Graph(int v){
            this->v=v;
            adjList = new vector<int> [v];
        }

        void addEdge(int u, int v, bool undir=true){
            adjList[u].push_back(v);
            if(undir){
                adjList[v].push_back(u);
            }
        }

        void dfsHelper(int node, bool * vis){
            cout<<node<<" ";
            vis[node]=true;
            for(auto i:adjList[node]){
                if(!vis[i]){
                    dfsHelper(i, vis);
                }
            }
        }

        void dfs(int source){
            bool * vis = new bool [this->v]{false};
            dfsHelper(source, vis);
        }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.dfs(1);

    return 0;
}
