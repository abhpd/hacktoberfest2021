/*
N-Queen Problem
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Print it row wise, each column seperated by a space and each row in the next line
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

0 0 1 0 
1 0 0 0 
0 0 0 1
0 1 0 0
*/
#include<bits/stdc++.h>
using namespace std;
int board[11][11];
bool isPossible(int n, int row, int col)
{
    for(int i = row-1;i>=0;i--) // Same Column
        if(board[i][col]==1)
            return false;

    for(int i = row-1, j = col-1;i>=0 && j>=0;i--,j--) //Upper Left Diagonal
        if(board[i][j]==1)
            return false;

    for(int i = row-1,j = col+1;i>=0 && j<n;i--,j++) // Upper Right Diagonal
        if(board[i][j]==1)
            return false;
    return true;
}
void NQueenHelper(int n,int row)
{
    if(row==n)
    {
        // We have reached some solution.
        // Print the board matrix
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return ;
    }
    
    // Place at all possible positions and move to smaller problem
    for(int j = 0;j<n;j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j] = 1;
            NQueenHelper(n,row+1);
            board[row][j] = 0;
        }
    }
    
}
void printNQueens(int n)
{
    memset(board,0,11*11*sizeof(int)); // Initialised 0 in the matrix board 11x11
    NQueenHelper(n,0);
}
int main()
{
    printNQueens(4); //Printing Number of Ways to put N=4 Queens in NxN Matrix
    return 0;
}