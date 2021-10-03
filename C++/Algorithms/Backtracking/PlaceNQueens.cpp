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

using namespace std;

bool isSafe(board[][10] , int i , int j , int n)
{
  // check right diagonal 
  forn(row,i)
  {
    if(board[row][j]==1) return false ;
  }
  int x=i , y=j ;
  while(x>=0 && y>=0)
  {
    if(board[i][j]==1) return false ;
    x-- ;
    y-- ;
  }
  int x=i , y=j ;
  while(x>=0 && y<=n)
  {
    if(board[x][y]==1) return false ;
    x-- ;
    y++ ;
  }
  return true ;
}
    

bool placeNQueens(int board[][10] , int i , int n)
{
  if(i==n)
  {
    forn(i,n)
    {
      forn(j,n)
      {
        board[i][j]==1 ? cout<<"Q " : cout<<"_ " ;
      }
      cout<<endl ;
    }
    return false  ; // to get all the permutations 
   }
  forn(j,n)
  {
    if(isSafe(board,i,j,n)
    {
      board[i][j]=1 ;
      bool nextQueen=placeNQueens(board,i+1,n);
      if(nextQueen) return true ;
      board[i][j]=0 ;
      return false ;
    }
  }
  return false ;       
}
       
int main()
{
  FIO
  // implementation depending on given input output
  return 0;
}
