
#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std;

/* Program that uses Prims Algorithm to generate a Minimum Spanning Tree
 * and hence find the minimum cost to connect all the vertices
 */
 
typedef pair<int, int> Pair; // First = Weight & Second = Vertex
const int numVertices = 4; // 4 vertices (0,1,2,3)
vector <bool> visitedVertex(numVertices, false);

void createAndAddEdge(vector <Pair> adjList[], int u, int weight, int v){
  adjList[u].push_back(make_pair(weight, v));
  adjList[v].push_back(make_pair(weight, u)); // do this because undirected graph
} // createAndAddEdge(vector <int> List[], int u, int v, int weight)

void PrimsAlgorithm(vector <Pair> adjList[], int source){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; // Set up priority queue
  Pair info;
  int minCost = 0;
  PQ.push(make_pair(0, source)); // Source has weight 0;
  while (!PQ.empty()){
    info = PQ.top(); // Use to get minimum weight
    source = info.second; // get the vertex
    PQ.pop(); // Pop before checking for cycles
    if (visitedVertex.at(source)) // Check for cycle
      continue; // Already accounted for it, move on
    visitedVertex.at(source) = true; // Else, mark the vertex so that we won't have to visit it again
    cout << "Mark vertex " << info.second << " and add weight " << info.first << endl;
    minCost += info.first; // Add to minCost
    for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++) // Visit all children
      if (!visitedVertex.at(it->second)) // If vertex hasn't been visited already
        PQ.push(make_pair(it->first, it->second)); // Push vertex and weight onto Priority Queue
  } // While Priority Queue is not empty
   cout << "Minimum cost to connect all vertices : " << minCost << endl;
} // PrimsAlgorithm

int main (void){
  // Idea is to implement the adjacency list as an array of vectors:
  int source = 0;
  vector<Pair> adjList[numVertices]; // Create an array of vectors that contain pairs of adjacent vertex and weight
  createAndAddEdge(adjList, 0, 1, 1);
  createAndAddEdge(adjList, 0, 2, 3);
  createAndAddEdge(adjList, 1, 4, 2);
  createAndAddEdge(adjList, 1, 3, 3);
  createAndAddEdge(adjList, 2, 5, 3);
  PrimsAlgorithm(adjList, source); // Generate MST and find minCost
  // Minimum Cost should be 7;

} // main()
