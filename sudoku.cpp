#include <bits/stdc++.h> 
using namespace std; 
  
// UNASSIGNED is used for empty 
// cells in sudoku grid 
#define UNASSIGNED 0 
  
// N is used for the size of Sudoku grid. 
// Size will be NxN 
#define N 9 
  
// Checks whether it will be legal 
// to assign num to the given row, col 
bool isSafe(int grid[N][N]) 
{ 
    // Hashmap for row column and boxes 
    unordered_map<int, int> 
        row_[9], column_[9], box[3][3]; 
    for (int row = 0; row < N; row++) { 
        for (int col = 0; col < N; col++) { 
            // mark the element in row column and box 
            row_[row][grid[row][col]] += 1; 
            column_[col][grid[row][col]] += 1; 
            box[row / 3][col / 3][grid[row][col]] += 1; 
  
            // if an element is already 
            // present in the hashmap 
            if ( 
                box[row / 3][col / 3][grid[row][col]] > 1 
                || column_[col][grid[row][col]] > 1 
                || row_[row][grid[row][col]] > 1) 
                return false; 
        } 
    } 
    return true; 
} 
  
/* A utility function to print grid */
void printGrid(int grid[N][N]) 
{ 
    for (int row = 0; row < N; row++) { 
        for (int col = 0; col < N; col++) 
            cout << grid[row][col] << " "; 
        cout << endl; 
    } 
} 
  
/* Takes a partially filled-in grid and attempts  
to assign values to all unassigned locations in  
such a way to meet the requirements for 
Sudoku solution (non-duplication across rows, 
columns, and boxes) */
bool SolveSudoku( 
    int grid[N][N], int i, int j) 
{ 
    // if the index reached the end 
    if (i == N - 1 && j == N) { 
        // if the matrix is safe 
        if (isSafe(grid)) { 
            // print and stop 
            printGrid(grid); 
            return true; 
        } 
  
        // else try other cases 
        return false; 
    } 
  
    // end of a row move to next row 
    if (j == N) { 
        i++; 
        j = 0; 
    } 
  
    // if the element is non zero keep as it is 
    if (grid[i][j] != UNASSIGNED) 
        return SolveSudoku(grid, i, j + 1); 
  
    // consider digits 1 to 9 
    for (int num = 1; num <= 9; num++) { 
        // assign and call recursively 
        grid[i][j] = num; 
  
        if (SolveSudoku(grid, i, j + 1)) 
            return true; 
  
        grid[i][j] = 0; 
    } 
    return false; 
} 
  
// Driver Code 
int main() 
{ 
    // 0 means unassigned cells 
    int grid[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 }, 
                       { 5, 2, 9, 1, 3, 4, 7, 6, 8 }, 
                       { 4, 8, 7, 6, 2, 9, 5, 3, 1 }, 
                       { 2, 6, 3, 0, 1, 5, 9, 8, 7 }, 
                       { 9, 7, 4, 8, 6, 0, 1, 2, 5 }, 
                       { 8, 5, 1, 7, 9, 2, 6, 4, 3 }, 
                       { 1, 3, 8, 0, 4, 7, 2, 0, 6 }, 
                       { 6, 9, 2, 3, 5, 1, 8, 7, 4 }, 
                       { 7, 4, 5, 0, 8, 6, 3, 1, 0 } }; 
    if (SolveSudoku(grid, 0, 0) != true) 
        cout << "No solution exists"; 
  
    return 0; 
} 
