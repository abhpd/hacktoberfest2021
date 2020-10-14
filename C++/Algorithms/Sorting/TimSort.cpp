#include<bits/stdc++.h> 
using namespace std; 
const int RUN = 32; // we sort pieces of size equal to run, make it power of 2 for best efficiency
  
// This function sorts array of size atmost RUN
void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
  
// Merge function merges the sorted runs
void merge(int arr[], int l, int m, int r) {
    // Original array is broken in two parts
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    // After comparing we merge those arrays
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of left arr
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    // Copy remaining element of right arr
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}

// Timsort main func
void timSort(int arr[], int n) { 
    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN) {
        insertionSort(arr, i, min((i+31), (n-1))); 
    }
    // Start merging from size RUN (or 32) to 64, then 128 and so on
    for (int size = RUN; size < n; size = 2*size) { 
        // pick starting point of left arr. We are merging arr[left..left+size-1] and arr[left+size, left+2*size-1]
        // and after every merge we increase left by *2
        for (int left = 0; left < n; left += 2*size) { 
            // find ending point of left arr and mid+1 is start of right arr
            int mid = left + size - 1; 
            int right = min((left + 2*size - 1), (n-1)); 
            // merge sub array arr[left.....mid] & arr[mid+1....right] 
            merge(arr, left, mid, right); 
        } 
    } 
} 
  
// Prints array 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) {
        printf("%d  ", arr[i]); 
    }
} 
  
// Main function 
int main() { 
    int arr[] = {-2, 7, 3, 0, 22, -13, 62, 5, 7, -7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    printArray(arr, n); //original array
  
    timSort(arr, n); 
  
    printArray(arr, n); //sorted array

    return 0; 
} 