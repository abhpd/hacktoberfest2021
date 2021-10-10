//----(N^(N*N)),O(N*N) ------
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int board[][10],int i,int j, int n){
    // CHECKING FOR COLUMN
    for(int row =0;row<i;row++){
        if(board[row][j] == 1){
            return false;
        }
    }
    // CHECKING FOR LEFT DIAGONAL
    int x=i, y=j;
    while(x>=0 && y>=0){
        if(board[x][y] == 1){
            return false;
        }
        x--; 
        y--;
    }
    // CHECKING FOR RIGHT DIAGONAL
    x = i, y = j;
    while(x>=0 && y<n){
        if(board[x][y] == 1){
            return false;
        }
        x--;
        y++;
    }
    // POSITION OF THE I,J IS SAFE
    return true;
}

bool solveNQueen(int board[][10], int i, int n){
// BASE CASE 
if(i==n){
    // you have successfully placed queens in n rows (0...n-1)
    // print the board
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                cout<<"Q ";
            } else {
                cout<<"_ ";
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    return true; // TO PRINT ALL THE SOLUTION --> MAKE IT FALSE
}
    // RECURSIVE CASE
    // TRY TO PLACE THE QUEEN IN THE CURRENT ROW AND CALL ON THE REMAINING PART
    // WHICH WILL BE SOLVED BY RECURSION
    
    for(int j=0;j<n;j++){
        //check for i,j in isSafe
        if(isSafe(board,i,j,n)){
            //place the QUEEN
            board[i][j] = 1;
            
            bool nextqueen = solveNQueen(board,i+1,n);
            if(nextqueen){
                return true;
            }
            // MEANS I,J IS NOT THE RIGHT POSITION. ASSUMPTION IS WRONG
            // BACKTRACK
            
            board[i][j] = 0;
        }
    }
    // YOU HAVE TRIED FOR ALL THE POSITIONS BUT COULDN'T PLACE THE QUEEN 
    return false;
}
int main()
{
    int n;
    cin>>n;
    int board[10][10] = {0};
    
    solveNQueen(board,0,n);
    
    return 0;
}