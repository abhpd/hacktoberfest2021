#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

// #define int long long
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main(){

    priority_queue<int,vector<int>> pq;//MaxHeap

    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<pq.top()<<endl;//3
    pq.pop();
    cout<<pq.top()<<endl;//2
    cout<<endl;
     
    priority_queue<int,vector<int>, greater<int>> pqm;//MinHeap

    pqm.push(2);
    pqm.push(3);
    pqm.push(1);

    cout<<pqm.top()<<endl;//1
    pqm.pop();
    cout<<pqm.top()<<endl;//2
    cout<<endl;

    return 0;
}