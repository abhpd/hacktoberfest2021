package com.datastructures;

public class SmallestLetter {

  static char findSmallestGreater(char[] arr, char target) {
    int start = 0, end = arr.length - 1;
    while (start <= end) {
      if (target >= arr[arr.length - 1]) return arr[0];
      int mid = start + (end - start) / 2;
      if (target < arr[mid]) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return arr[start];
  }

  public static void main(String[] args) {
    char[] arr = {'c', 'f', 'j'};
    System.out.println(findSmallestGreater(arr, 'f'));
  }
}
