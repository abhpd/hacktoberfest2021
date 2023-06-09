#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc ll tc; cin>>tc ; cin.ignore(5,'\n'); for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
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

const int N=100005 ;

using namespace std;

vector<int> a(N) ;

struct segment_tree_of_vectors
{
	vector<int> st[N*4];
	void build_tree(int start , int end , int node)
	{
		if(start==end)
		{
			st[node].pb(a[start]);
			return ;
		}
		int mid=(start+end)/2 ;
		build_tree(start,mid,2*node+1);
		build_tree(mid+1,end,2*node+2);
		merge(all(st[2*node+1]) , all(st[2*node+2]) , back_inserter(st[node]));
	}	

	int query(int start , int end , int l , int r , int k , int node)
	{
		if(start>r or end<l) return 0;
		if(start>=l and end<=r)
		{
			return st[node].size()-(lower_bound(all(st[node]),k) - st[node].begin()); // consider = ffs 
		}
		int mid=(start+end)/2 ;
		int left=query(start,mid,l,r,k,2*node+1);
		int right=query(mid+1,end,l,r,k,2*node+2);
		return left+right ;
	}

}tree;

int main()
{
    int n ;
    cin>>n ;
    arr(a,n);
    tree.build_tree(0,n-1,0);
    int q ;
    cin>>q ;
    while(q--)
    {
        int l,r,k ;
        cin>>l>>r>>k ;
	      l-- ; r-- ; 
        cout<<tree.query(0,n-1,l,r,k,0)<<endl;
    }
    return 0;
}
