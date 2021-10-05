#include <iostream>
#include <string>
#include <vector>

using namespace std;

void radixSort(string arr[], int n, int max)
{
    int i, j, index, count = 0;
    vector<string> pocket[10];
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < n; j++)
        {
            int length = arr[j].length();

            if (length <= i)
            {
                index = 0;
            }
            else
            {
                index = arr[j][length - 1 - i] - '0';
            }
            pocket[index].push_back(arr[j]);
        }
        count = 0;
        for (j = 0; j < 10; j++)
        {
            while (!pocket[j].empty())
            {
                arr[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    string arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 1)
    {
        cout << "0" << endl;
        return 0;
    }

    radixSort(arr, n, 10);

    int max_needed = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int current = stoi(arr[i]);
        int next = stoi(arr[i + 1]);

        int diff = next - current;

        if (max_needed < diff)
        {
            max_needed = diff;
        }
    }

    cout << max_needed << endl;

    return 0;
}
