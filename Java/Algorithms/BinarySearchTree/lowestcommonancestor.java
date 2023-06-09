
static TreeNode lca(TreeNode root,int d1,int d2){
    if(root.val> d1 && root.val>d2){
        return lca(root.left,d1,d2);
    }
    else if(root.val <d1 && root.val<d2){
        return lca(root.right,d1,d2);
    }
    return root;
}