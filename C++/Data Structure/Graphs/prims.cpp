#include <stdio.h>
#include <limits.h>
#include <iostream>
 
using namespace std;

#define V 7

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
    if (mstSet[v] == false && key[v] < min)
    min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V]) {
    cout<<"Edge   Weight\n";
    for (int i = 1; i < V; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
void primMST(int graph[V][V]) {
    int parent[V]; 
    int key[V]; 
    bool mstSet[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0; 
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++){
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)  
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, V, graph);
}
int main() {
    //0-A,1-B,2-C,3-D,4-E,5-F,6-G
    int graph[V][V] =  {{0,7,0,5,0,0,0}, 
                        {7,0,8,9,7,0,0},
                        {0,8,0,0,5,0,0}, 
                        {5,9,0,0,15,6,0}, 
                        {0,7,5,15,0,8,9},
                        {0,0,0,6,8,0,11},
                        {0,0,0,0,9,11,0}};
    primMST(graph);
    return 0;
}