#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *searchInBST(Node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (key == root->data)
    {
        return root;
    }

    if (key < root->data)
    {
        return searchInBST(root->left, key);
    }
    //data<key
    return searchInBST(root->right, key);
}

int main()
{

    struct Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (searchInBST(root, 5) == NULL)
    {
        cout << "Key does not exist" << endl;
    }
    else
    {
        cout << "Key exist" << endl;
    }
    return 0;
}