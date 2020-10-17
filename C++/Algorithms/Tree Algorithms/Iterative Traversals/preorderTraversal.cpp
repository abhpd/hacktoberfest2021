#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> preorderTraversal(TreeNode* root) {
        
        stack<TreeNode* > s;
        vector<int>v;
        s.push(root);
        while(!s.empty()){
            TreeNode *t=s.top();
            s.pop();
            if(t){
                v.push_back(t->val);
                s.push(t->right);
                s.push(t->left);
            }
        }
        return v;
    }