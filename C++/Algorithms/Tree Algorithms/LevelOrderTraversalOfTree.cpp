
// CPP program to construct a binary tree in level order.
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node* left;
	Node* right;
};
struct Node* newNode(int value)
{
	Node* n = new Node;
	n->key = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct Node* insertValue(struct Node* root, int value,
						queue<Node *>& q)
{
	Node* node = newNode(value);
	if (root == NULL)
		root = node;

	else if (q.front()->left == NULL)
		q.front()->left = node;

	else {
		q.front()->right = node;
		q.pop();
	}

	q.push(node);
	return root;
}

// This function mainly calls insertValue() for
// all array elements. All calls use same queue.
Node* createTree(int arr[], int n)
{
	Node* root = NULL;
	queue<Node*> q;
	for (int i = 0; i < n; i++)
	root = insertValue(root, arr[i], q);
	return root;
}

// This is used to verify the logic.
void levelOrder(struct Node* root)
{
	if (root == NULL)
		return;
	queue<Node*> n;
	n.push(root);
	while (!n.empty()) {
		cout << n.front()->key << " ";
		if (n.front()->left != NULL)
			n.push(n.front()->left);
		if (n.front()->right != NULL)
			n.push(n.front()->right);
		n.pop();
	}
}

// Driver code
int main()
{
	int n;
	cout<<"Enter the number of nodes you want to insert : ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Node* root = createTree(arr, n);
	levelOrder(root);
	return 0;
}


/*Sample Input : 

Enter the number of nodes you want to insert : 5
10 20 30 40 50

Sample Output : 10 20 30 40 50
