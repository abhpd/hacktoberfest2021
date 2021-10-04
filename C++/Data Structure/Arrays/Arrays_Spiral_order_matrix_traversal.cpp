#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    //spiral order print

    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;

    while (row_start <= row_end && column_start <= column_end)
    {
        //for row start
        for (int col = column_start; col <= column_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }
        row_start++;
        //for column end
        for (int row = row_start; row <= row_end; row++)
        {
            cout << arr[row][column_end] << " ";
        }
        column_end--;

        //for row end
        for (int col = column_end; col >= column_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }
        row_end--;

        //for column start
        for (int row = row_end; row >= row_start; row--)
        {
            cout << arr[row][column_start] << " ";
        }
        column_start++;
    }

    return 0;
}