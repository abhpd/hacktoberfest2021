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
vector<int> postorderTraversal(TreeNode* root) {
        
        //Do a preorder traversal
        // Preorder:Root left Right
        // Postorder : Left right root
        //Preorder -> Root right left mei nikale and reverse
        
        stack<TreeNode*>  s;
        s.push(root);
        TreeNode *temp;
        vector<int>v;
        while(!s.empty()){
            temp=s.top();
            s.pop();
            if(temp){
                v.push_back(temp->val);
                s.push(temp->left);
                s.push(temp->right);
            }
        }
        reverse(v.begin(),v.end());
        return v;
    }