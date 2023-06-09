#include <iostream>
using namespace std;

//Function to get the largest element from an array
int getMax(int arr[], int n)
{
  int mx = arr[0];
  for (int i = 1; i < n; i++)
    if (arr[i] > mx)
      mx = arr[i];
  return mx;
}

//Using counting sort to sort the elements in the basis of significant places
void countSort(int array[], int size, int place) 
{
  const int mx = 10;
  int output[size];
  int count[mx];

  for (int i = 0; i < mx; ++i)
    count[i] = 0;

  //Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  //Calculating cumulative count
  for (int i = 1; i < mx; i++)
    count[i] += count[i - 1];

  //Placing the elements in sorted order
  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

//Main function to implement radix sort
void radixsort(int array[], int size) 
{
  //Getting maximum element
  int mx = getMax(array, size);

  //Applying counting sort to sort elements based on place value.
  for (int place = 1; mx / place > 0; place *= 10)
    countSort(array, size, place);
}

//Printing an array
void display(int array[], int size) 
{
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << "\t";
  cout << endl;
}

int main() 
{
  int array[] = {112, 400, 543, 441, 678, 675, 9, 777};
  int n = sizeof(array) / sizeof(array[0]);
  cout<<"Before sorting \n";
  display(array, n);
  radixsort(array, n);
  cout<<"After sorting \n";
  display(array, n);
}
