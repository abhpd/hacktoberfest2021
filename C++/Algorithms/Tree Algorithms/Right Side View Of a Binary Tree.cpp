// Problem : Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Code :
 void solve(TreeNode* root,int level,vector<int>&res)
    {
        if(root==NULL)
            return ;
        
        if(res.size()==level)
            res.push_back(root->val);
        
        solve(root->right,level+1,res);
        solve(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        solve(root,0,res);
        return res;
    }
