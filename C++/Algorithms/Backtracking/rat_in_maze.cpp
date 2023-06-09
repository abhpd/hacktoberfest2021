/*
    Given a N*N maze matrix with a rat placed at the upper left most block of maze (maze[0][0]) 
    and we have to move rat towards lower rightmost destination block maze[N-1][N-1]. Rat can move only in two direction : forward and down.
    (i,j) -> (i+1,j) or (i,j+1);
*/


#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool valid(int x,int y,int n)
{
    return (x>=0 && x<n && y>=0 && y<n);
}
bool solve(vector<vector<int>>&matrix,int maze[][20],int n,int x,int y)
{
    if(x>n || y>n || y<0 || x<0)
    {
        return false;
    }
    if(x == n-1 && y == n-1)
    {
        matrix[x][y]  = 1;
        return true;
    }
    
    matrix[x][y] = 1;
    for(int i = 0;i<4;i++)
    {
        int newx = x+dx[i];
        int newy = y+dy[i];
       
        if(maze[newx][newy]==1 && valid(newx,newy,n) && matrix[newx][newy]==0 and solve(matrix,maze,n,newx,newy))
        {
            return true;
        }   
    }
    matrix[x][y] = 0;
    return false;
}

void ratInAMaze(int maze[][20], int n){
	vector<vector<int>>matrix(n+1,vector<int>(n+1,0));
    if(solve(matrix,maze,n,0,0))
    {
        cout<<"Solution:- "<<endl;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<matrix[i][j]<<" "; 
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Solution does not exist"<<endl;
    }
}

int main()
{

    // Taking input
    int n; 
    cin >> n ;
    int maze[20][20];
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < n; j++){
                cin >> maze[i][j];
            }		
    }
    
    ratInAMaze(maze,n);
    return 0;
}

/* 
  TestCase 1:
	Input:
		N = 3
		maze[3][3] = 1 0 1
			     1 0 1
			     1 1 1
	Output:
		1 0 0 
		1 0 0 
		1 1 1 
   TestCase 2:
	Input:
		N  = 4
		maze[4][4] =  1 0 0 1
			      1 1 1 0
			      1 0 1 1
			      0 0 1 1
	Output:
		1 0 0 0
                1 1 1 0
                0 0 1 0
		0 0 1 1
	
	
Time Complexity = O(2^n)
Space Complexity = O(n*n)
where n = size of maze rows and columns
		
*/