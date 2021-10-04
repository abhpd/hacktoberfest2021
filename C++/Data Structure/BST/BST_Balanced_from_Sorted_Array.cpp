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

Node *sortedArrayToBST(int arr[], int start, int end)
{

    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

void printPreorder(struct Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    Node *root = sortedArrayToBST(arr, 0, 4);

    printPreorder(root);
    cout << endl;

    return 0;
}