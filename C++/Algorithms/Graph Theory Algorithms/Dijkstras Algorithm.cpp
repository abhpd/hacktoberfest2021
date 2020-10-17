#include<iostream>
#include<unordered_map>
#include<set>
#include<map>
#include<climits>
#include<list>
using namespace std;

// class graph 
class graph{

   unordered_map<long int,list<pair<long int,long int>>> m;
   
   public:
   
      //Adding edge in graph
     void addedge(long int x,long int y,int r){
		    m[x].push_back(make_pair(y,r));
		    m[y].push_back(make_pair(x,r));
	    }
      
	   void dikshitras(long int src){
		  map<long int,long int> mp;
		  set<pair<long int,long int>> s;
		  for(auto i:m){
			 mp[i.first]=INT_MAX;
		  }
		  mp[src]=0;
		  s.insert(make_pair(0,src));
		  while(!s.empty()){
         auto node=*(s.begin());
		     long int t=node.second;
		     long int nodedis=node.first;
		     s.erase(s.begin());
		     for(auto nbrs:m[node.second]){
			    if(mp[nbrs.first] > nbrs.second+nodedis){
				      auto k=s.find(make_pair(mp[nbrs.first],nbrs.first));
				      if(k!=s.end()){
					       s.erase(k);
				      }
				      mp[nbrs.first]=nbrs.second+nodedis;
				      s.insert(make_pair(mp[nbrs.first],nbrs.first));
			   }
		   }
		  }
      
      // printing the distance of each vertex from source 
		  for(auto i:mp){
			  if(i.first != src)
			  if(i.second==INT_MAX)
			  cout<<-1<<" ";
			  else
			  cout<<i.second<<" ";
		  }
		  cout<<endl;
	  }
};

int main() {
  //test cases
	long int t; cin>>t;
  
	while(t--){
  
      //n vertices , m edges
      long int n,m;  cin>>n>>m;
      
	     graph g;
	    for(long int i=0;i<m;i++){
           long int x,y,r; cin>>x>>y>>r;
			     g.addedge(x,y,r);
	    }
      //s source vertex 
      long int s; cin>>s;
      
		  g.dikshitras(s);
	}
	return 0;
}
