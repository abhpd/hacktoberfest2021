#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    int target;
    cin >> target;

    int mat[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    int r = 0;
    int c = n - 1;
    bool found = false;
    while (r < m && c >= 0)
    {
        if (mat[r][c] == target)
        {
            found = true;
            break;
        }
        else if (mat[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (found)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}
