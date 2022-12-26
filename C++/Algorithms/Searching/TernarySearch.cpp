/*    * Time Complexity *
---> O(log3 n)  where n is the size of the array
    
    * Space Complexity *
---> O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int ternarySearch(int l, int r, int key, int ar[]) {
  if (r >= l) {

    int mid1 = l + (r - l) / 3;
    int mid2 = r - (r - l) / 3;

    if (ar[mid1] == key) {
      return mid1;
    }
    if (ar[mid2] == key) {
      return mid2;
    }
    if (key < ar[mid1]) {
      return ternarySearch(l, mid1 - 1, key, ar);
    } else if (key > ar[mid2]) {
      return ternarySearch(mid2 + 1, r, key, ar);
    } else {
      return ternarySearch(mid1 + 1, mid2 - 1, key, ar);
    }
  }
  return -1;
}

int main() {
  int n, l, r, p, key;
  cin >> n;
  int * ar = new int[n];

  // taking input array
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }

  cout << "enter key ";
  cin >> key;

  l = 0;
  r = n;
  cout << r;

  p = ternarySearch(l, r, key, ar);

  // Print the result
  cout << "Index of " << key << " is " << p << endl;

}
