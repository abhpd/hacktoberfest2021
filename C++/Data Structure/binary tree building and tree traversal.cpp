// 1) build a binary tree
// 2) Preorder traversal
// 3) Inordertraversal
// 4) Postorder traversal

#include<iostream>
using namespace std;

struct node{
	int val;
	
	node *left;
	node *right;
};

void addNode(node **root, int data);
void preorderTraversal(node *root);
void inorderTraversal(node *root);
void postorderTraversal(node *root);

void printRealList(int arr[], int length);

int main(){
	int arr[]={4,5,9,8,7,6,1,2,3,4,5,8,7,0};
	int length = sizeof(arr)/sizeof(arr[0]);
	
	cout<<"Real List           : ";
	printRealList(arr, length);
	
	node *head = NULL;
	
	for(int i=0; i<length; i++){
		addNode(&head, arr[i]);
	}
	
	cout<<"Preorder Traversal  : ";
	preorderTraversal(head);
	cout<<endl;
	
	cout<<"Inorder Traversal   : ";
	inorderTraversal(head);
	cout<<endl;
	
	cout<<"Postorder Traversal : ";
	postorderTraversal(head);
	
}

void addNode(node **root, int data){
	if(*root==NULL){
		node *temp = new node;
		temp->val = data;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	}else{
		if((*root)->val>data){
			addNode((&(*root)->left), data);
		}else{
			addNode((&(*root)->right), data);
		}
	}
}

void preorderTraversal(node *root){
	if(root!=NULL){
		cout<<root->val<<" ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

void inorderTraversal(node *root){
	if(root!=NULL){
		inorderTraversal(root->left);
		cout<<root->val<<" ";
		inorderTraversal(root->right);
	}
}

void postorderTraversal(node *root){
	if(root!=NULL){
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout<<root->val<<" ";
	}
}

void printRealList(int arr[], int length){
	for(int i=0; i<length; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


