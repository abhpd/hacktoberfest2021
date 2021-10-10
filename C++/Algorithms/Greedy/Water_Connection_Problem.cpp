#include <bits/stdc++.h>
using namespace std;
 
// number of houses and number
// of pipes
int n, p;
 
// Array rd stores the
// ending vertex of pipe
int rd[1100];
 
// Array wd stores the value
// of diameters between two pipes
int wt[1100];
 
// Array cd stores the
// starting end of pipe
int cd[1100];
 
// Vector a, b, c are used
// to store the final output
vector<int> a;
vector<int> b;
vector<int> c;
 
int ans;
 
int dfs(int w)
{
    if (cd[w] == 0)
        return w;
    if (wt[w] < ans)
        ans = wt[w];
    return dfs(cd[w]);
}
 
// Function performing calculations.
void solve(int arr[][3])
{
    int i = 0;
 
    while (i < p) {
         
        int q = arr[i][0], h = arr[i][1],
            t = arr[i][2];
         
        cd[q] = h;
        wt[q] = t;
        rd[h] = q;
        i++;
    }
     
    a.clear();
    b.clear();
    c.clear();
     
    for (int j = 1; j <= n; ++j)
     
        /*If a pipe has no ending vertex
        but has starting vertex i.e is
        an outgoing pipe then we need
        to start DFS with this vertex.*/
        if (rd[j] == 0 && cd[j]) {
            ans = 1000000000;
            int w = dfs(j);
             
            // We put the details of component
            // in final output array
            a.push_back(j);
            b.push_back(w);
            c.push_back(ans);
        }
         
    cout << a.size() << endl;
    for (int j = 0; j < a.size(); ++j)
        cout << a[j] << " " << b[j]
             << " " << c[j] << endl;
}
 
// driver function
int main()
{
    n = 9, p = 6;
 
    memset(rd, 0, sizeof(rd));
    memset(cd, 0, sizeof(cd));
    memset(wt, 0, sizeof(wt));
 
    int arr[][3] = { { 7, 4, 98 },
                    { 5, 9, 72 },
                    { 4, 6, 10 },
                    { 2, 8, 22 },
                    { 9, 7, 17 },
                    { 3, 1, 66 } };
 
    solve(arr);
    return 0;
}
