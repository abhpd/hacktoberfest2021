// Leetcode question  : Flatten Binary Tree to Linked List  (https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
// Code : 

class Solution {
public:
    
    void flatten(TreeNode* root) {
        if(!root) return;
       
        if(root == NULL || root->left == NULL && root->right == NULL) return;
        
        if(root->left != NULL){
            flatten(root->left);
            TreeNode* tmp = root->right;
            root->right = root->left;
            root->left = NULL;

            TreeNode* t = root->right;
            while(t->right != NULL){
                t = t->right;
            }
            t->right = tmp; 
        }
            
        flatten(root->right);
        return;
    }
};
