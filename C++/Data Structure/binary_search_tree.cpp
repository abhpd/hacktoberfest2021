#include<iostream>
using namespace std;

/* 

    Binary Search Tree:-
        The left subtree of a node contains  only nodes with keys lesser than the node’s key.
        The right subtree of a node contains only nodes with keys greater than the node’s key.
        The left and right subtree each must also be a binary search tree. 
        There must be no duplicate nodes.

*/

// object of this class represent a node in the tree
class TreeNode {

    public:
        int val;
        TreeNode *left,*right;

        //constructor 
        TreeNode(int val) {
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

TreeNode *insert(TreeNode *root, int key) {

    // if root is null then return the new node 
    if(!root) return new TreeNode(key);

    // if the new key is less than root node then it will add in the left subtree.
    if(key < root->val) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

TreeNode *successor(TreeNode *root) {
    TreeNode* curr = root;

    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

TreeNode *deleteNode(TreeNode *root, int key) {

    if(!root) return root;
    // if key is less than root value then call recursively in left subtree
    if(key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    // if key is greater than root value then call recursively in right subtree
    else if(key > root->val){
        root->right = deleteNode(root->right, key);
    }

    // if the key found
    else {

        // if the left and right node is null then simply delete it.
        if(!root->left and !root->right) {
            return NULL;
        }
        // if node has only one child (right)
        else if(!root->left) {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        // if node has only one child (left)
        else if(!root->right) {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        //if node has both children
        else {
            /* 
                we have to find inorder successor of the node that we want to delete.
                inorder successor -> smallest valued node in the right subtree.
            */
            TreeNode *succ = successor(root->right);

            //copy the value of the succssor to this node

            root->val = succ->val;
            
            // delete the successor
            root->right = deleteNode(root->right, succ->val);

        }
    }
    return root;
}

TreeNode *search(TreeNode *root, int key) {

    if(root->val == key or !root) return root;

    if(key < root->val) return search(root->left, key);

    return search(root->right, key);
}

// inorder traversal of the BST always print node values in sorted order
void inorder(TreeNode *root) {

    if(!root) {
        return ;
    }

    inorder(root->left);
    // you can store these values in an array as well
    cout<<root->val<<" ";
    inorder(root->right);

}
int main() {

    TreeNode* root = NULL;

    int arr[9] = {20, 15, 40, 9, 18, 35, 60, 17, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<n; i++) {
        root = insert(root, arr[i]);
    }

    inorder(root);

    TreeNode *temp = search(root, 20);

    if(temp == NULL) {
        cout<<"Node not present"<<endl;
    }
    else {
        cout<<"Node present"<<endl;
    }

    temp = deleteNode(root, 17);

    inorder(root);


}
