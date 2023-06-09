#include "bits/stdc++.h"
using namespace std;

// This sorting technique is useful only when the array is within a range of 0 to 1.

void bucketSort(float arr[], int n)
{
    vector<float> b[n];
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++){
        sort(b[i].begin(), b[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < b[i].size(); j++){
            arr[index++] = b[i][j];
        }
    }
}

int main()
{
    float arr[] = { 0.999, 0.235, 0.88, 0.456, 0.330, 0.780 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}