#include<bits/stdc++.h>
using namespace std;

int calc(vector<int> v, int l, int r, int x){
    if(l>r){
        return -1;
    }
    if(l==r){
        return ((v[l]==x)?l:-1);
    }
    int m = l+(r-l)/2;
    int val = calc(v, l, m, x);
    if(val!=-1){
        return val;
    }
    return calc(v, m+1, r, x);
}

int main(){
    int n; //Size of array
    cin>>n;
    vector<int> v(n); //Array of numbers
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int x; //Value to search
    cin>>x;
    cout<<"Element present at index: "<<calc(v, 0, n-1, x)<<endl;
    //Returns index of element and -1 if element not present
}
