// Topological Sorting (Kahn's Algorithm)

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int totalVertices;
    vector<int> *adj;
public:
    Graph(int v);
    void addEdge(int src, int dest);
    void topologicalSort();
};

Graph :: Graph(int v) {
    totalVertices = v;
    adj = new vector<int> [totalVertices];
}

void Graph :: addEdge(int src, int dest) {
    adj[src].emplace_back(dest);
}

void Graph :: topologicalSort() {

    vector<int> indegree(totalVertices, 0);

    for (int v = 0; v < totalVertices; ++v) {
        vector<int> :: iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            ++indegree[*i];
    }

    queue<int> q;
    for (int v = 0; v < totalVertices; ++v)
        if (indegree[v] == 0)
            q.push(v);

    vector<int> sortedList;

    while (!q.empty()) {

        int currVertex = q.front();
        q.pop();
        sortedList.push_back(currVertex);

        vector<int> :: iterator i;
        for (i = adj[currVertex].begin(); i != adj[currVertex].end(); ++i)
            if (--indegree[*i] == 0)
                q.push(*i);
    }

    if (sortedList.size() != totalVertices)
        cout << "Graph is not a Directed Acyclic Graph !\n";
    else {
        for (int i = 0; i < totalVertices; ++i)
            cout << sortedList[i] << ' ';
    }
}

int main() {

    int vertices;
    cout << "Enter the total number of vertices : ";
    cin >> vertices;

    Graph g(vertices);

    int E;
    cout << "Enter the total number of edges : ";
    cin >> E;

    cout << "Enter " << E << " edges : ";
    int src, dest;
    for (int i = 0; i < E; ++i) {
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    cout << "Topological Ordering : ";
    g.topologicalSort();

    return 0;
}