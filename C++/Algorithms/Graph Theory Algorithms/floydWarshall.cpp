#include <iostream>
#include <list>
#include <climits>
#include <vector>
#include <unordered_map>
using namespace std;
#define N 10
class Graph{
    int V;
    int** m; 
    public:
        Graph(int V){
            this->V=V;
            m=new int*[V];
            //this
            for(int i=0;i<V;i++){
                m[i]=new int[V];
            }
            //this
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                    m[i][j]=INT_MAX;
                }
            }
            for(int i=0;i<V;i++) m[i][i]=0; //dist from node to itself is 0
        }
        void addEdge(int a,int b,int wt){
            m[a][b]=wt;
        }
        
        void floydW(){
            
            for(int k=0;k<V;k++){
                for(int i=0;i<V;i++){
                    for(int j=0;j<V;j++){
                        m[i][j]=min(m[i][j],m[i][k]+m[k][j]);
                    }
                }
            }

            //printing matrix
            for(int i=0;i<V;i++){
                for(int j=0;j<V;j++){
                        if(m[i][j]<100 && m[i][j]>-100){
                            cout<<"Minimum Distance from "<<i<<" to "<<j<<"-"<<m[i][j]<<", ";
                        }
                }
            }
            return;
        }
};

int main(){
    Graph g(5);
    g.addEdge(0,1,5);
    g.addEdge(0,2,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,1);
    g.addEdge(3,4,4);
    g.addEdge(2,4,3);
    g.floydW();
}