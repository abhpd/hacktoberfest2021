// Problem : Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level 
// and alternate between).

// Code :

vector<vector<int>>ZigZag(TreeNode* root)
{
    vector<vector<int>order;
    if(root==NULL)
    return order;
    
    queue<TreeNode*>q;
    q.push(root);
    bool LeftToRight=true;

    while(!q.empty())
    {
        int sz=q.size();
        vector<int>v(sz);
        while(sz--)
        {
            TreeNode* node=q.front();
            q.poo();

            int index=LeftToRight?i:(sz-i-1);
            v[index]=node->val;

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);
        }
        LeftToRight=!LeftToRight;
        order.push_back(v);
    }
return order;
}
