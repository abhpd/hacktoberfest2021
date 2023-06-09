#include<bits/stdc++.h>
using namespace std;

// O(n) time complexity
void bucket_sort(float arr[], int n) {
    vector<float> bucket[10];
    
    int maxm = *max_element(arr, arr+n);
    int divisor = ceil((float)(maxm+1) / 10);
 
    for(int i=0; i<n; i++) {
        int idx = arr[i] / divisor;
        bucket[idx].push_back(arr[i]);
    }

    for(int i=0; i<n; i++)
        sort(bucket[i].begin(), bucket[i].end());
 
    int index = 0;
    for(int i=0; i<10; i++) {
        for (int j = 0; j < bucket[i].size(); j++) {
            arr[index++] = bucket[i][j];
        }
    }

    return;
}


int main() {
    cout << "Enter the size of the array" << endl;
    int n; cin>>n; 

    cout << "Enter the elements in the array" << endl;
    float arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"Before Sorting - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    
    bucket_sort(arr, n);

    cout<<"After Bucket Sort - ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    // solve();
}