#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Function: ternary_search
 * @param[in] l   : leftmost element to search from
 * @param[in] r   : righmostmost element to search from
 * @param[in] key : Key to be searched
 * @param[in] arr : Input array of keys
 * Return Value: index of the key or -1 (Key not found)
 */
int ternary_search(int l, int r, int key, int arr[])
{
    if (r >= l) {

        // Find the mid_first and mid_second
        int mid_first = l + (r - l) / 3;
        int mid_second = r - (r - l) / 3;

        // Check if key is present at any mids
        if (arr[mid_first] == key) {
            return mid_first;
        }

        if (arr[mid_second] == key) {
            return mid_second;
        }

        /* Since key is not present at mid, check in which region it is present
         * then repeat the Search operation in that region */
        if (key < arr[mid_first]) {

            // The key lies in between l and mid_first
            return ternary_search(l, mid_first - 1, key, arr);
        }
        else if (key > arr[mid_second]) {

            // The key lies in between mid_second and r
            return ternary_search(mid_second + 1, r, key, arr);
        }
        else {

            // The key lies in between mid_first and mid_second
            return ternary_search(mid_first + 1, mid_second - 1, key, arr);
        }
    }

    // Key not found
    return -1;
}


int main()
{
    int key, idx;

    // Get the sorted array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // length of array
    int len = sizeof(arr)/sizeof(arr[0]);;

    /* Case 1: Search a valid key */
    key = 5;
    idx = ternary_search(0, len, key, arr);
    cout << "Index of " << key << " is " << idx << endl;

    /* Case 2: Search an invalid key */
    key = 50;
    idx = ternary_search(0, len, key, arr);

    // Print the result
    cout << "Index of " << key << " is " << idx << endl;
}
