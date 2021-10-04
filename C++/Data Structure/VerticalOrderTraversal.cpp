// C++ program for printing
// vertical order of a given binary
// tree
#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node *left, *right;
};
 
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Store vertical order
// in map "m", hd = horizontal
// distance, vd = vertical distance
void preOrderTraversal(Node* root,
                       long long int hd,
                       long long int vd,
                       map<long long int,
                       vector<int> >& m)
{
    if (!root)
        return;
    // key = horizontal
    // distance (30 bits) + vertical
    // distance (30 bits) map
    // will store key in sorted
    // order. Thus nodes having same
    // horizontal distance
    // will sort according to
    // vertical distance.
    long long val = hd << 30 | vd;
 
    // insert in map
    m[val].push_back(root->data);
 
    preOrderTraversal(root->left, hd - 1, vd + 1, m);
    preOrderTraversal(root->right, hd + 1, vd + 1, m);
}
 
void verticalOrder(Node* root)
{
    // map to store all nodes in vertical order.
    // keys will be horizontal + vertical distance.
    map<long long int, vector<int> > mp;
 
    preOrderTraversal(root, 0, 1, mp);
 
    // print map
    int prekey = INT_MAX;
    map<long long int, vector<int> >::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (prekey != INT_MAX
            && (it->first >> 30) != prekey) {
            cout << endl;
        }
        prekey = it->first >> 30;
        for (int j = 0; j < it->second.size(); j++)
            cout << it->second[j] << " ";
    }
}
 
// Driver code
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal :- " << endl;
    verticalOrder(root);
    return 0;
}
