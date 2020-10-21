// Program to perform Heap Sort in C
#include <iostream> 
using namespace std; 

// Function to swap the the position of two elements
void swap(int *a, int *b) 
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) 
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  // check if left node is larger then i 
  if (left < n && arr[left] > arr[largest])
    largest = left;

  // check if right node is larger then i 
  if (right < n && arr[right] > arr[largest])
    largest = right;

  // Swap and heapify
  if (largest != i) 
  {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) 
{
  // Build max-heap
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  for (int i = n - 1; i >= 0; i--) 
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
  for (int i = 0; i < n; ++i)
    cout<<arr[i]<<" ";
  cout<<endl;
}


int main() 
{
  int n;
  cout<<"Enter size of array : ";
  cin>>n;
  int arr[n];
  int i;
  cout<< "Enter array elements one by one : ";
  for(i=0; i<n; i++)
  {
    cin>>arr[i];
  }

  heapSort(arr, n);

  cout<< "Array after heap-sort : ";
  printArray(arr, n);
  return 0;
}