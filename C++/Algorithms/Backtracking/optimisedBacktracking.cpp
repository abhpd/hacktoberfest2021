/*
There are 88418 paths in a 7×7 grid from the upper-left square to the lower-left square. Each path corresponds to a 48-character description consisting of characters D (down), U (up), L (left) and R (right).

For example, the path

corresponds to the description DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD.

You are given a description of a path which may also contain characters ? (any direction). Your task is to calculate the number of paths that match the description.

Input

The only input line has a 48-character string of characters ?, D, U, L and R.

Output

Print one integer: the total number of paths.

Example

Input:
??????R??????U??????????????????????????LD????D?

Output:
201
*/

#include<bits/stdc++.h>
using namespace std;
 
#define ll long long 
 
ll cnt=0;
 
int vis[7][7];
 
//int dx[4] = {-1,1,0,0};
//int dy[4] = {0,0,-1,1};
//char ch[4] = {'U','D','L','R'};
 
bool isVal(int x,int y) {
    if(x<0 || x>=7 || y<0 || y>=7)
    return false;
 
    if(vis[x][y]==1)
    return false;
 
    return true;
}
 
void fun(vector<char> &v,int ind,int x,int y) {
    //
    if(ind==48)
    {
        if(x==6 && y==0)
        cnt++;
 
        return;
    }
 
    if(x==6 && y==0)
    return;
 
    vis[x][y] = 1;
 
    if ((v[ind] == '?' || v[ind] == 'R') && isVal(x,y+1)) { 
        // R
    bool lck = !isVal(x,y+2) && isVal(x-1,y+1) && isVal(x+1,y+1);
 
    if (!lck) {
 
       // vis[x][y + 1] = 1;
        fun(v,ind+1,x,y+1);
       // vis[x][y+1] = 0;
    }
      }
 
      //
 
     if ((v[ind] == '?' || v[ind] == 'L') && isVal(x,y-1)) { 
        // L
    bool lck = !isVal(x,y-2) && isVal(x-1,y-1) && isVal(x+1,y-1);
 
    if (!lck) {
 
       // vis[x][y - 1] = 1;
        fun(v,ind+1,x,y-1);
       // vis[x][y-1] = 0;
    }
}
 
//
 
 if ((v[ind] == '?' || v[ind] == 'U') && isVal(x-1,y)) { 
        // U
    bool lck = !isVal(x-2,y) && isVal(x-1,y+1) && isVal(x-1,y-1);
 
    if (!lck) {
 
       // vis[x-1][y] = 1;
        fun(v,ind+1,x-1,y);
       // vis[x-1][y] = 0;
    }
}
 
//
 
 if ((v[ind] == '?' || v[ind] == 'D') && isVal(x+1,y)) { 
        // D
    bool lck = !isVal(x+2,y) && isVal(x+1,y+1) && isVal(x+1,y-1);
 
    if (!lck) {
 
       // vis[x+1][y] = 1;
        fun(v,ind+1,x+1,y);
       // vis[x+1][y] = 0;
    }
}
 
vis[x][y] = 0;
 
 
}
 
int main() {
    vector<char> v(48);
 
    for(int i=0;i<48;i++)
    cin>>v[i];
 
    cnt=0;
 
    memset(vis,0,sizeof(vis));
 
    fun(v,0,0,0);
 
    cout<<cnt<<"\n";

    return 0;
}

