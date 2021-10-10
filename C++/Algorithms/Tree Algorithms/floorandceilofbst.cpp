#include <iostream>
#include <iomanip>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Recursive function to find the floor and ceil of a given key in a BST.
// Note that floor and ceil are passed by reference to the function
void findFloorCeil(Node* root, Node* &floor, Node* &ceil, int key)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // if a node with the desired value is found, both floor and ceil is equal
    // to the current node
    if (root->data == key)
    {
        floor = root;
        ceil = root;
    }
 
    // if the given key is less than the root node, recur for the left subtree
    else if (key < root->data)
    {
        // update ceil to the current node before recursing in the left subtree
        ceil = root;
        findFloorCeil(root->left, floor, ceil, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        // update floor to the current node before recursing in the right subtree
        floor = root;
        findFloorCeil(root->right, floor, ceil, key);
    }
}
 
int main()
{
    /* Construct the following tree
               8
             /   \
            /     \
           4       10
          / \     /  \
         /   \   /    \
        2     6 9     12
    */
 
    int keys[] = { 2, 4, 6, 8, 9, 10, 12 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // calculate the ceil and floor for each key
    for (int i = 0; i < 15; i++)
    {
        Node *floor = nullptr, *ceil = nullptr;
        findFloorCeil(root, floor, ceil, i);
 
        cout << setw(2) << i << " —> ";
        cout << setw(4) << (floor? floor->data: -1);
        cout << setw(4) << (ceil? ceil->data: -1) << endl;
    }
 
    return 0;
}