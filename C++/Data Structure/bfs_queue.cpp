#include<iostream>
using namespace std;
int adj[20][20],v[20],queue[20],n,front=0,rear=0;
void BFS(int i){
    v[i]=3;
    for(int j=1;j<=n;j++){
        if(adj[i][j]==1 && v[j]==1){
            queue[++rear]=j;
            v[j]=2; 
        }
    }
    if(front<=rear)
    BFS(queue[front++]);
}
int main(){
    int i,j,start;
    cout<<"Enter the total nodes: "; 
    cin>>n;
    cout<<"give adjacency matrix: "<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>adj[i][j];
        }
    }
    for(i=1;i<=n;i++){
        v[i]=1;
        queue[i]=0;
    }
    cout<<"give starting point for bfs: ";
    cin>>start;
    queue[++rear]=start;
    front=1; 
    v[start]=2;
    BFS(start);
    for(i=1;i<=n;i++){
        if(queue[i]!='0')
        cout<<queue[i];  
    }
    return 0;
}

