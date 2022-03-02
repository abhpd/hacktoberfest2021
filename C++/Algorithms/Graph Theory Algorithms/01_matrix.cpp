/*
problem statement:-
Given an n x m binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

test case fomrat:-
N M 
[[...],[...],...] array

test case:- 
Enter n & m:  3 3
Input matrix:
0 0 0
0 1 0
0 0 0

Output:- 
0 0 0 
0 1 0
0 0 0

*/


#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second

int main()
{
    int n, m;
    cout<<"Enter n & m: ";
    cin>>n>>m;
    int mat[n][m];

    cout<<"Input matrix:-\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    queue<pair<pair<int,int>,int>> Q;
        
    vector<vector<int>> ans(n,vector<int> (m,0));
        
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==0)
                Q.push({{i,j},0});
            else
                ans[i][j]=INT_MAX;
        }
    }
        
    int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        
    while(!Q.empty())
    {
        auto x=Q.front();
        Q.pop();
 
        for(int i=0;i<4;i++)
        {
            int a=x.f.f+d[i][0],b=x.f.s+d[i][1];
                
            if(a>=0 && a<n && b>=0 && b<m && mat[a][b]==1)
            {
                if(ans[a][b]>1+ans[x.f.f][x.f.s])
                {
                    ans[a][b]=1+ans[x.f.f][x.f.s];
                    Q.push({{a,b},x.s});
                }
                mat[a][b]=0;
            }
        }
    }

    cout<<"\nOutput matrix:-\n";  

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }  
    cout<<"\n";

    return 0;
}

// time complexity:-  O(N*M)
// space complexity:- O(N*M)