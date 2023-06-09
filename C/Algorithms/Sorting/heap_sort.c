// Program to perform Heap Sort in C
#include <stdio.h>
#include <stdlib.h>

// Function to swap the the position of two elements
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) 
{
  int largeOne = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // check if left node is larger then i 
  if (left < n && arr[left] > arr[largeOne])
    largeOne = left;

  // check if right node is larger then i 
  if (right < n && arr[right] > arr[largeOne])
    largeOne = right;

  // Swap and heapify
  if (largeOne != i) 
  {
    swap(&arr[i], &arr[largeOne]);
    heapify(arr, n, largeOne);
  }
}

void heapSort(int arr[], int n) 
{
  // Build max-heap
  int i;
	for (i = (n / 2)- 1; i >= 0; i--){
    	heapify(arr, n, i);
	}

  for (i = n - 1; i >= 0; i--) 
  {
    //Move the root node at the end
    swap(&arr[0], &arr[i]);

    //Heapify the remaining tree
    heapify(arr, i, 0);
  }
}

// Print an array
void printArray(int arr[], int n) 
{
	int i;
  for (i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}


int main() 
{
  int n;
  printf("Enter size of array : ");
  scanf("%d", &n);
  int arr[n];
  int i;
  printf("Enter array elements one by one : ");
  for(i=0; i<n; i++)
  {
    scanf("%d", &arr[i]);
  }

  heapSort(arr, n);

  printf("Array after heap-sort : ");
  printArray(arr, n);
  return 0;
}
