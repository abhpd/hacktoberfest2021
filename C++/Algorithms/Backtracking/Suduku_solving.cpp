/*
1. Sudoku can be solved using Backtracking
2. We take the unfinished Sudoku as input from the user where we fill the 0s.
3. The Sudoku has to be filled so that no number is repeated in a row, column or 3 * 3 submatrix.
4. We try to fill a number with any valid number from 1 to 9 that is not repeated.
5. If after filling all the cells we reach the nth row, we have successfully filled the sudoku.
6. Else we try other options of filling a cell by backtracking.  
*/

#include <bits/stdc++.h>
using namespace std;

//Function that checks whether a number is repeated in a row, column or a 3 * 3 submatrix
bool isValid(vector<vector<int>> sudoku, int row, int col, int num)
{
    //checking row
    for(int i = 0; i < sudoku[0].size(); ++i)
    {
        if(sudoku[row][i] == num)
            return false;
    }

    //checking column
    for(int i = 0; i < sudoku.size(); ++i)
    {
        if(sudoku[i][col] == num)
            return false;
    }

    //checking submatrix
    int submat_row = 3 * row/3; //finding top corner row of 3 * 3 submatrix
    int submat_col = 3 * col/3; //finding top corner column of 3 * 3 submatrix
    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(sudoku[submat_row][submat_col] == num)
                return false;
        }
    }
    return true;
}

//Helper function to solve the Sudoku
void sudoku_solver(vector<vector<int>> sudoku, int row, int col)
{
    //If we reach the nth row, we have solved the sudoku and hence we print the solved sudoku
    if(row == sudoku.size())
    {
        cout<<"The solved sudoku matrix is : \n";
        for(int i = 0; i < sudoku.size(); ++i)
        {
            for(int j = 0; j < sudoku[0].size(); ++j)
            {
                cout<<sudoku[i][j]<<" ";
            }
            cout<<endl;
        }
        exit(0);
    }

    //Finding the next row and column
    int next_row = 0, next_col = 0;
    
    //if we reach the last column, next row will be current + 1 and next col will be 0 as we move to the first element of the next row
    if(col == sudoku[0].size() - 1)
    {
        next_row = row + 1;
        next_col = 0;
    }

    //Else we just increment the column by 1
    else
    {
        next_row = row;
        next_col = col + 1;
    }

    //If the number is not 0, it is already filled and hence we do not have to fill it
    if(sudoku[row][col] != 0)
    {
        sudoku_solver(sudoku, next_row, next_col);
    }

    //If the number is not filled
    else
    {
        //We try all possible options from 1 to 9
        for(int num = 1; num <= 9; ++num)
        {
            //If the option is valid, we place the number in that place or move ahead
            if(isValid(sudoku, row, col, num))
            {
                sudoku[row][col] = num;
                sudoku_solver(sudoku, next_row, next_col);
                //If the number makes the sudoku unsolvable, we remove it and recurse for other options which is the Backtracking step
                sudoku[row][col] = 0; 
            }
        }
    }
}

int main()
{
    cout<<"Enter the size of the sudoku matrix\n";
    int n;
    cin>>n;
    vector<vector<int>> sudoku;
    
    cout<<"Enter the elements of the sudoku matrix\n";
    for(int i = 0; i < n; ++i)
    {
        vector<int> sudoku_row;
        for(int j = 0; j < n; ++j)
        {
            int num;
            cin>>num;
            sudoku_row.push_back(num);
        }
        sudoku.push_back(sudoku_row);
    }

    //solving the sudoku by calling the helper method.
    sudoku_solver(sudoku, 0, 0);
    return 0;
}

/*
Input 1 : 
N = 9
sudoku = 
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0 
Output 1 : 
The solved sudoku matrix is : 
3 1 6 5 2 8 4 9 7 
5 2 1 3 4 7 8 6 9 
2 8 7 6 5 4 9 3 1 
6 4 3 9 1 5 7 8 2 
9 7 2 8 6 3 1 4 5 
7 5 8 4 9 1 6 2 3 
1 3 4 7 8 9 2 5 6 
8 6 9 1 3 2 5 7 4 
4 9 5 2 7 6 3 1 8 
*/

/*
Input 2 : 
N = 9
sudoku = 
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 0 0 
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
Output 2 : 
The solved sudoku matrix is : 
5 3 1 2 7 4 6 9 8 
6 2 3 1 9 5 8 4 7 
1 9 8 3 4 6 7 5 2 
8 4 2 9 6 7 5 1 3 
4 7 6 8 5 3 9 2 1 
7 1 9 5 2 8 4 3 6 
9 6 5 7 3 1 2 8 4 
2 8 7 4 1 9 3 6 5 
3 5 4 6 8 2 1 7 9 
*/

/* 
Time Complexity of the approach : O(9 ^ (N * N))
Space Complexity of the approach : O(N * N)
where, N = number of rows and columns of the input matrix 
*/