#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* Find the shortest path for an unweighted, undirected graph
 * We will use BFS to traverse the graph.
 * Shortest Path using only BFS will work if there are no cycles and if the graph is unweighted or if all edges have same weight
 */

void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); // do this because undirected graph
} // createAndAddEdge(vector <int> List[], int u, int v)

void ShortestPath(vector <int> adjList[], vector <bool> visitedVertex, int source){
  int v;
  queue <int> Q; //set up Queue for BFS
  vector <int> ShortestPaths(visitedVertex.size());
  ShortestPaths.at(source) = 0;
  for (int i = 0; i < ShortestPaths.size(); i++)
    if (i != source)
      ShortestPaths.at(i) = 1000000; // All other distances have been set to +infinity
  Q.push(source);

  while (!Q.empty()){
    v = Q.front();
    visitedVertex.at(v) = true;
    Q.pop();
    for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // Visit all children
      if (!visitedVertex.at(*it)){
        Q.push(*it); // Push unvisted vertex onto the queue

        if (ShortestPaths.at(v) + 1 < ShortestPaths.at(*it))
          ShortestPaths.at(*it) = ShortestPaths.at(v) + 1; // Get new distance
        visitedVertex.at(*it) = true;
      } // if not visited
  } // While Queue is not empty
  cout << "Shortest paths from " << source << ": ";
  for (int i = 0; i < ShortestPaths.size(); i++)
    cout << ShortestPaths.at(i) << " ";
  cout << endl;
} // ShortestPath

// Driver function
int main (void){
  const int numVertices = 6; // 6 vertices (0,1,2,3,4,5)
  int source = 0;
  vector<int> adjList[numVertices]; // Create an array of vectors
  vector <bool> visitedVertex(numVertices, false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 1, 2);
  createAndAddEdge(adjList, 1, 5);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 5, 5);
  ShortestPath(adjList, visitedVertex, source); // Find the shortest path from the source to all other vertices.
  //Shortest Path from 0: 0 1 2 3 3 2
} // main()
