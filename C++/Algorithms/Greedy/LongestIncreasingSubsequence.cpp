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

#include <bits/stdc++.h>
using namespace std;

void print_array(const char *s, const vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    if (i)
      cout << ", ";
    else
      cout << s << ": [";
    cout << arr[i];
  }
  printf("]\n");
}

void reconstruct_print(int lis_end, const vector<int> &arr,
                       const vector<int> &parent) {
  int x = lis_end;
  stack<int> st;
  for (; parent[x] >= 0; x = parent[x])
    st.push(arr[x]);

  cout << "[" << arr[x];
  for (; !st.empty(); st.pop())
    cout << ", " << st.top();

  cout << "]\n";
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto &i : arr)
    cin >> i;

  vector<int> trackNum, trackIndex, parent(2 * arr.size(), 0);

  /*to track upto where parent is filled. */
  int lis_end = 0;

  for (int i = 0; i < n; ++i) {

    /* for strictly increasing sequence use lower_bound */
    int pos = upper_bound(trackNum.begin(), trackNum.end(), arr[i]) -
              trackNum.begin();

    if (pos >= trackNum.size()) {
      /* means that current element has greatest value, no element of this value
       * was present */
      trackNum.push_back(arr[i]);
      trackIndex.push_back(i);
      lis_end = max(lis_end, i);
    } else {
      /* means that we have a better value now, HOW? */
      /* previous array: 1, 4, 5 | upcoming element is : 2 */
      /* New array: 1, 2, 5 */
      trackNum[pos] = arr[i];
      trackIndex[pos] = i;
    }

    /* To keep track of previous smaller element, so that we can generate
     * sequence later on. */
    parent[i] = pos ? trackIndex[pos - 1] : -1;

    cout << "Considering element A[" << i << "] "
         << " = " << arr[i] << '\n';
    cout << "LIS ending at A[" << i << "] is of length: " << pos + 1;
    reconstruct_print(i, arr, parent);
    print_array("L is now", trackNum);
    cout << '\n';
  }

  /* Size of the final Longest Increasing subsequence */
  cout << "Size of LIS: " << trackNum.size() << '\n';

  /* Generating finalise longet increasing subsequence */
  cout << "final LIS is : ";
  reconstruct_print(lis_end, arr, parent);
}
