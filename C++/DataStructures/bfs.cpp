#include <iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph
{
    map<T,list<T>>l;
    public:
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src)
    {
        map<T,int>visited;
        queue<T>q ;
        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            for(int nbr:l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};
        
int main() {
	// your code goes here
	Graph<char>ob;
	ob.addedge('A','B');
	ob.addedge('A','D');
	
	ob.addedge('A','C');
	ob.addedge('C','D');
	ob.addedge('D','E');
	ob.addedge('E','F');
	ob.bfs('A');
	return 0;
}
