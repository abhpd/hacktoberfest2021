#include <bits/stdc++.h>
typedef long long ll;   //to make the code a little short
using namespace std;

struct segTree {
    int size = 1;   //set initial size of tree to be 1
    vector<ll> sums;    //vector for maintaining sums of the segments

    //initialise the segment tree with zeroes
    void init(int n) {
        //make the size of the tree a power of 2 for the sake of easiness
        while(size < n) {
            size *= 2;
        }
        //the maximum size of the vector would be 4n
        //set all the elements to be 0 in the vector
        sums.assign(2*size, 0);
    }

    //build the segment tree from a vector of elements
    void build(vector<ll>& v, int n, int x, int lx, int rx) {
        if(rx-lx == 1) {
            if(lx < n) {
                //check if the element is not out of bounds of the vector
                sums[x] = v[lx];
            }
            return;
        }
        //build the subtrees recursively
        int m = (lx+rx)/2;
        build(v, n, 2*x+1, lx, m);
        build(v, n, 2*x+2, m, rx);
        //calculate the sums of the left and right subtrees
        sums[x] = sums[2*x+1]+sums[2*x+2];
    }

    //for the sake of convenience in the main code
    void build(vector<ll>& v, int n) {
        build(v, n, 0, 0, size);
    }

    //set the element at index i to value v
    void set(int i, ll v, int x, int lx, int rx) {
        // x = root of current subtree, lx and rx are ends of the segment(rx exclusive)
        if(rx-lx == 1) {
            //found the index
            sums[x] = v;
            return;
        }
        int m = (lx+rx)/2;
        if(i < m) {
            //if the index is in the left subtree call same function recursively in the left subtree
            set(i, v, 2*x+1, lx, m);
        } else {
            //if the index is in the right subtree call same function recursively in the right subtree
            set(i, v, 2*x+2, m, rx);
        }
        //calculate the sum of the children nodes
        sums[x] += sums[2*x+1]+sums[2*x+2];
    }

    //for the sake of easy implementation in the main code
    void set(int i, ll v) {
        set(i, v, 0, 0, size);  //call the function from the root of the tree with 0 and size limits
    }

    //get sum of elements from index l to index r-1
    ll getSum(int l, int r, int x, int lx, int rx) {
        if(l >= rx || lx >= r) {
            //check whether the current segment is outside the required segment
            //if yes, then return 0, since adding 0 won't change the result
            return 0;
        }
        if(l <= lx && rx <= r) {
            //check whether the current segment is comletely inside the required segment
            //if yes, then add the sum of this segment to the result
            return sums[x];
        }
        //if none of the above conditions hold true, then call the function recursively on both subtrees
        //and then add and return results of the recursive calls
        int m = (lx+rx)/2;
        return getSum(l, r, 2*x+1, lx, m)+getSum(l, r, 2*x+2, m, rx);
    }

    //for sake of convenience in the main code
    ll getSum(int l, int r) {
        return getSum(l, r, 0, 0, size);
    }
};

int main() {
    int n; cin >> n;    //take input for the size of array
    //take the input of the array/vector of elements
    vector<ll> v(n);
    for(ll& i : v) cin >> i;
    //initialize the segment tree with the size of the vector
    //again the maximum size of the tree vector would 4n
    segTree st; st.init(n);
    //build the segment tree from the elements
    st.build(v, n);
    int m; cin >> m; //Enter the number of queries
    //the query are in the following form:
    //1 i v: set the element at index i to be v
    //2 l r: get the sum of the segment from indices l to r-1
    while(m--) {
        int q; cin >> q;
        if(q == 1) {
            int i; ll val;
            cin >> i >> val;
            //set the element at index i to be v
            st.set(i, val);
        } else {
            int l, r;
            cin >> l >> r;
            //print the sum of the elements from indices l to r-1
            cout << st.getSum(l, r) << "\n";
        }
    }
    return 0;
}
