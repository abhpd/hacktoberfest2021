/*
Given a chess board having  cells, you need to place N queens on the board in such a way that no queen attacks any other queen.

Input:
The only line of input consists of a single integer denoting N.

Output:
If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N integers. The integer in  line and  column will denote the cell  of the board and should be 1 if a queen is placed at  otherwise 0. If there are more than way of placing queens print any of them. If it is not possible to place all N queens in the desired way, then print "Not possible" (without quotes).


Sample Input
4

Sample Output
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 
 */
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr, int x, int y, int n){
    for(int row=0; row<x; row++){
        if(arr[row][y]==1){
            return false;
        }
    }

    int row =x;
    int col =y;
    while (row>=0 && col >=0){
        if(arr[row][col]==1){
            return false;
        }
        row --;
        col--;
    } 
    row =x ;
    col =y;
    while (row>=0 && col <n){
        if(arr[row][col]==1){
            return false;
        }
        row --;
        col ++;
    }
    return true;
}

bool nQueen(int **arr, int x , int n){
    if (x>=n){
        return true;
    }
    for (int col=0; col < n; col++){
        if (isSafe(arr,x,col,n)){
            arr[x][col]=1;
            if (nQueen(arr, x+1,n)){
                return true;
            }   
            arr[x][col]=0; 
        }

    }
    return false;
}



int main(){
    int n;
    cin >> n;
    int **arr = new int*[n];
    if (n>1 && n<4){
        cout << "Not possible";
    }
    else
    {
    for (int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0;j<n; j++)
            arr[i][j]=0;
    }
    if (nQueen(arr,0,n)){
        for (int i=0; i<n; i++){
        
            for(int j=0;j<n; j++){
                cout << arr[i][j]<< " ";
            }
            cout << endl;
        }
    }}
    return 0;
}