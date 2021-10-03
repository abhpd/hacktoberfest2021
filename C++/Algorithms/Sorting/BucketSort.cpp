//Bucket Sort
//Time Complexity: O(n + k) for best case and average case and O(n2 ) for worst case.
//Space Complexity: O(nk) for worst case

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to print array
void print(float *array, int size)
{
   for (int i = 0; i < size; i++)
      cout << array[i] << " ";
   cout << endl;
}

// Sorting Function
void bucketSort(float *array, int size)
{
   vector<float> bucket[size];
   for (int i = 0; i < size; i++)
   {
      bucket[int(size * array[i])].push_back(array[i]); //put elements into different buckets
   }
   for (int i = 0; i < size; i++)
   {
      sort(bucket[i].begin(), bucket[i].end()); //sort individual vectors
   }
   int index = 0;
   for (int i = 0; i < size; i++)
   {
      while (!bucket[i].empty())
      {
         array[index++] = *(bucket[i].begin());
         bucket[i].erase(bucket[i].begin());
      }
   }
}

// Main Function
int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   float arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   print(arr, n); // Printing array before sorting

   bucketSort(arr, n); // Sorting the array using bucket sort

   cout << "Array after Sorting: ";
   print(arr, n); // Printing array after sorting
}