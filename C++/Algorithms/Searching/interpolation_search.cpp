#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
 * Function: interpolation_search
 * @param[in] len : length of an array
 * @param[in] key : Key to be searched
 * @param[in] arr : Input array of keys
 * Return Value: index of the key or -1 (Key not found)
 */
int interpolation_search(int len, int key, int arr[])
{
    // Find indexes of two corners
    int st = 0, end = (len - 1);

    while (st <= end && key >= arr[st] && key <= arr[end])
    {
        if (st == end)
        {
            if (arr[st] == key) return st;
            return -1;
        }

        int pos = st + (((double)(end - st) / (arr[end] - arr[st])) * (key - arr[st]));

        if (arr[pos] == key)
            return pos;

        // If key is larger, key is in upper part
        if (arr[pos] < key)
            st = pos + 1;

        // If key is smaller, key is in the lower part
        else
            end = pos - 1;
    }
    return -1;
}


int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int len = sizeof(arr) / sizeof(arr[0]);

    int key = 6;
    int idx = interpolation_search(len, key, arr);
    
    // If element was found
    if (idx != -1)
        cout << "Index of " << key << " is " << idx << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
