// Question: https://cses.fi/problemset/task/1076/

// You are given an array of n integers. Your task is to calculate the median of each window of k elements, from left to right.

// Input
// The first input line contains two integers n and k: the number of elements and the size of the window.
// Then there are n integers x1,x2,…,xn: the contents of the array.

// Output
// Print n−k+1 values: the medians.

#include <bits/stdc++.h> 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree <pair<int, int>, null_type, less<pair<int, int>>,	rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); 

    int n , k;
    cin >> n >> k;
    vector<int> a(n);
    ordered_set os;

    for(int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a[i] = x;
        os.insert({x , i});

        if(i >= k)
        os.erase(os.lower_bound({a[i - k] , 0}));

        if(i >= k - 1)
        cout << (*os.find_by_order((k - 1) / 2)).first << ' ';
    }

}

// Logic : I've used Policy Based Data Sturcture for finding the index efficiently. 
// Ordered Set is a PBDS and by using find_by_order it will returns the value present at that index if it was in a sorted.

