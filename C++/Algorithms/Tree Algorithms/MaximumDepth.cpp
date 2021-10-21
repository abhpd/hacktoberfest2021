// A recursive CPP program to find
// Maximum Depth of a Binary Tree.
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left, *right;
};


int maxDepth(node* root) {
        if(root == NULL) return NULL;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l,r) + 1;
    }


node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return(Node);
}

/* Driver code*/
int main()
{

	node *root = newNode(20);
	root->left = newNode(8);
	root->right = newNode(22);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	
	cout<<maxDepth(root)<<endl;


	return 0;
}

