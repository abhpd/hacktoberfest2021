#include <bits/stdc++.h>
using namespace std;
 
// Comparator class to assign
// priority to coordinates
class comp {
 
public:
    bool operator()(pair<int, int> a,
                    pair<int, int> b)
    {
        int x1 = a.first * a.first;
        int y1 = a.second * a.second;
        int x2 = b.first * b.first;
        int y2 = b.second * b.second;
 
        // return true if distance
        // of point 1 from origin
        // is greater than distance of
        // point 2 from origin
        return (x1 + y1) > (x2 + y2);
    }
};

void kClosestPoints(int x[], int y[],
                    int n, int k)
{
    // Priority queue
    priority_queue<pair<int, int>,
                   vector<pair<int, int> >,
                   comp>
        pq;
 
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(x[i], y[i]));
    }
 
    for (int i = 0; i < k; i++) {
 
        pair<int, int> p = pq.top();
 
        cout << p.first << " "
             << p.second << endl;

        pq.pop();
    }
}
int main()
{

    int x[] = { 1, -2 };
 
 
    int y[] = { 3, 2 };
    int K = 1;
 
    int n = sizeof(x) / sizeof(x[0]);
 
    kClosestPoints(x, y, n, K);
 
    return 0;
}