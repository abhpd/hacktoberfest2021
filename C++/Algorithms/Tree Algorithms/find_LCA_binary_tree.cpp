/* C++ program to find LCA of n1 and n2 using one traversal of Binary Tree.

   It handles all cases even when n1 or n2 is not there in Binary Tree */
#include <iostream>

using namespace std;
 
// A Binary Tree Node

struct Node
{

    struct Node *left, *right;

    int key;
};
 
// Utility function to create a new tree Node

Node* newNode(int key)
{

    Node *temp = new Node;

    temp->key = key;

    temp->left = temp->right = NULL;

    return temp;
}
 
// This function returns pointer to LCA of two given values n1 and n2.
// v1 is set as true by this function if n1 is found
// v2 is set as true by this function if n2 is found

struct Node *findLCAUtil(struct Node* root, int n1, int n2, bool &v1, bool &v2)
{

    // Base case

    if (root == NULL) return NULL;
 

    // If either n1 or n2 matches with root's key, report the presence

    // by setting v1 or v2 as true and return root (Note that if a key

    // is ancestor of other, then the ancestor key becomes LCA)

    if (root->key == n1)

    {

        v1 = true;

        return root;

    }

    if (root->key == n2)

    {

        v2 = true;

        return root;

    }
 

    // Look for keys in left and right subtrees

    Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);

    Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);
 

    // If both of the above calls return Non-NULL, then one key

    // is present in once subtree and other is present in other,

    // So this node is the LCA

    if (left_lca && right_lca)  return root;
 

    // Otherwise check if left subtree or right subtree is LCA

    return (left_lca != NULL)? left_lca: right_lca;
}
 
// Returns true if key k is present in tree rooted with root

bool find(Node *root, int k)
{

    // Base Case

    if (root == NULL)

        return false;
 

    // If key is present at root, or in left subtree or right subtree,

    // return true;

    if (root->key == k || find(root->left, k) ||  find(root->right, k))

        return true;
 

    // Else return false

    return false;
}
 
// This function returns LCA of n1 and n2 only if both n1 and n2 are present
// in tree, otherwise returns NULL;

Node *findLCA(Node *root, int n1, int n2)
{

    // Initialize n1 and n2 as not visited

    bool v1 = false, v2 = false;
 

    // Find lca of n1 and n2 using the technique discussed above

    Node *lca = findLCAUtil(root, n1, n2, v1, v2);
 

    // Return LCA only if both n1 and n2 are present in tree

    if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))

        return lca;
 

    // Else return NULL

    return NULL;
}
 
// Driver program to test above functions

int main()
{

    // Let us create binary tree given in the above example

    Node * root = newNode(1);

    root->left = newNode(2);

    root->right = newNode(3);

    root->left->left = newNode(4);

    root->left->right = newNode(5);

    root->right->left = newNode(6);

    root->right->right = newNode(7);

    Node *lca =  findLCA(root, 4, 5);

    if (lca != NULL)

       cout << "LCA(4, 5) = " << lca->key;

    else

       cout << "Keys are not present ";
 

    lca =  findLCA(root, 4, 10);

    if (lca != NULL)

       cout << "nLCA(4, 10) = " << lca->key;

    else

       cout << "nKeys are not present ";
 

    return 0;
}
