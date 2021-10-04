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

//case1
void printSubtreeNodes(Node *root, int K)
{

    if (root == NULL || K < 0)
    {
        return;
    }

    if (K == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtreeNodes(root->left, K - 1);
    printSubtreeNodes(root->right, K - 1);
}

//case2
int printNodesAtK(Node *root, Node *target, int K)
{

    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printSubtreeNodes(root, K);
        return 0;
    }

    int dl = printNodesAtK(root->left, target, K);
    if (dl != -1)
    {
        if (dl + 1 == K)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->right, K - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printNodesAtK(root->right, target, K);
    if (dr != -1)
    {
        if (dr + 1 == K)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubtreeNodes(root->left, K - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    printNodesAtK(root, root->left, 1);

    return 0;
}