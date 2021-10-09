#include <iostream>
using namespace std;
 
// Structure Node to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Function to print all nodes of a given level from left to right
bool printLevel(Node* root, int level)
{
    if (root == nullptr)
        return false;
 
    if (level == 1)
    {
        cout << root->key << " ";
 
        // return true if at least one node is present at a given level
        return true;
    }
 
    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);
 
    return left || right;
}
 
// Function to print level order traversal of a given binary tree
void levelOrderTraversal(Node* root)
{
    // start from level 1 — till the height of the tree
    int level = 1;
 
    // run till `printLevel()` returns false
    while (printLevel(root, level)) {
        level++;
    }
}
 
int main()
{
    Node* root = new Node(45);
    root->left = new Node(34);
    root->right = new Node(61);
    root->left->left = new Node(18);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
 
    levelOrderTraversal(root);
 
    return 0;
}