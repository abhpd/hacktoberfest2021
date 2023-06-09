// A CPP program to find
//left voew of a binary tree
#include <bits/stdc++.h>
using namespace std;

/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    vector<int> v;
    queue<Tree*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        int k = sz;
        while (sz--) {
            Tree* top = q.front();
            q.pop();
            if (sz == k - 1) v.push_back(top->val);
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
    }
    return v;
}
