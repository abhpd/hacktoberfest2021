
#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std;

/* Uses Dijkstra's Algorithm to find the Shortest Path from an arbitrary vertex to all other vertices
 * Since the following version of Dijkstra's is implemented using a min-priority queue,
 * the time complexity of the algorithm is O(V + ElogV).
 */

typedef pair<int, int> Pair; // First = Weight & Second = Vertex
const int numVertices = 6; // 6 vertices (0,1,2,3,4,5)
vector <bool> visitedVertex(numVertices, false);
int ShortestPath[numVertices]; // Have an array to store the shortest path

void createAndAddEdge(vector <Pair> adjList[], int u, int weight, int v){
  adjList[u].push_back(make_pair(weight, v));
} // createAndAddEdge(vector <int> List[], int u, int v, int weight)

void DijkstrasAlgorithm(vector <Pair> adjList[], int source){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; // Set up priority queue
  Pair info;
  int weight;
  ShortestPath[source] = 0; // Set source distance to zero

  for (int i = 0; i < numVertices; i++)
    if (i != source)
      ShortestPath[i] = 100000; // Initialize everything else to +infinity

  PQ.push(make_pair(0, source)); // Source has weight 0;

  while (!PQ.empty()){
    info = PQ.top(); // Use to get minimum weight
    PQ.pop(); // Pop before checking for cycles
    source = info.second; // get the vertex
    weight = info.first; // current distance

    if (visitedVertex.at(source)) // Check for cycle
      continue; // Already accounted for it, move on

    visitedVertex.at(source) = true; // Else, mark the vertex so that we won't have to visit it again

    for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
       if ((weight + (it->first)) < ShortestPath[it->second]){ // Check if we can do better
         ShortestPath[it->second] = weight + (it->first); // Update new distance
         PQ.push(make_pair(ShortestPath[it->second], it->second)); // Push vertex and weight onto Priority Queue
       } // Update distance
  } // While Priority Queue is not empty
} // DijkstrasAlgorithm

// Driver function
int main (void){

  int source = 0;
  vector<Pair> adjList[numVertices]; // Create an array of vectors that contain pairs of adjacent vertex and weight
  createAndAddEdge(adjList, 0, 5, 1);
  createAndAddEdge(adjList, 0, 10, 3);
  createAndAddEdge(adjList, 1, 2, 2);
  createAndAddEdge(adjList, 1, 10, 5);
  createAndAddEdge(adjList, 1, 5, 4);
  createAndAddEdge(adjList, 2, 1, 3);
  createAndAddEdge(adjList, 2, 5, 4);
  createAndAddEdge(adjList, 2, 3, 0);
  createAndAddEdge(adjList, 4, 2, 5);
  DijkstrasAlgorithm(adjList, source);

  cout << "Shortest path from source vertex " << source << ": ";
  for (int i = 0; i < numVertices; i++)
    cout << ShortestPath[i] << " ";
  cout << endl;

} // main()
