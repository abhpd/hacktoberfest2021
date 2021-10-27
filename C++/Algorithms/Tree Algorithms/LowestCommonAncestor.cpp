 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       if we have one less than one greater than root the obvious thats the ancestor so this way we are finding ancestor
if(root->val>p->val&&root->val>q->val)return lowestCommonAncestor(root->left,  p, q);
 else if(root->val<p->val&&root->val<q->val)return lowestCommonAncestor(root->right,p,q);
  return root;  
    }
