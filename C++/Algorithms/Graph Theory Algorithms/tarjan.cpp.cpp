# include <bits/stdc++.h>
using namespace std ; 
typedef vector<int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define MAX 100005

int n,m,foundat=1;
vvi graph,scc;
vi disc,low; // init disc to -1
bool onstack[MAX]; //init to 0 

void tarjan(int u){
    static stack<int> st;

    disc[u]=low[u]=foundat++;
    st.push(u);
    onstack[u]=true;
    for(auto i:graph[u]){
        if(disc[i]==-1){
            tarjan(i);
            low[u]=min(low[u],low[i]);
        }
        else if(onstack[i])
            low[u]=min(low[u],disc[i]);
    }
    if(disc[u]==low[u]){
        vi scctem;
        while(1){
            int v=st.top();
            st.pop();onstack[v]=false;
            scctem.pb(v);
            if(u==v)
                break;
        }
        scc.pb(scctem);
    }
}
int main()
{
	int m ; 
	cin >> n >>  m ; 
	vector<int> ans(n+1) ; 
    
    graph.clear();graph.resize(n+1);
    disc.clear();disc.resize(n+1,-1);
    low.clear();low.resize(n+1);
	for(int i = 0 ; i < m ; ++i) {
		int a, b ; 
		cin >> a>> b ; 
		graph[a].push_back(b) ; 
	}
    //
    // input graph here
    for(int i = 0 ; i < n ; ++i)
        if(disc[i+1]==-1)
            tarjan(i+1);
    cout << scc.size() << endl ; 
    for(vi a : scc) {
	for(int x : a) {
	    cout << x << " " ; 
	}
	cout << "\n" ; 
    }

}