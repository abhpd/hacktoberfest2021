// cycle detection using DSU, we will keep on taking union of edges
// when the union of a new egde has the same leader, it means that there exists a cycle

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
vector<vector<int>> edges; // adj list for the graph
vector<int> parent(N);
vector<int> sz(N);

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find_set(int v){
    if(v==parent[v]){
        return v; // he is the leader of the set
    }
    return parent[v] = find_set(parent[v]); // recursion with "path compression"
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(sz[a] < sz[b]){
            swap(a, b); // so that a is always the largest set and we always move the smaller tree
        }
        parent[b] = a;
        sz[a] += sz[b]; 
    }
    else{
        return;
    }
}
int main(){
    for (int i = 0; i < N;i++){
        make_set(i);
    }
    // DSU is coded
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e;i++){
        int start, end;
        cin >> start >> end;
        edges.push_back({start, end}); // we just need to traverse the edges, we can use adj list also
    }
    bool cycle = false;
    for (auto i: edges)
    {
        int start = i[0];
        int end = i[1];
        int x = find_set(start);
        int y = find_set(end);
        // cout << x << " " << y<<"\n";
        if(x==y){
            cycle = true;
        }
        else{
            union_sets(start, end);
        }
    }
    if(cycle){
        cout << "cycle is detected";
    }
    else
        cout << "No";
    return 0;
}