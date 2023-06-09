#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *graph;

public:
    Graph(int V)
    {
        this->V = V;
        graph = new vector<int>[V];
    }

    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
    }

    void printStack(stack<int> &s, int source, vector<int> &inStack)
    {
        cout << "Strongly connected components are : ";
        while (s.top() != source)
        {
            cout << s.top() << "  ";
            inStack[s.top()] == -1;
            s.pop();
        }
        cout << s.top() << "  " << endl;
        inStack[s.top()] == -1;
        s.pop();
    }

    void Tarjans_Algorithm(int source, vector<int> &discovery, vector<int> &low, stack<int> &s, vector<int> &inStack)
    {
        static int time = 0;

        discovery[source] = low[source] = ++time;
        s.push(source);
        inStack[source] = 1;

        for (auto v : graph[source])
        {
            if (discovery[v] == -1)
            {
                Tarjans_Algorithm(v, discovery, low, s, inStack);
                // Important STEP
                low[source] = min(low[source], low[v]);
            }
            else if (inStack[v] == 1)
            {
                // Important STEP
                low[source] = min(low[source], discovery[v]);
            }
        }
        // Lastly printing the stack to get one component.
        if (discovery[source] == low[source])
            printStack(s, source, inStack);
    }
};

int main()
{
    int V = 11;
    Graph g(V);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,0);
    g.addEdge(2,6);
    g.addEdge(3,2);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(5,8);
    g.addEdge(5,9);
    g.addEdge(6,4);
    g.addEdge(7,9);
    g.addEdge(8,9);
    g.addEdge(9,8);

    vector<int> discovery(V, -1);
    vector<int> low(V, -1);
    // Stack to print the vertices of one component.
    stack<int> s;
    // Vector to store the vertices present in the stack.
    vector<int> inStack(V, -1);

    for (int i = 0; i < V; i++)
    {
        // To make sure that no vertex is left un-discoveryed even the graph is undirected.
        if (discovery[i] == -1)
            g.Tarjans_Algorithm(i, discovery, low, s, inStack);
    }

    return 0;
}