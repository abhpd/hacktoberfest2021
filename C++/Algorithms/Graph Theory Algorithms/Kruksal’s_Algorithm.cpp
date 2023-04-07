//Kruksal’s Algorithm by blankita21

#include <bits/stdc++.h>
using namespace std;

//structure to save the needed info

struct node
{
    int u;
    int v;
    int wt;

    node(int a, int b, int c)
    {
        u = a;
        v = b;
        wt = c;
    }
};

// comparator function

bool comp(node a, node b)
{
    return (a.wt < b.wt);
}

// function to find the parent of a given node

int findpar(int u, vector<int> &parent)
{
    if (u == parent[u])
    {
        return u;
    }

    return (findpar(parent[u], parent));
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int a = findpar(u, parent);
    int b = findpar(v, parent);

    if (rank[a] < rank[b])
    {
        parent[a] = b;
    }

    else if (rank[a] > rank[b])
    {
        parent[b] = a;
    }

    else
    {
        parent[a] = b;
        rank[b]++;
    }
}

int main()
{
    int vv, e; // declaring vertex and edges
    cin >> vv >> e;

    vector<node> edges;

    for (int i = 0; i < e; i++)
    {
        int wt, u, v;
        cin >> wt >> u >> v;
        edges.push_back(node(u, v, wt));
    }

    //sorting the graph using the comparator function

    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(vv);
    vector<int> rank(vv, 0);

    for (int i = 0; i < vv; i++)
    {
        parent[i] = i;
    }

    vector<pair<int, int>> mst;
    int cost = 0;

    for (auto it : edges)
    {
        if (findpar(it.u, parent) != findpar(it.v, parent))
        {
            mst.push_back({it.u, it.v});
            cost += it.wt;
            unionn(it.u, it.v, parent, rank);
        }
    }

    // printing the final result

    cout << cost << endl;

    for (auto it : mst)
    {
        cout << it.first << " --> " << it.second << endl;
    }

    return 0;
}