// including necessary header files.
#include <bits/stdc++.h>
using namespace std;

// segment tree template
template<typename T>
struct segment_tree {
    using F = std::function<T(T, T)>;
    int n;
    T e;
    F f;
    std::vector<T> t;

    // Constructor to initialize the build function.
    segment_tree(const std::vector<T> &a, T e, F f) : n(a.size()), e(e), t(4 * a.size()), f(f) {
        build(a, 1, 0, n - 1);
    }

    // Utility function to build the segment tree.
    void build(const std::vector<T> &a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        }
        else {
            int tm = (tl + tr) / 2;
            build(a, v << 1, tl, tm);
            build(a, v << 1 | 1, tm + 1, tr);
            t[v] = f(t[v << 1], t[v << 1 | 1]);
        }
    }

    // Helper function to compute the answer for queries
    int find_helper(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return e;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return f(find_helper(v << 1, tl, tm, l, min(r, tm)), find_helper(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
    }

    // Utility function to call the find_helper function
    int find(int l, int r) {
        return find_helper(1, 0, n - 1, l, r);
    }

    // Helper function to handle point updates on the segment tree.
    void update_helper(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update_helper(v << 1, tl, tm, pos, val);
            else
                update_helper(v << 1 | 1, tm + 1, tr, pos, val);
            t[v] = f(t[v << 1], t[v << 1 | 1]);
        }
    }

    // Utility function to call the update_helper function
    void update(int pos, int val) {
        update_helper(1, 0, n - 1, pos, val);
    }
};

signed main() {
    // Uncomment the commented lines to get custom input.
    int n = 10;
    // cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++) {
        a[i] = i + 1;
        // cin >> a[i];
    }

    // The following lines of code creates a segment tree for sum queries.
    segment_tree<int> st_sum(a, 0, [&](int x, int y) {
        return x + y;
    });

    // The following lines of code creates a segment tree for min queries.
    segment_tree<int> st_min(a, 1e9, [&](int x, int y) {
        return min(x, y);
    });

    // The following lines of code creates a segment tree for max queries.
    segment_tree<int> st_max(a, -1, [&](int x, int y) {
        return max(x, y);
    });

    cout<<"sum query "<<st_sum.find(0, n - 1)<<'\n';
    cout<<"min query "<<st_min.find(0, n - 1)<<'\n';
    cout<<"max query "<<st_max.find(0, n - 1)<<'\n';

    return 0;
}