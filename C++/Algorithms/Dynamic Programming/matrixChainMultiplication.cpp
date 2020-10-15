#include<bits/stdc++.h>
using namespace std;

int t[10001][10001];
int MCM(vector<int> &arr, int i, int j){
    if(i + 1 >= j){
        return 0;
    }
    if(t[i][j] != -1)
        return t[i][j];
    int mn = INT_MAX;
    for(int k = i + 1; k <= j - 1; k++){
        mn = min(mn, (MCM(arr, i, k) + MCM(arr, k, j) + arr[i] * arr[k] * arr[j]));
    }
    return t[i][j] = mn;
}

int main(){
    memset(t, -1, sizeof(t));
    vector<int> arr = {40, 20, 30, 10, 30};     // 26000
    vector<int> arr2 = {10, 30, 5, 60};         // 4500
    // cout<<MCM(arr, 0, arr.size() - 1)<<"\n";
    cout<<MCM(arr2, 0, arr2.size() - 1)<<"\n";
    return 0;
}


