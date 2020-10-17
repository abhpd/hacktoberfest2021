//Diameter of Binary Tree
//C++ Program 
//Time Complexity O(n)
//The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.
#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
	int data; 
	Node* left, *right; 
}; 

//find the height of the tree
int height(Node* root, int& ans) 
{ 
	if (root == NULL) 
		return 0; 
	int left_height = height(root->left, ans); 
    int right_height = height(root->right, ans); 
    //diameter of the tree = max(leftheight, rightheight)+1
	ans = max(ans, 1 + left_height + right_height); 
    return 1 + max(left_height, right_height); 
} 

int diameter(Node* root) 
{ 
	if (root == NULL) 
		return 0; 
	int ans = INT_MIN;
	int height_of_tree = height(root, ans); 
	return ans; 
} 

struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 

	return (node); 
} 

// main function to test the code 
int main() 
{ 
	struct Node* root = newNode(5); 
	root->left = newNode(4); 
	root->right = newNode(3); 
	root->left->left = newNode(2); 
	root->left->right = newNode(1); 

	printf("Diameter is %d\n", diameter(root)); 

	return 0; 
} 
// output comes to be 4
