#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    //check for any queen in col
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y] == 1)
            return false;
    }
    //left diagonal
    int row = x, col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }
    //right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true;
}
//no need for col varialbe; we wont be checking for col, we will move to next row after placing the quen
bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
    { //base case
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
                return true;
            arr[x][col] = 0; //backtracking
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}