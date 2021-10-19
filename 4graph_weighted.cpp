// coding blocks video 4
/*
Graph Adjacency list
Weighted Graph
we are using hashMap
*/

#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>
using namespace std;

class Graph
{
    // adj list
    // unordered_map<key, value>
    unordered_map<string, list<pair<string, int> > > l;

    public:
    void addEdge(string x, string y, bool bidirec, int weight)
    {
        l[x].push_back(make_pair(y, weight));
        if(bidirec)
        {
            l[y].push_back(make_pair(x, weight));
        }
    }

    void printAdj()
    {
        for(auto p: l)
        {
            string city = p.first;
            list<pair<string, int>> nbrs = p.second;
            cout<< city <<"->";
            for(auto n1 : nbrs)
            {
                string dest = n1.first;
                int dist = n1.second;
                cout<<"("<<dest<<" "<<dist<<")";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph g;
    // (from, to, is bidirectional, weight
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printAdj();
    return 0;
}