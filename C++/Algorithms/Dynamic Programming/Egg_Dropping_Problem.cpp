#include <bits/stdc++.h>
using namespace std;
#define MAX 100

vector<vector<int>> memoArr(MAX, vector<int> (MAX, -1));
int eggDropPuzzle(int n, int k) {

	if(memoArr[n][k] != -1) { return memoArr[n][k];}
	
	if (k == 1 || k == 0)
	return k;

	if (n == 1)
	return k;

	int min = INT_MAX, x, res;

	for (x = 1; x <= k; x++) {
	res = max(
		eggDropPuzzle(n - 1, x - 1),
		eggDropPuzzle(n, k - x));
	if (res < min)
		min = res;
	}
	
	memoArr[n][k] = min+1;
	return min + 1;
}

int main() {

	int n =3, k = 24;
	cout<<eggDropPuzzle(n, k);
	return 0;
}