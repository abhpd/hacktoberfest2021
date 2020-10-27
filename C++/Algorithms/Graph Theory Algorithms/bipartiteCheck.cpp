#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V];
        }
        void addEdge(int a,int b){
            l[a].push_back(b);
            l[b].push_back(a);
        }

        bool bigraph(int node,int color[]){
            queue<int> q;
            q.push(node);
            color[node]=1;
            while(!q.empty()){
                int ele=q.front();
                q.pop();
                for(auto nbr:l[ele]){
                    if(color[nbr]==color[ele]){
                        return false;
                    }
                    if(color[nbr]==-1){
                        color[nbr]=1-color[ele];
                        q.push(nbr);
                    }
                }
            }
            return true;
        }

        bool BipartiteCheck(){
            int* color=new int[V];
            for(int i=0;i<V;i++){
                color[i]=-1;
            }
            for(int i=0;i<V;i++){
                if(color[i]==-1){
                    if(!bigraph(i,color)){
                        return false;
                    }
                }
            }
            return true;
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,0);
    if(g.BipartiteCheck()){
        cout<<"Bipartite check Successful"<<endl;
    }else{
        cout<<"Graph is not a Bipartite."<<endl;
    }
}