#include <cstring>
#include <iostream>
using namespace std;
#define V 5
int minKey(int key[],bool mstSet[])
{
    int min = INT_MAX, min_index;
    for(int v =0;v<V;v++)
    {
        if(mstSet[v]== false && key[v] < min)
            min = key[v] , min_index = v;
    }
    return min_index;
}
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for(int i = 1; i<V; i++)
        cout << parent[i] <<" - "<< i <<" \t" << graph[i][parent[i]] << "\n";
}
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for(int i =0; i< V; i++)
        key[i]= INT_MAX, mstSet[i]= false;
    key[0]=0;
    parent[0] = -1;
    for(int count =0; count<V-1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u]= true;
        for(int v =0; v<V; v++)
        {
            if(graph[u][v] && mstSet[v]== false && graph[u][v] < key[v])
                parent[v]=u , key[v] = graph[u][v];

        }
    }
    printMST(parent, graph);    
}
int main()
{
    int graph[V][V] = {{0, 9, 75, 0, 0},
                    {9, 0, 95, 19, 42},
                    {75, 95, 0, 51, 66},
                    {0, 19, 51, 0, 31},
                    {0, 42, 66, 31, 0}};
    primMST(graph);
    return 0;                
}