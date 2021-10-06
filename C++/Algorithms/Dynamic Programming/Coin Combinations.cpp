/*
Problem:
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2
Input

The first input line has two integers n and x: the number of coins and the desired sum of money.

The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output

Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤100
1≤x≤106
1≤ci≤106
Example

Input:
3 9
2 3 5

Output:
8
*/
#include <bits/stdc++.h>
#define ll long long int
#define omar main
#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//priority_queue push_back make_pair emplace vector double float unordered_map unordered_set queue stack sort begin resize clear second first continue break
using namespace std;
const int N = 110, S = 10 + 1e6;
int arr[N], dp[S], n, x, mod = 7 + 1e9;
 
int omar(){ //fastIO
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
		dp[arr[i]] = 1;
	}
	dp[0] = 0;
	for (int i = 0; i <= x; i++){
		for (int j = 1; j <= n; j++){
			if (i + arr[j] > x)continue;
			int &pivot = dp[i+arr[j]];
			pivot = ((pivot%mod) + (dp[i]%mod))%mod;
		}
	} printf("%d", dp[x]);
	return 0;
}
