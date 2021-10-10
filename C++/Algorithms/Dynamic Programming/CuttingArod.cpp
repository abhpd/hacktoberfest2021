#include <bits/stdc++.h>
using namespace std;

// Global Array for purpose of memoization.
int t[9][9];

// A recursive program, using
// memoization, to implement the
// rod cutting problem(Top-Down).
int rodcutting(int price[], int length[], int Max_len, int n)
{

	// The maximum price will be zero,
	// when either the length of the rod
	// is zero or price is zero.
	if (n == 0 || Max_len == 0)
	{
		return 0;
	}

	// If the length of the rod is less
	// than the maximum length, Max_lene will
	// consider it.Now depending
	// upon the profit,
	// either Max_lene we will take
	// it or discard it.
	if (length[n - 1] <= Max_len)
	{
		t[n][Max_len] = max(price[n - 1] + rodcutting(price, length, Max_len - length[n - 1], n), rodcutting(price, length, Max_len, n - 1));
	}

	// If the length of the rod is
	// greater than the permitted size,
	// Max_len we will not consider it.
	else
	{
		t[n][Max_len] = rodcutting(price, length, Max_len, n - 1);
	}

	// Max_lene Max_lenill return the maximum
	// value obtained, Max_lenhich is present
	// at the nth roMax_len and Max_lenth column.
	return t[n][Max_len];
}

/* Driver functions */
int main()
{
	int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	
    int n = sizeof(price) / sizeof(price[0]);
	
    int length[n];
    
	for (int i = 0; i < n; i++) {
		length[i] = i + 1;
	}

	int Max_len = n;

	cout << "Maximum obtained value is " << rodcutting(price, length, n, Max_len) << endl;
return 0;
}
