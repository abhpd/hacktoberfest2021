#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <cassert>
#include <sstream>
#include <unordered_set>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
	Graph class with method floyd marshall algorithm
*/
class APSP {
  int totalVertices;
  int totalEdges;
  int adjMat[1000][1000];
  int minDist = INT_MAX;
 public:
  APSP() {
    cin >> totalVertices;
    cin >> totalEdges;
    cout << "Graph input of " << totalVertices 
         << " vertices and edges : " << totalEdges << std::endl; 
    for(int i = 0; i < totalVertices; i++) {
      for(int j = 0; j < totalVertices; j++) {
        if(i == j) adjMat[i][j] = 0;
        else adjMat[i][j] = INT_MAX;
      }
    }
  }
  void takeInput();
  int floydWarshall();
};

/*
	Take input from a file from commandline argument set in main code
*/
void APSP::takeInput() {
  auto start = high_resolution_clock::now();
  std::string line;  
  while(getline(cin,line,'\n')) {
    istringstream iss(line);
    int v1 = 0, v2 = 0, w = 0;
    iss >> v1;
    iss >> v2;
    iss >> w;
    adjMat[v1-1][v2-1] = w;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << "Time taken for input : " << duration.count() << "ms\n";
}
/*	
	the main Floyd Warshall algorithm 
*/
int APSP::floydWarshall() {
  int dist[1000][1000];
  for(int i = 0; i < totalVertices; i++) {
    for(int j = 0; j < totalVertices; j++) {
      if(i == j) {
        dist[i][j] = 0;
      } else {
        dist[i][j] = adjMat[i][j];
      } 
    } 
  }
  for(int k = 1; k < totalVertices; k++) {
    for(int i = 0; i < totalVertices; i++) {
      for(int j = 0; j < totalVertices; j++) {
        if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && (dist[i][k] + dist[k][j] < dist[i][j])) {
          dist[i][j] = dist[i][k] + dist[k][j];
          minDist = min(minDist,dist[i][j]);
        }
      }
    }
  }
  for(int i = 0; i < totalVertices; i++) {
    if(dist[i][i] < 0) {
      cout <<"Ignore : ";
      return INT_MAX;
    }
  }
  return minDist;
}
/*
	Main driver code
*/
int main(int argc, char * argv[]) {
  assert(argc > 1);
  freopen(argv[1],"r",stdin);
  APSP graph;
  graph.takeInput();
  cout << graph.floydWarshall();
}
