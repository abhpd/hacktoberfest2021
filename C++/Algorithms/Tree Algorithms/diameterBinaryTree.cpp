#include <iostream>
using namespace std;

class node
{
	public:
	int data;
	node* left, *right;
};

//function to calculate diameter of a binary tree
int calcDiameter(node *root, int* height){
    
    if(root==NULL){
        *height=-1;
        return 0;
    }
        
    int leftHeight=0, rightHeight=0;
        
    int leftDiameter=calcDiameter(root->left, &leftHeight);
    int rightDiameter=calcDiameter(root->right, &rightHeight);
        
    int currentDiameter = leftHeight + rightHeight + 2;
        
    *height = std::max(leftHeight, rightHeight)+1;
        
    return std::max( currentDiameter, std::max(leftDiameter, rightDiameter));
}


//function to create and set the new node
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}

    //              (1) <--root
    //            /     \
    //          (2)      (3)
    //         /   \
    //     (4)      (5)
    //             /   \
    //         (6)      (9)
    //        /           \
    //     (7)            (10)
    //     /                \
    //   (8)                (11)
    //                     /
    //                 (12)

/* Driver code*/

void inorderDisplay(node* root){
    if(root==NULL) {
        return;
    }

    inorderDisplay(root->left);
    std::cout << root->data << " ";
    inorderDisplay(root->right);
}

void postorderDisplay(node* root){
    if(root==NULL) {
        return;
    }

    postorderDisplay(root->left);
    postorderDisplay(root->right);
    std::cout << root->data << " ";
}

int main()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->left->left = newNode(7);
    root->left->right->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->left->right->right->right = newNode(10);
    root->left->right->right->right->right = newNode(11);
    root->left->right->right->right->right->left = newNode(12);

    int height=0;
    
    std::cout << "Inorder of Binary Tree: "; 
    inorderDisplay(root);
    std::cout << "\nPostrder of Binary Tree: ";
    postorderDisplay(root);
    std::cout << "\nDiameter of the binary tree is: " << calcDiameter(root, &height) << "\n" ;

	return 0;
}