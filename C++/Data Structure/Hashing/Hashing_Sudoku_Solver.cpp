#include <bits/stdc++.h>
using namespace std;
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> row, vector<map<int, int>> col)
{
    if (r == 9)
    {
       
        for (auto it : a)
        {
            for (auto i : it)
            {
                cout << i << " ";
            }
            cout << endl;
            return;
        }
        if (c == 9)
        {
            helper(r + 1, 0, a, mp, row, col);
            return;
        }
        if (a[r][c] != '.')
        {
            helper(r, c + 1, a, mp, row, col);
            return;
        }
        for (int i = 1; i <= 9; i++)
        {
            int rw = r / 3, cl = c / 3;
            if (!mp[{rw, cl}][i] and !row[r][i] and !col[c][i])
            {
                mp[{rw, cl}][i] = 1;
                row[r][i] = 1;
                col[c][i] = 1;
                a[r][c] = i + '0';
                helper(r, c + 1, a, mp, row, col);
                mp[{rw, cl}][i] = 0;
                row[r][i] = 0;
                col[c][i] = 0;
                a[r][c] = '.';
            }
        }
    }
}

void solveSudoku(vector<vector<char>> &a)
{
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != '.')
            {
                mp[{i / 3, j / 3}][a[i][j] - '0'] = 1;
                row[i][a[i][j] - '0'] = 1;
                col[i][a[i][j] - '0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
}

int main()
{

    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},

    };
    solveSudoku(sudoku);
}