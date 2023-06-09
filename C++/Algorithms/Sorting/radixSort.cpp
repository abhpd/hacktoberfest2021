// C++ implementation of Radix Sort
#include <bits/stdc++.h>
using namespace std;

//  Function to obtain the maximum value in a[]
int getMax(int a[], int n)
{
	int maxi = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > maxi)
			maxi = a[i];
	return maxi;
}

//Function to perform counting sort on the array based on the digit represented by e 
void countSort(int a[], int n, int e)
{
	int output_arr[n]; 
	int i, count[10] = { 0 };

	// Storing the count of occurrences of elements
	for (i = 0; i < n; i++)
		count[(a[i] / e) % 10]++;

	// Changing the values of count[] such that it contains 
	//the position of the particular digit in output_arr[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Building the output array
	for (i = n - 1; i >= 0; i--) {
		output_arr[count[(a[i] / e) % 10] - 1] = a[i];
		count[(a[i] / e) % 10]--;
	}

	// Copying the output array to a[]
	for (i = 0; i < n; i++)
		a[i] = output_arr[i];
}

//Function to implement the Radix sort 
void radixsort(int a[], int n)
{
	// Finding the maximum number
	int m = getMax(a, n);

	
	//Count sort is performed for each digit.
	
	for (int e = 1; m / e > 0; e *= 10)     // Here e is 10^i, where i is the current digit
		countSort(a, n, e);
}



// Driver Code
int main()
{
	int a[] = { 17, 450, 7, 190, 82, 324, 72, 60 };
	int n = sizeof(a) / sizeof(a[0]);
	
	// Function Call
	radixsort(a, n);
	
	//priting the sorted array
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
