#include <iostream>
#include <list>
#include <set>
#include <climits>
#include <unordered_map>
#include <string>
using namespace std;

template<class T>
class Graph{
    unordered_map<T,list<pair<T,int>>> l;
    public:
        void addEdge(T a,T b,int wt){
            l[a].push_back(make_pair(b,wt));
                l[b].push_back(make_pair(a,wt));
        }
        void dijkstra(T src){
            unordered_map<T,int> dist;
            bool *visited=new bool[10];
            for(auto node:l){
                dist[node.first]=INT_MAX;
                visited[node.first]=false;
            }
            dist[src]=0;
            set<pair<int,T>> s;
            s.insert(make_pair(0,src));
            while(!s.empty()){
                auto p=(*s.begin());
                T node=p.second;
                int nodeDist=p.first;
                s.erase(s.begin());
                visited[node]=true;

                //iterate over nbrs of node
                for(auto child:l[node]){
                    if(!visited[child.first]){
                            if(nodeDist+child.second<dist[child.first]){
                                T dest=child.first;
                                auto f=s.find(make_pair(dist[dest],dest));
                                if(f!=s.end()){
                                    s.erase(f);
                                }
                                dist[dest]=nodeDist+child.second;
                                s.insert(make_pair(dist[dest],dest));
                            }
                    }
                }

            }
            //print distance
            
            for(auto c:dist){
				if(c.second==INT_MAX) cout<<-1<<" ";
				if(c.second!=src)
                cout<<c.second<<" ";
            }
			cout<<endl;

        }

};
int main(){
    int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n;m;
		Graph<int> g();
		for(int i=0;i<m;i++){
			int x,y,z;
			cin>>x>>y>>z;
			g.addEdge(x-1,y-1,z);
		}
		int src;
		cin>>src;
		g.dijkstra(src);
	}

}