#include<bits/stdc++.h> 
using namespace std; 
   
// graph class
class Graph 
{ 
int V;    // No. of vertices 
list<int> *adjList;    // adjacency lists 
public: 
Graph(int V)  //graph Constructor 
    {
this->V = V; 
adjList = new list<int>[V]; 
    }
void addEdge(int v, int w) // add an edge to graph 
    {
adjList[v].push_back(w); // Add w to v’s list. 
    }
void DFS();  // DFS traversal
   
    // utility function called by DFS 
void DFSUtil(int s, vector<bool> &visited); 
}; 
   
//traverses all not visited vertices reachable from start node s
void Graph::DFSUtil(int s, vector<bool> &visited) 
{ 
    // stack for DFS 
stack<int> dfsstack; 
   // current source node inside stack 
dfsstack.push(s); 
   
while (!dfsstack.empty()) 
    { 
        // Pop a vertex  
        s = dfsstack.top(); 
       dfsstack.pop(); 
   
        // display the item or node only if its not visited 
 if (!visited[s]) 
        { 
cout << s << " "; 
visited[s] = true; 
        } 
   
        // explore all adjacent vertices of popped vertex. 
        //Push the vertex to the stack if still not visited
for (auto int i = adjList[s].begin(); i != adjList[s].end(); ++i) 
if (!visited[*i]) 
dfsstack.push(*i); 
    } 
}
// DFS 
void Graph::DFS() 
{ 
    // initially all vertices are not visited 
vector<bool> visited(V, false); 
   
for (int i = 0; i < V; i++) 
if (!visited[i]) 
DFSUtil(i, visited); 
} 
   
//main program
int main() 
{ 
    Graph gidfs(5);  //create graph 
gidfs.addEdge(0, 1); 
gidfs.addEdge(0, 2); 
gidfs.addEdge(0, 3);
gidfs.addEdge(1, 2); 
gidfs.addEdge(2, 4);
gidfs.addEdge(3, 3); 
gidfs.addEdge(4, 4);
  
cout << "Output of Iterative Depth-first traversal:\n"; 
gidfs.DFS(); 
   
return 0; 
}
