// Finds whether an input array has a subset with the required sum or not using dynamic programming

#include <bits/stdc++.h>
using namespace std;

// Checks if any subset gives the required subset sum
bool subsetsum(vector<int> a, int n, int s){
    bool subs[n+1][s+1];

    // sum is zero
    for(int i=0; i<n; i++)
        subs[i][0] = true;
    // There are zero elements in array
    for(int i=0; i<s; i++)
        subs[0][i] = false;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            if(j < a[i-1])
                subs[i][j] = subs[i-1][j];
            else    
                subs[i][j] = subs[i-1][j] || subs[i-1][j-a[i-1]];
        }
    }
    return subs[n][s];
}

int main(){
    int n, sum;
    cout << "Please enter the size of array and the subset sum: ";
    cin >> n >> sum;
    cout << endl;
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << endl;
    if(subsetsum(arr, n, sum))
        cout << "Subset exists." << endl;
    else    
        cout << "No such subset exists." << endl;
}