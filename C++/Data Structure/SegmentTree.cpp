#include<bits/stdc++.h>

#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db double
#define pp(x) pair<x,x>
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

using namespace std;

void build(int *a, int *tree, int ss, int se, int index)
{
    if(ss==se)
    {
        tree[index]= a[ss];
        return;
    }
    int mid= (ss+se)/2;
    build(a,tree,ss,mid,2*index);
    build(a,tree,mid+1,se,2*index+1);
    tree[index]= min(tree[2*index], tree[2*index+1]);
    return;
}

int query(int *tree,int ss,int se,int l,int r,int i)
{
    if(l>se || r<ss)
    return INT_MAX;

    if(l<=ss && r>=se)
    return tree[i];

    int mid=(ss+se)/2;
    int ls= query(tree,ss,mid,l,r,2*i);
    int rs= query(tree,mid+1,se,l,r,2*i+1);
    return min(ls,rs);
}

void update(int *tree,int ss,int se,int l,int val,int i){
    if(l>se || l<ss) return;
    if(ss==se) { tree[i]=val ; return; }
    int mid=(ss+se)/2;
    update(tree,ss,mid,l,val,2*i);
    update(tree,mid+1,se,l,val,2*i+1);
    tree[i]= min(tree[2*i], tree[2*i+1]);
}

void updateinrange(int *tree , int ss , int se , int val , int index , int l , int r)
{
  if(l<se || r>ss) return ;
  if(ss==se) { tree[index]+=val ; return ; }
  int mid=(ss+se)/2 ;
  updateinrange(tree , ss , mid , val , 2*index , l , r);
  updateinrange(tree , mid+1 , se , val , 2*index+1 , l ,r);
  tree[index]=min(tree[2*index] , tree[2*index+1]);
}

int lazy[1000]={0};

void lazyupdate(int *tree , int ss , int se , int l , int r , int inc , int index)
{
  if(lazy[index]!=0)
  {
    tree[index]+=lazy[index];
    if(ss!=se)
    {
      tree[2*index]+=lazy[index];
      tree[2*index+1]+=lazy[index];
    }
    lazy[index]=0 ;
  }
  if(r<ss || l>se) return ;
  if(ss>=l && se<=r)
  {
    tree[index]+=inc ;
    if(ss!=se)
    {
      lazy[2*index]+=inc ;
      lazy[2*index+1]+=inc ;
    }
    return ;
  }
  int mid=(ss+se)/2 ;
  lazyupdate(tree,ss,mid,l,r,inc,2*index);
  lazyupdate(tree,mid+1,se,l,r,inc,2*index+1);
  tree[index]=min(tree[2*index] , tree[2*index+1]);
}

int getsum(int *tree , int ss, int se, int l , int r , int index)
{
    if (lazy[index] != 0)
    {
        tree[index] += (se-ss+1)*lazy[index];
        if (ss != se)
        {
            lazy[2*index+1] += lazy[index];
            lazy[2*index] += lazy[index];
        }
        lazy[index] = 0;
    }
    if (ss>se or ss>r or se<l) return 0;

    if (ss>=l and se<=r) return tree[index];

    int mid = (ss + se)/2;
    return getsum(tree,ss, mid, l , r, 2*index+1) + getsum(tree,mid+1, se, l, r, 2*index+2);
}

int main()
{
    FIO
    int a[]={1,4,3,5,2};
    int n=sizeof(a)/sizeof(int);
    build_tree(a,tree,0,n-1,0);
    return 0;
}
