/*
 * This file contains the recursive and iterative traversals (inorder, preorder and postorder)
 * of a binary tree
*/
#include <bits/stdc++.h>
using namespace std;

// structure definition for the Node
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* TreeNode;

// Function to create a new node
TreeNode newNode(int value){
    TreeNode root = (TreeNode)malloc(sizeof(struct Node));
    root->data = value;
    root->left = NULL;
    root->right = NULL;
    return (root);
}
/*------------------RECURSIVE IMPLEMENTATION----------------------*/

// recursive function for inorder traversal
void recursiveInOrder(TreeNode root, vector<int> &result){
    if(root == NULL)
        return;
    else
    {
        // recursively call the left subtree
        recursiveInOrder(root->left, result);
        // push the value of the root in the result vector
        result.push_back(root->data);
        // recursively call the right subtree
        recursiveInOrder(root->right, result);
    }
}

// recursive function for preorder traversal
void recursivePreOrder(TreeNode root, vector<int> &result){
    if(root == NULL)
        return;
    else
    {
        // recursively call the left subtree
        recursivePreOrder(root->left, result);
        // push the value of the root in the result vector
        result.push_back(root->data);
        // recursively call the right subtree
        recursivePreOrder(root->right, result);
    }
}

// recursive function for postorder traversal
void recursivePostOrder(TreeNode root, vector<int> &result){
    if(root == NULL)
        return;
    else
    {
        // recursively call the left subtree
        recursivePostOrder(root->left, result);
        // push the value of the root in the result vector
        result.push_back(root->data);
        // recursively call the right subtree
        recursivePostOrder(root->right, result);
    }
}

/*------------------ITERATIVE IMPLEMENTATION----------------------*/

void iterativeInOrder(TreeNode root, vector<int> &result)
{
    // if the tree is empty or is not present, then return
    if(root == NULL)
        return;

	// Create an empty stack.
	stack<TreeNode> stack;
	
    // Start from the root node.
	TreeNode curr = root;

	// If the current node is NULL and stack is also empty, then terminate the program
	while (!stack.empty() || curr != NULL)
	{
    // Push the current node to the stack and set curr = curr->left.
		if (curr != NULL)
		{
			stack.push(curr);
			curr = curr->left;
		}
		else // If the curr node is NULL.
		{
			curr = stack.top(); 
			stack.pop(); // Pop the node on top of stack.
			result.push_back(curr->data); // Push the elements in the result vector
			curr = curr->right; 
		}
	}
}

void iterativePreOrder(TreeNode root, vector<int> &result)
{
    // return if the tree is empty
    if (root == NULL)
    return;
 
    // create an empty stack and push the root node
    stack<TreeNode> stk;
    stk.push(root);
 
    // loop till stack is empty
    while (!stk.empty())
    {
        // pop a node from the stack and print it
        TreeNode curr = stk.top();
        stk.pop();
 
        result.push_back(curr->data); // store the elements in result vector
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stk.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stk.push(curr->left);
        }
    }
}


void iterativePostOrder(TreeNode root, vector<int> &result)
{
    // if the tree is empty or is not present, then return
    if(root == NULL)
        return;
    // create an empty stack and push the root node
    stack<TreeNode> stk1;
    stk1.push(root);
 
    // create another stack to store postorder traversal
    stack<int> resultStack;
 
    // loop till stack is empty
    while (!stk1.empty())
    {
        // pop a node from stack1 and push the data into the resultStack
        TreeNode curr = stk1.top();
        stk1.pop();
 
        resultStack.push(curr->data);
 
        // push the left and right child of the popped node into stack1
        if (curr->left) {
            stk1.push(curr->left);
        }
 
        if (curr->right) {
            stk1.push(curr->right);
        }
    }
 
    // store elements in the result vector
    while (!resultStack.empty())
    {
        result.push_back(resultStack.top());
        resultStack.pop();
    }
}






int main(){
    TreeNode root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    vector<int> it_In, it_Pre, it_Post;
    vector<int> rec_In, rec_Pre, rec_Post;

    cout<<"Recursive Traversals:-\n";
    // function call for recursive implementation of tree traversals
    recursiveInOrder(root, rec_In);
    recursivePreOrder(root, rec_Pre);
    recursivePostOrder(root, rec_Post);
    
    // Printing of all the traversals
    cout<<"InOrder\n";
    for(auto element : rec_In)
        cout<<element<<" ";
    cout<<endl;

    cout<<"PreOrder\n";
    for(auto element : rec_Pre)
        cout<<element<<" ";
    cout<<endl;

    cout<<"PostOrder\n";
    for(auto element : rec_Post)
        cout<<element<<" ";
    cout<<endl;
    cout<<endl;

    cout<<"Iterative Traversals:-\n";
    // function call for iterative implementation of tree traversals
    iterativeInOrder(root, it_In);
    iterativePreOrder(root, it_Pre);
    iterativePostOrder(root, it_Post);

    // Printing of all the traversals
    cout<<"InOrder\n";
    for(auto element : it_In)
        cout<<element<<" ";
    cout<<endl;

    cout<<"PreOrder\n";
    for(auto element : it_Pre)
        cout<<element<<" ";
    cout<<endl;

    cout<<"PostOrder\n";
    for(auto element : it_Post)
        cout<<element<<" ";
    cout<<endl;

    return 0;
}