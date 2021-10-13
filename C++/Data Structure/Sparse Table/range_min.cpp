// template to implement sparse table for finding minimum in a range 
// the user input is stored in "vector<int> dataVector"
// a global sparse table is built on dataVector

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
typedef long double ld;
const int INF = int(1e9);
const int MAX_N = 1000005;

int sparse_table[MAX_N][25];

// function to build sparse table
void build(vector<int> dataVector){
    int N = dataVector.size();
    for(int L = N-1; L>=0; L--){
        for(int W=0; W<25; W++){
            int R = L + (1<<W) - 1;
            if(R>=N) break;
            if(W == 0) sparse_table[L][W] = dataVector[L];
            else sparse_table[L][W] = min(sparse_table[L][W-1], sparse_table[L+(1<<(W-1))][W-1]);
        }
    }
}

// function to find log base 2 of a number efficiently (can use inbuilt functions as well)
int log_table[MAX_N];
void build_log_table(int N){
    log_table[1] = 0;
    for(int i=2; i<=N; i++){
        log_table[i] = 1+log_table[i/2];
    }
}

// function to query from sparse table (min in range L to R)
int query(int l, int r){
    int W = r-l;
    int power = log_table[W];
    return min(sparse_table[l][1<<power], sparse_table[r-(1<<power)][1<<power]);
}