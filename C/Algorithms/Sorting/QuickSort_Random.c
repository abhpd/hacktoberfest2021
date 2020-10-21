#include <stdlib.h>
#include <time.h>

static inline void swap(int* arr, int x, int y) {
  // utility swap function
	if(x==y) return;
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}
static inline int choose_pivot(int start, int end) {
	// chooses a RANDOM number between start 
	// and end by taking any number
	// from 0 to length of current array and adding start to it
  return (random() % (end - start + 1)) + start ; 
}
int partition(int* arr, int start, int end) {
  int pivot = choose_pivot(start,end); 
  // swapping the pivot to the start point
	swap(arr,start,pivot);
  pivot = start;
	// using i as the seperator between right of pivot and left
  int i = start+1;
	// skipping elements who are less than pivot
  for(; i <= end && arr[i] <= arr[pivot]; i++) ;
  int j = i+1;
	// making left side of pivot smaller than it by swapping elements
  for(; j <= end; j++) {
    if(arr[j] < arr[pivot]) {
      swap(arr,j,i);
      i++;
    }
  }
	// swapping pivot to the partition point where left is less than pivot
	// and right is greater than pivot
  swap(arr,i-1,pivot);
	// returning pivot position
  return i-1;
}
void quick_sort_rec(int* arr, int start, int end) {
  if(start < end) {
		// choosing a pivot and then sorting around it
		int pivot = partition(arr,start,end);
    // recursing over the left array of the pivot
		quick_sort_rec(arr,start,pivot-1);
		// recursing over the right array of the pivot
    quick_sort_rec(arr,pivot+1,end);
  }
}
// The actual Quick sort function for the user to call
void quick_sort(int* arr, int size) {
	// Setting the random seed for choosing pivots
  srandom(time(NULL));
	// calling the recursive implementation
  quick_sort_rec(arr,0,size-1);
}

