#include<bits/stdc++.h>
using namespace std;

void BFS(map<char,string> graph, int n){
    cout<<"BFS Traversal :";
    queue<char> q;
    unordered_map<char,bool> visited;
    char x;
    q.push(graph.begin()->first);
    while(!q.empty()){
        //push children of top element of queue and  then pop it
        x = q.front();
        q.pop();
        //printing the answer.
        cout<<x<<" ";
        
        for(int j=0;j<graph[x].size();j++){
            if(visited[graph[x][j]]!=true){
                q.push(graph[x][j]);
                visited[graph[x][j]]=true;
            }
        }
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter no of vertices: ";
    cin>>n;
    map<char,string> graph;
    char ch;
    string s;
    for(int i=0;i<n;i++){
        cin>>ch;
        cin>>s;
        graph[ch]=s;
    }
    BFS(graph,n);
    return 0;
}

// a fcb
// b gc
// c f
// d c
// e dcj
// f d
// g ce
// j dk
// k eg