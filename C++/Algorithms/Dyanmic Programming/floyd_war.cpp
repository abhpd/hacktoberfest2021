// kaustubh0201

#include <bits/stdc++.h>
#define INF 99999
#define V 4

using namespace std;

void printGraph(int graph[][V])
{
    cout << "The shortest path of each element from each other is as follows: " << endl;
    cout << "Note that there is no loop for each element. " << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << "INF"
                     << "    ";
            }
            else
            {
                cout << graph[i][j] << "    ";
            }
        }

        cout << endl;
    }
}

void floyd_warshall(int graph[][V])
{
    for (int k = 0; k < V; k++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int i = 0; i < V; i++)
            {
                if (graph[j][k] + graph[k][i] < graph[j][i])
                {
                    graph[j][i] = graph[j][k] + graph[k][i];
                }
            }
        }
    }

    printGraph(graph);
}

int main(void)
{
    int graph[][V] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    floyd_warshall(graph);

    return 0;
}