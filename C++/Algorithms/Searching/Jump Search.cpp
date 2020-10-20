// C++ program to implement Jump Search 
  
#include <bits/stdc++.h> 
using namespace std; 
  
int jumpSearch(int arr[], int x, int n) 
{ 
    // Finding block size to be jumped 
    int step = sqrt(n); 
  
    // Finding the block where element is 
    // present (if it is present) 
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
  
    // Doing a linear search for x in block 
    // beginning with prev. 
    while (arr[prev] < x) 
    { 
        prev++; 
  
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, n)) 
            return -1; 
    } 
    // If element is found 
    if (arr[prev] == x) 
        return prev; 
  
    return -1; 
} 
  
// Driver program to test function 
int main() 
{ 
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
    int x = 55; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
    // Find the index of 'x' using Jump Search 
    int index = jumpSearch(arr, x, n); 
  
    // Print the index where 'x' is located 
    cout << "\nNumber " << x << " is at index " << index; 
    return 0; 
} 
  
// Contributed by nuclode 

Output:

Number 55 is at index 10
  
/*Time Complexity : O(√n)
Auxiliary Space : O(1)

Works only sorted arrays.
The optimal size of a block to be jumped is (√ n). This makes the time complexity of Jump Search O(√ n).
The time complexity of Jump Search is between Linear Search ( ( O(n) ) and Binary Search ( O (Log n) ).
Binary Search is better than Jump Search, but Jump search has an advantage that we traverse back only once
(Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the smallest element or smaller than the smallest). 
So in a system where binary search is costly, we use Jump Search.
*/
