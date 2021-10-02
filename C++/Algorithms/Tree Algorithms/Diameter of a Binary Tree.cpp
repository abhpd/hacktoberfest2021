/*

Problem : Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

*/

// Code :

 int diameter(TreeNode* root, int &d)
    {
        if(root==NULL)
            return 0;
        
        int lh=diameter(root->left,d);
        int rh=diameter(root->right,d);
        
        d=max(d,lh+rh);
        
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        diameter(root,d);
        return d;
    }
