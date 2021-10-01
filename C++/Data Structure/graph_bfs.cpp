#include<bits/stdc++.h>
using namespace :: std;

class Graph{
    public:
        int v;
        vector<int> *adjList;

        Graph(int v){
            this->v=v;
            adjList = new vector<int> [v];
        }

        void addEdge(int a, int b, bool undir=true){
            adjList[a].push_back(b);
            if(undir){
                adjList[b].push_back(a);
            }
        }

        void bfs(int source){
            bool vis[v]={false};
            queue<int> q;
            q.push(source);
            vis[source]=true;
            while(!q.empty()){
                int p=q.front();
                cout<<p<<" ";
                q.pop();
                for(auto i: adjList[p]){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=true;
                    }
                }
            }
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
    g.bfs(1);

    return 0;
}
