/**
 * In a N*N maze a rat is placed at (0,0) and has to reach (N-1,N-1).Find all possible paths
 * that the rat can take to reach destination if directions allowed for movement are :
 * UP (U)
 * DOWN (D)
 * LEFT (L)
 * RIGHT (R)
 * A cell in matrix is blocked if mat[i][j]=0 else the rat can move to that cell 
 * N<10
 * eg maze is of size 4
 * 0 0 1 0
 * 1 1 0 0
 * 0 0 1 1
 * 1 0 1 0
 * as the initial cell is blocked hence no possible path.
 * */
#include<vector>
#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;

int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
char ch[4]={'D','L','R','U'};
int vis[10][10];
vector<string>ans;
string path;

bool isSafe(int i,int j,int n)
{
    if(i>=0 && j>=0 && i<n && j<n && vis[i][j]==0)
    return true;
    return false;
}
void possiblePath(int x,int y, int dest,vector<vector<int>> &maze)
{
    if(x==dest-1 && y==dest-1)
    {
        ans.push_back(path);
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        if(isSafe(x+dx[i],y+dy[i],dest) &&  maze[x+dx[i]][y+dy[i]]==1 )
        {
            path.push_back(ch[i]);
            possiblePath(x+dx[i],y+dy[i],dest,maze);
            path.pop_back();
        }
    }
    vis[x][y]=0;
}
//function to find possible path !
vector<string> findPath(vector<vector<int>> &maze, int n) 
{
    memset(vis,0,sizeof(vis));
    if(maze[0][0]==0)
        return ans;
    possiblePath(0,0,n,maze);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int N;
    cout<<"enter the size of maze";
    cin>>N;
    int i,j;
    cout<<"enter the maze constraints\n";
    vector<vector<int>>maze(N, vector<int> (N,0));
    
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin>>maze[i][j];
        }
    }
    //find the path possible using this function
    vector<string> result = findPath(maze, N);
    if(result.size()==0)
        cout<<"No possible path to reach the destination\n";
    else
    {
        cout<<"Possible path to reach the destination are:\n";
        for(i=0;i<result.size();i++)
        {
            cout<<result[i]<<"\n";
        }
    }
}
    