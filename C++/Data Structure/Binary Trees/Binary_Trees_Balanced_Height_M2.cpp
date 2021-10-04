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

bool isBalanced(Node *root, int *height)
{

    int lh = 0, rh = 0;

    if (root == NULL)
    {
        return true;
    }

    if (isBalanced(root->left, &lh) == false)
    {
        return false;
    }
    if (isBalanced(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);

    int height = 0;
    if (isBalanced(root1, &height))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }

    if (isBalanced(root2, &height))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Unbalanced Tree" << endl;
    }
    return 0;
}