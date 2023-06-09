// Problem : Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// Note : The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the
// rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Code :

vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        //nodes[vertical]=[level,values in that level]
         map<int,map<int,multiset<int>>>nodes;
        //q={node,its horizontal level,its vertical level}
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int vertical=p.second.first;
            int level=p.second.second;
            
            nodes[vertical][level].insert(node->val);
            
            if(node->left)
            q.push({node->left,{vertical-1,level+1}});
            
            if(node->right)
            q.push({node->right,{vertical+1,level+1}});
        }
        
        for(auto p : nodes)
        {
            vector<int>col;
            for(auto q : p.second)
            {
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
