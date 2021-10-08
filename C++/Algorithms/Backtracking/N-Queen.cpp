// The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;  // result vector

// checks whether it is safe to place the queen
bool isSafe(vector<vector<int>> board, int row, int col)
{

    int i, j;
    int n = board.size();

    // check row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side 
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}


bool solveNQ(vector<vector<int>> &board, int col)
{

    int n = board.size();

    // Base Case: If all queens are placed.
    if (col == n)
    {
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1)       // iterate over the whole board to get the column positions of the queens
                    v.push_back(j + 1);  // push column value
            }
        }
        result.push_back(v);
        return true;
    }

    // Consider the current column(col) and try placing this queen in all rows one by one
    bool res = false;
    for (int i = 0; i < n; i++)    // iterate over row
    {
        if (isSafe(board, i, col))  // Check if queen can be placed in (i, col)
        {
            board[i][col] = 1;  // Place the queen
            res = solveNQ(board, col + 1) || res;  // Make res true if placement is possible

            // If we dont get the result by placing queen in (i, col)
            board[i][col] = 0;      // Backtracking
        }
    }
    return res;  // return false as we backtrack
}

// This function creates a board and uses solveNQ to return all the possible solutions of N Queen
vector<vector<int>> nQueen(int n)
{

    result.clear();
    vector<vector<int>> board(n, vector<int>(n, 0)); // n*n matrix having values 0

    if (solveNQ(board, 0) == false)
        return {};

    sort(result.begin(), result.end());
    return result;
}

int main()
{

    int n = 4;
    vector<vector<int>> v = nQueen(n);

    for (auto ar : v)
    {
        cout << "[ ";
        for (auto it : ar)
            cout << it << " ";
        cout << "] ";
    }

    return 0;
}