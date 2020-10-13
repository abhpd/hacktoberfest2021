/* Another sorting algorithm in cpp
   Time Complexity: O(n+2^k)
   Space Complexity: O(2^k)*/

#include<iostream>
#include<list>
#include<cmath>
using namespace std;

void getMaxMin(int *arr, int n, int &maximum, int &minimum) {
   maximum = minimum = arr[0]; //initially max and min ar arr[0]

   for(int i = 1; i<n; i++) {
      if(arr[i] > maximum)
         maximum = arr[i]; //get maximum data
      if(arr[i] < minimum)
         minimum = arr[i]; //get minimum data
   }
}

void pegionHoleSort(int *arr, int n) {
   int max, min;
   getMaxMin(arr, n, max, min);
   int holeRange = max - min +1;
   list<int> hole[holeRange]; //create an array of holes

   for(int i = 0; i<n; i++) {
      hole[arr[i]-min].push_back(arr[i]);
   }

   int count = 0;
   for(int j = 0; j<holeRange; j++) {
      //delete from linked lists and store to array
      while(!hole[j].empty()) {
         arr[count] = *(hole[j].begin());
         hole[j].erase(hole[j].begin());
         count++;
      }
   }
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int main() {
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;

   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

   cout << "Data before Sorting: ";
   display(arr, n);
   pegionHoleSort(arr, n);
   cout << "Data after Sorting: ";
   display(arr, n);
}
