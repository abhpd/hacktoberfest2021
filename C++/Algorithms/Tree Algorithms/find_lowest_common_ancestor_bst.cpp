// A recursive CPP program to find
// LCA of two nodes n1 and n2.
#include <bits/stdc++.h>
using namespace std;

class node
{
	public:
	int data;
	node* left, *right;
};


struct node *lca(struct node* root, int n1, int n2)
{
	while (root != NULL)
	{
		if (root->data > n1 && root->data > n2)
		root = root->left;

		else if (root->data < n1 && root->data < n2)
		root = root->right;

		else break;
	}
	return root;
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

	int n1 = 10, n2 = 14;
	node *t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data<<endl;

	n1 = 14, n2 = 8;
	t = lca(root, n1, n2);
	cout<<"LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

	n1 = 10, n2 = 22;
	t = lca(root, n1, n2);
	cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
	return 0;
}

