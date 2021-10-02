//Link to the problem: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx=0;
    unordered_map<int,int> mp;
    TreeNode *solve(vector<int>& post, vector<int>& ino,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode *root=new TreeNode(post[idx]);
        int j=mp[post[idx]];
        idx--;
        root->right=solve(post,ino,j+1,end);
        root->left=solve(post,ino,start,j-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
        idx=post.size()-1;
        
        for(int i=0;i<ino.size();i++)
            mp[ino[i]]=i;
        return solve(post,ino,0,post.size()-1);
    }
};