/*A maze is in the form of a 2D matrix in which some cells/blocks are blocked. One of the cells is termed as a source cell, from where we have to start. 
And another one of them is termed as a destination cell, where wehave to reach. 
We have to find a path from the source to the destination without moving into any of the blocked cells. 
A picture of an unsolved maze is shown below, where grey cells denote the dead ends and white cells denote the cells which can be accessed.
*/
#include<iostream>
using namespace std;

//It will check if we can move to next cell of matrix or not
bool isSafe(int **arr,int x,int y,int n)
{
	if(x<n && y<n && arr[x][y]==1)
	{
		return true;
	}
	
	return false;
}

bool RatInMaze(int **arr,int x,int y,int n,int **solve)
{
	if(x==n-1 && y==n-1)//base condition when rat reaches to its destination 
	{
		solve[x][y]=1;
		return true;
	}
	
	if(isSafe(arr,x,y,n))
	{
		solve[x][y]=1;
		if(RatInMaze(arr,x+1,y,n,solve)) //moving to right direction
		{
			return true;

		}
		if(RatInMaze(arr,x,y+1,n,solve))  //moving to down direction
		{
			return true;
		}
		solve[x][y]=0;   //if we have choosen wrong direction then backtrack means move to initial right direction again
		return false;
	}
	
	return false;
}

int main()
{
	int n;
	cin>>n;
	
	int** arr = new int *[n];
	
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int** solve = new int *[n];
	
	for(int i=0;i<n;i++)
	{
		solve[i] = new int[n];
		
		for(int j=0;j<n;j++)
		{
			solve[i][j]=0;
		}
	}
	
	cout<<endl;
	cout<<endl;
	
	if(RatInMaze(arr,0,0,n,solve))
	{
		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<solve[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	else
	{
		cout<<"Path is not there in the maze.";
	}
	
}

//Sample Input
//5
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1
*/