#include <iostream>
#include <list>
#include <stack>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    list<int>*lr;

    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V];
            lr=new list<int>[V];
        }
        void addEdge(int a,int b){
            l[a].push_back(b);
            lr[b].push_back(a);
        }
        void dfs(int node, bool visited[],stack<int>& s){
            visited[node]=true;
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    dfs(nbr,visited,s);
                }
            }
            s.push(node);
        }
        void dfs_reverse(int node,bool visited[]){
            visited[node]=true;
            cout<<node<<" ";
            for(auto nbr:lr[node]){
                if(!visited[nbr]){
                    dfs_reverse(nbr,visited);
                }
            }
        }
        void kosaraju(){
            bool* visited=new bool[V];
            for(int i=0;i<V;i++){
                visited[i]=false;
            }
            stack<int> s;
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    dfs(i,visited,s);
                }
            }
            //use lr for reversed graph
            for(int i=0;i<V;i++){
                visited[i]=false;
            }
            while(!s.empty()){
                int t=s.top();
                if(visited[t]==false){
                    cout<<"Elements in a component are: ";
                    dfs_reverse(t,visited);
                    cout<<endl;
                }
                s.pop();
            }
        }
};
int main(){
    Graph g(10);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(2,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(6,4);
    g.addEdge(7,6);
    g.addEdge(7,8);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.kosaraju();
}