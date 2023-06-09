#include <iostream>
using namespace std;
int get_max(int arr[], int num)
{
	int max = arr[0];
	for (int i = 1; i < num; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
void countSort(int arr[], int num, int exp)
{
	int output[num];
	int i, count[10] = { 0 };

	for (i = 0; i < num; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = num - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < num; i++)
		arr[i] = output[i];
}

void radixsort(int arr[], int num)
{
	int m = get_max(arr, num);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, num, exp);
}

void print(int arr[], int num)
{
	for (int i = 0; i < num; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 100, 75, 40, 40, 82, 240, 52, 76 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	radixsort(arr, n);
	print(arr, n);
	return 0;
}
