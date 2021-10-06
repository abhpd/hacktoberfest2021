/*
Problem (Classic):
Consider an n×n grid whose squares may have traps. It is not allowed to move to a square with a trap.

Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down.

Input

The first input line has an integer n: the size of the grid.

After this, there are n lines that describe the grid. Each line has n characters: . denotes an empty cell, and * denotes a trap.

Output

Print the number of paths modulo 109+7.

Constraints
1≤n≤1000
Example

Input:
4
....
.*..
...*
*...

Output:
3
*/

#include <bits/stdc++.h>
#define ll long long int
#define omar main
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//priority_queue push_back make_pair emplace vector double float unordered_map unordered_set queue stack sort begin resize clear second first continue break
using namespace std;
const int N = 1010;
int n, dp[N][N], mod = 7 + 1e9;
string arr[N];
int calc(int x, int y){
	if ((x == n-1) && (y == n-1) && (arr[x][y] != '*'))return 1;
	if ((x >= n) || (y >= n)) return 0;
	if (arr[x][y] == '*')return 0;
	if (dp[x][y] != -1) return dp[x][y];
	int right = calc(x, y+1);
	int down = calc(x+1, y);
	return dp[x][y] = ((down%mod) + (right%mod))%mod;
}
int omar(){ fastIO
	cin >> n;
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << calc(0, 0) << endl;
	return 0;
}
