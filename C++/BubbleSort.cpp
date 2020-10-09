// bubble sort
// Edit: Modified to pass fucntion as a fucntion parameter
#include<stdio.h>

bool compare(int a, int b) {
	return a > b;
}

// Bubble Sort
void bubblesort(int arr[], int n, bool (*cmp)(int, int)) {
	for (int j = n - 1; j > 0; j--) {
		for (int i = 0; i < j; i++) {
			if (cmp(arr[i + 1], arr[i])) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

int main() {
	int x;
	scanf("%d", &x);
	int arr[13] = {5, 4, 9, 123, 58, 37, 324, 444, 699, 347, -1, 0, 200};
	int n = sizeof(arr) / sizeof(arr[0]);

	bubblesort(arr, n, compare);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
