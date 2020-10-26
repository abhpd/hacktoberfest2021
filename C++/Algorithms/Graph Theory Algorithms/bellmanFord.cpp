#include <iostream>
#include <list>
#include <climits>
#include <unordered_map>
using namespace std;

class Graph {
    int V;
    list<pair<pair<int, int>,int>> l;

    public:
        Graph(int V){
            this->V=V;
        }
        void addEdge(int x,int y,int wt){
            l.push_back({{x,y},wt});
        }

        void bellmanFord(int src){
            int* parent=new int[V];
            int* dist=new int[V];
            for(int i=0;i<V;i++){
                dist[i]=INT_MAX;
                parent[i]=i;
            }
            dist[src]=0;
            bool flag;
            for(int i=0;i<V-1;i++){
                flag=false;
                for(auto edge:l){
                    int a=edge.first.first;
                    int b=edge.first.second;
                    int d=edge.second;
                    if(dist[b]>dist[a]+d){
                        flag=true;
                        dist[b]=dist[a]+d;
                        parent[b]=a;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(flag){
                for(auto edge:l){
                    int a=edge.first.first;
                    int b=edge.first.second;
                    int d=edge.second;
                    if(dist[b]>dist[a]+d){
                        cout<<"Negative weighted cycle is present."<<endl;
                        return;
                    }
                }
            }
            for(int i=0;i<V;i++){
                cout<<parent[i]<<" ->"<<i<<"-"<<dist[i]<<",";
            }
    }       
};

int main(){
    Graph g(5);
    g.addEdge(0,1,6);
    g.addEdge(0,2,7);
    g.addEdge(1,2,8);
    g.addEdge(1,3,-4);
    g.addEdge(1,4,5);
    g.addEdge(2,3,9);
    g.addEdge(2,4,-3);
    g.addEdge(3,4,7);
    g.addEdge(3,0,2);
    g.addEdge(4,1,-2);
    g.bellmanFord(0);
}