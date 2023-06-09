// CPP program to implement Disjoint Set Union

#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n) {
        iota(begin(par), end(par), 0);                  // initially, set each element as parent of itself
    }
    
    // finds the id which represents the set that an element belongs to
    int find(int x) {
        if(x == par[x]) return x;                       // x is itself the parent of this component
        return par[x] = find(par[x]);                   // update parent of x before returning for each call
    }

    // joins two sets/component into a single set. Returns false if already in same set
    bool Union(int x, int y) {
        int xp = find(x), yp = find(y);                 // find parents of x and y, i.e, representatives of components that x and y belong to
        if(xp == yp) return false;                      // x and y already belong to same component - not possible to union
        if(rank[xp] > rank[yp]) par[yp] = par[xp];      // union by rank - join smaller ranked to bigger one
        else if(rank[yp] > rank[xp]) par[xp] = par[yp];
        else par[xp] = yp, rank[yp]++;                  // same rank - join either to other and increment rank of final parent
        return true;
    }
};

int main() {
    // Your implementation...
    DSU obj(6);
    obj.Union(1, 2);
    obj.Union(2, 3);
    obj.Union(4, 5);
    cout << obj.find(2) << '\n';
}

/*  
    Time Complexity :   O(n*α(n)) ≈ O(n). 
                        n = number of elements
                        Here, α(n) is the inverse Ackermann function. It doesn't exceed 4 for any n < 10600 and hence is practically constant.
    Space Complexity :  O(n)
*/
