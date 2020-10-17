//kaustubh0201

#include <bits/stdc++.h>
#define INF 99999
#define V 7

using namespace std;

void printGraph(int parent[V], int graph[][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

int min_ele(int distance[V], bool check[V])
{
    int temp = INF, index = 0;
    for (int i = 0; i < V; i++)
    {
        if (!check[i] && distance[i] < temp)
        {
            temp = distance[i];
            index = i;
        }
    }
    return index;
}

void prims(int graph[][V])
{

    bool check[V];
    int distance[V], parent[V];

    for (int i = 0; i < V; i++)
    {
        distance[i] = INF;
        check[i] = false;
    }

    distance[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < V; i++)
    {
        int u = min_ele(distance, check);

        check[u] = true;

        for (int j = 0; j < V; j++)
        {
            if (graph[u][j] == 0)
                continue;
            else
            {
                if (check[j] == false)
                {
                    if (graph[u][j] < distance[j])
                    {
                        distance[j] = graph[u][j];
                        parent[j] = u;
                    }
                }
            }
        }
    }

    printGraph(parent, graph);
}

int main(void)
{
    int graph[][V] = {
        {0, 28, 0, 0, 0, 10, 0},
        {28, 0, 16, 0, 0, 0, 14},
        {0, 16, 0, 12, 0, 0, 0},
        {0, 0, 12, 0, 22, 0, 18},
        {0, 0, 0, 22, 0, 25, 24},
        {10, 0, 0, 0, 25, 0, 0},
        {0, 14, 0, 18, 24, 0, 0}};

    prims(graph);

    return 0;
}