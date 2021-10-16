/*
 * problem: Longest Increasing subsequence, Greey vairant
 * works in O(n logn) time
 * extra space utilized in storing the LIS.
 * Example
 * Input: arr[] = {3, 10, 2, 1, 20}
 * Output: Length of LIS = 3
 * The longest increasing subsequence is 3, 10, 20
 *
 */

import java.util.*;

class LongestIncreasingSubsequence {
  static void reconstruct_print(int end, int[] a, int[] p) {
    int x = end;
    Stack<Integer> s = new Stack();
    for (; p[x] >= 0; x = p[x])
      s.push(a[x]);
    System.out.printf("[%d", a[x]);
    for (; !s.isEmpty(); s.pop())
      System.out.printf(", %d", s.peek());
    System.out.printf("]\n");
  }

  public static void main(String[] args) {
    final int MAX_N = 100000;

    int n = 11;
    int[] arr = new int[] { -7, 10, 9, 2, 3, 8, 8, 1, 2, 3, 4 };
    int[] trackIndex = new int[MAX_N], parent = new int[MAX_N];
    Vector<Integer> trackElement = new Vector<Integer>();

    int lis = 0, lis_end = 0;
    for (int i = 0; i < n; ++i) {
      int pos = Collections.binarySearch(trackElement, arr[i]);

      if (pos < 0)
        pos = -(pos + 1); // some adjustments are needed

      /*
       * means that current element has greatest value, no element of this value was
       * present means that we have a better value now, HOW? previous array: 1, 4, 5 |
       * upcoming element is : 2 New array: 1, 2, 5
       */

      if (pos >= trackElement.size())
        trackElement.add(arr[i]);
      else
        trackElement.set(pos, arr[i]);

      trackIndex[pos] = i;

      /*
       * To keep track of previous smaller element, so that we can generate sequence
       * later on.
       */
      parent[i] = pos > 0 ? trackIndex[pos - 1] : -1;

      if (pos + 1 > lis) {
        lis = pos + 1;
        lis_end = i;
      }

      System.out.printf("Considering element A[%d] = %d\n", i, arr[i]);
      System.out.printf("LIS ending at A[%d] is of length %d: ", i, pos + 1);
      reconstruct_print(i, arr, parent);
      System.out.println("L is now: " + trackElement);
      System.out.printf("\n");
    }

    /* Size of the final Longest Increasing subsequence */
    System.out.printf("Final LIS is of length %d: ", lis);
    /* Generating finalise longet increasing subsequence */
    reconstruct_print(lis_end, arr, parent);
  }
}
