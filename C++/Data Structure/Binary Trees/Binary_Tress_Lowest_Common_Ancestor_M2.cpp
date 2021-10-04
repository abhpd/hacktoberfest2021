#include <bits/stdc++.h>
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

Node *LCA2(Node *root, int n1, int n2)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA2(root->left, n1, n2);
    Node *right = LCA2(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return LCA2(root->left, n1, n2);
    }

    if (right != NULL)
    {
        return LCA2(root->right, n1, n2);
    }
}

int main()
{

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->right->left = new Node(5);

    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    int n1 = 7;
    int n2 = 6;
    Node *lca = LCA2(root, n1, n2);

    if (lca == NULL)
    {
        cout << "LCA does not exist" << endl;
    }
    else
    {
        cout << "LCA is: " << lca->data << endl;
    }

    return 0;
}