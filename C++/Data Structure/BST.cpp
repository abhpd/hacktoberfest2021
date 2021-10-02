// Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
	int data;
	Node* left;
	Node* right;
public:
	Node(int x) {
		this->data = x;
		left = NULL;
		right = NULL;
	}

	bool search(Node* root, int x) {
		// base case
		if (root == NULL)return false;

		if (root->data == x)return true;
		else if (root->data < x)search(root->right, x);
		else search(root->left, x);
	}

	Node* insert(Node* root, int x) {
		// base case
		if (root == NULL) {
			Node* temp = new Node(x);
			return temp;
		}

		if (root->data < x)root->right = insert(root->right, x);
		else if (root->data > x)root->left = insert(root->left, x);

		return root;
	}
	// left most leaf of right child
	Node* getSuccessor(Node* root) {
		Node* curr = root->right;
		while (curr->left != NULL)curr = curr->left;
		return curr;
	}

	Node* deleteNode(Node* root, int x) {
		//base case
		if (root == NULL)return root;
		if (root->data == x) {
			// no child
			if (!root->left and !root->right) {
				delete root;
				return NULL;
			}
			// only right child
			else if (!root->left) {
				Node* temp = root->right;
				delete root;
				return temp;
			}
			// only left child
			else if (!root->right) {
				Node* temp = root->left;
				delete root;
				return temp;
			}
			// both child
			else {
				Node* temp = getSuccessor(root);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
				return root;
			}
		}

		else if (root->data < x)root->right = deleteNode(root->right, x);
		else root->left = deleteNode(root->left, x);
		return root;
	}
};

int main() {

	Node * root = new Node(5);

	cout << root->search(root, 10) << "\n";
	root->insert(root, 10);
	root->insert(root, 20);
	root->insert(root, 2);
	root->insert(root, 4);
	root->insert(root, 8);
	root->deleteNode(root, 5);
	cout << "20 " << root->search(root, 20) << "\n";
	cout << "5 " << root->search(root, 5) << "\n";

	return 0;
}