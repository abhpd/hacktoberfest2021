#include<bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int n, int exp) {
    int output[n], i;
    int count[10] = {0};
    
    for(i=0; i<n; i++)
        count[(arr[i] / exp) % 10]++;

    for(i=1; i<10; i++)
        count[i] += count[i - 1];
 
    for (i=n-1; i>=0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for(i = 0; i<n; i++)
        arr[i] = output[i];
}

// O(n) time complexity
void radix_sort(int arr[], int n) {
    int m = *max_element(arr, arr+n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        counting_sort(arr, n, exp);
}



int main() {
    cout << "Enter the size of the array" << endl;
    int n; cin>>n; 

    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"Before Sorting - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    radix_sort(arr, n);

    cout<<"After Radix Sort - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    // solve();
}

// 170, 45, 75, 90, 802, 24, 2, 66