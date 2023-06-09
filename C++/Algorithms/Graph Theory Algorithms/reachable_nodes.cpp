// QUESTION: https://cses.fi/problemset/task/2138/ 

// A directed acyclic graph consists of n nodes and m edges. The nodes are numbered 1,2,…,n.
// Calculate for each node the number of nodes you can reach from that node (including the node itself).

// Input
// The first input line has two integers n and m: the number of nodes and edges.
// Then there are m lines describing the edges. Each line has two distinct integers a and b: there is an edge from node a to node b.

// Output
// Print n integers: for each node the number of reachable nodes.

#include <bits/stdc++.h> 
using namespace std;
#define ll long long
const ll N = 5e4 + 4;

int n , m;
vector<int> g[N]; 
vector<int> indegree(N , 0);

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    cin >> n >> m;
 
    for(int i = 0; i < m; ++i)
    {
        int x , y;
        cin >> x >> y;
        g[x].push_back(y);
        ++indegree[y];
    }
    
    // Topological  Sort
    queue<int> q;
 
    for(int i = 1; i <= n; ++i)
        if(indegree[i] == 0)
            q.push(i);
    
    vector<int> order;
 
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
 
        order.push_back(top);
 
        for(auto x : g[top])
        {
            --indegree[x];
            if(indegree[x] == 0)
                q.push(x);
        }
    }
    
    // For the Reach
 
    bitset<N> reach[N];
 
    for(int i = n - 1; ~i; --i)
    {
        reach[order[i]] = reach[order[i]].set(order[i]);
        for(auto x : g[order[i]])
            reach[order[i]] |= reach[x];
    }
 
    for(int i = 1; i <= n; ++i)
        cout << reach[i].count() << ' ';    
}

// Logic : 
// First Find the order of the nodes using Topological Sort 
// Then  Start from the last node in the order and set the bits of 
// child.
// By using bitset every node will be added only once and we will do 
// bitwise or operation between the parent and it's children to find
// which all nodes are reachable. 
// If some nodes are reachable from it's  children then it is also
// reachable from their parent.
