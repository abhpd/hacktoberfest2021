#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int find) // finding between l to r index of the arr[]
{
	if (r >= l)
	{
		int m = l + (r - l) / 2; // m = middle
		
		if (arr[m] == find)
			return m;

		if (arr[m] > find)
			return binarySearch(arr, l, m - 1, find);

		return binarySearch(arr, m + 1, r, find);
	}
	return -1; // returns -1 if cant find out the element from the arr
}

int main()
{
	int arr[] = {7, 8, 9, 10, 40};
	int find = 40; // element that you are finding from the arr[]
	int n = sizeof(arr) / sizeof(arr[0]);
	int res = binarySearch(arr, 0, n - 1, find);
	if (res == -1)
		cout << "not found"; // finding element is not found in arr[]
	else
		cout << res << endl; // index of the finding element in arr[]
	return 0;
}
