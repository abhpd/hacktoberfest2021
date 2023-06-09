using namespace std;

struct TreeNode {
  TreeNode *left,*right;
  int val;
  TreeNode(int x){
    val=x;
    left=right=null;
  }
};
bool helper(TreeNode *root,TreeNode* min, TreeNode* max){
        if(!root){
            return true;
        }
        if(min&&root->val<=min->val){
            return false;
        }
        if(max&&root->val>=max->val){
            return false;
        }
        return helper(root->left,min,root)&&helper(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }

int main(){
  //call isValidBST()
}
