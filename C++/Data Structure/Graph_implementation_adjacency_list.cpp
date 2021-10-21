/* Adjacency List representation in C++*/

#include <bits/stdc++.h>

using namespace std;

/* Add edge to the graph*/
void Add_Edge(vector<int> adj[], int s, int d) 
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

/* Print the graph */
void Print_Graph(vector<int> adj[], int V) 
{
    for (int d = 0; d < V; ++d) 
    {
        cout << "\n Vertex "<< d << " ";
        for (auto x : adj[d])
        cout << "-> " << x;
        printf("\n");
    }
}


int main() 
{
    int V = 5;

    /* Create a graph */
    vector<int> adj[V];

    /* Adding edges to the graph */
    Add_Edge(adj, 0, 1);
    Add_Edge(adj, 1, 2);
    Add_Edge(adj, 0, 2);
    Add_Edge(adj, 0, 3);
    Add_Edge(adj, 2, 3);
    Add_Edge(adj, 1, 4);
    cout<<"Adjacency List:"<<'\n';
    Print_Graph(adj, V);
}


