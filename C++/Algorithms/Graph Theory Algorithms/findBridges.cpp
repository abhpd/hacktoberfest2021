#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairs;
void dfsBridges(vector<vector<int>> &graph,int u,vector<bool> &vis,vector<int> &parent,vector<int> &disc,vector<int> &low,set<pairs> &bridges){

    static int time=0;
    vis[u]=true;

    disc[u]=low[u]=++time;

    for(int i=0;i<graph[u].size();i++){
        if(graph[u][i]==1){
            int v=i;
            if(!vis[v]){
            parent[v]=u;
            dfsBridges(graph,v,vis,parent,disc,low,bridges);

            low[u]=min(low[u],low[v]);

                if(low[v] > disc[u]){
                // cout<<u<<" "<<v<<endl;
                    bridges.insert({u,v});
                }
            }
            else if(v!=parent[u])
                low[u]=min(low[u],disc[v]);
        }

    }

}
void findBridges(vector<vector<int>> &graph){

    int ver=graph.size();

    vector<int> parent(ver,-1),disc(ver,0),low(ver,0);
    vector<bool> vis(ver+1,false);

    set<pairs> ans;

    for(int i=0;i<ver;i++)
        if(!vis[i])
            dfsBridges(graph,i,vis,parent,disc,low,ans);

    if(ans.size()){
        cout<<"The Following Edges are Bridges in the graph"<<endl;
        for(auto i : ans)
            cout<<i.first<<" "<<i.second<<endl;
    }
    else{
        cout<<"No Bridges in this graph"<<endl;
    }
}
int main(){

    int vertices;
    cin>>vertices;

    vector<vector<int>> graph(vertices,vector<int>(vertices,0));
    
    for(int i=0;i<vertices;i++)
        for(int j=0;j<vertices;j++)
            cin>>graph[i][j];

    findBridges(graph);
}