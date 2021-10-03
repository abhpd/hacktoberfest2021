#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tc ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
#define mp make_pair 
#define pq priority_queue
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define bp ll kkk; cin >>kkk;
#define dbgArr(a,n) cout<<"Array "<<#a<<endl; for(ll i=0 ; i<n ; i++) cout<<a[i]<<" "; cout<<endl;
#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define forn1(i,n) for(ll i=1 ; i<=n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }
#define arr1(a,n) for(ll i=1;i<=n;i++){ cin>>a[i]; }
#define file freopen("inp.in","r",stdin); freopen("outp.out","w",stdout)
#define print cout<<"Case #"<<number<<": "
#define all(x) x.begin(), x.end()
#define trav(x, a) for(auto &x: a)
ll power(ll x, ll b) {ll p = 1;while (b > 0) {if(b&1) {p = p * x; p %= mod;} b >>= 1; x *= x; x %= mod;} return p % mod;}

using namespace std;

class DSU
{
    int *rank , *parent ;
    public :
        DSU(int n)
        {
            rank=new int[n];
            parent=new int[n];
            forn(i,n)
            {
                parent[i]=-1 ; rank[i]=1 ;
            }
        }
        int find(int x)
        {
            if(parent[x]==-1) return -1 ;
            else return parent[x]=find(parent[x]);
        }
        void unite(int x , int y)
        {
            int s1=find(x);
            int s2=find(y);
            if(s1!=s2)
            {
                if(rank[s1]<rank[s2])
                {
                    parent[s1]=s2 ;
                    rank[s2]+=rank[s1];
                }
                else 
                {
                    parent[s2]=s1 ;
                    rank[s1]+=rank[s2];
                }
            }
        }       
};

class Graph
{
    vector<vector<int>> edgeList ;
    int V ;
    public :
        Graph(int V)
        {
            this->V = V ;
        }
        void addEdge(int x, int y , int w)
        {
            edgeList.pb({w,x,y});
        }
        int kruksal_mst()
        {
            DSU s(V);
            sort(all(edgeList));
            int ans=0 ;
            trav(edge,edgeList)
            {
                int x=edge[1];
                int y=edge[2];
                int w=edge[0];
                if(s.find(x)!=s.find(y))
                {
                    s.unite(x,y);
                    ans+=w ;
                }
            }
            return ans ;
        }
};

int main()
{
    FIO
    //execution  
    return 0 ;
}
