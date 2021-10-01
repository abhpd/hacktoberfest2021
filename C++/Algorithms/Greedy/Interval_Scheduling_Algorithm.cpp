// Interval Scheduling Algorithm
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void printMaxActivities(vector< pair<int, int> > &v, int n)
{
    sort(v.begin(), v.end(), cmp);
    int i, j;
    cout << "Following activities are selected " << endl;

    // The first activity always gets selected
    i = 0;
    cout << " " << i;

    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
        pair<int, int> p2 = v[i];
        pair<int, int> p1 = v[j];
        if (p1.first >= p2.second)
        {
            cout << " " << j;
            i = j;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of vector : ";
    cin >> n;
    vector< pair<int, int> > v(n);
    cout << "\nEnter pair of start and end of activity : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    // vector< pair<int, int> > v = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    printMaxActivities(v, n);
    return 0;
}