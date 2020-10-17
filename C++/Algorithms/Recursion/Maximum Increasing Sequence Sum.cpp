#include <iostream>
#include <climits>
using namespace std;

// Function to find maximum sum of increasing subsequence
int MSIS(int arr[], int i, int n, int prev, int sum)
{
	// Base case: nothing is remaining
	if (i == n)
		return sum;

	// case 1: exclude the current element and process the
	// remaining elements
	int excl = MSIS(arr, i + 1, n, prev, sum);

	// case 2: include the current element if it is greater
	// than previous element
	int incl = sum;
	if (arr[i] > prev)
		incl = MSIS(arr, i + 1, n, arr[i], sum + arr[i]);

	// return maximum of above two choices
	return max(incl, excl);
}

int main()
{
	int arr[] = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Maximum sum of increasing subsequence is " <<
			MSIS(arr, 0, n, INT_MIN, 0);

	return 0;
}