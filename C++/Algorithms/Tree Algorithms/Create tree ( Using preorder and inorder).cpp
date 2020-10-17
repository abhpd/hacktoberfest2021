#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;

	node(int d){
		data =d;
		left = right = NULL;
	}
};

node* createTree(int pre[],int ino[],int s,int e){
	static int i=0;
	if(s>e){
		return NULL;
	}
	node* root = new node(pre[i]);
	int index = -1;
	for(int j=s;j<=e;j++){
		if(ino[j]==pre[i]){
			index = j;
			break;
		}
	}
	i++;
	root->left = createTree(pre,ino,s,index-1);
	root->right = createTree(pre,ino,index+1,e);
	return root;
}

void print(node* root){
	if(root==NULL){
		return;
	}else if(root->left!=NULL && root->right==NULL){
		cout<< root->left->data << " => "<< root->data<< " <= END"<< endl;
	}else if(root->left==NULL && root->right !=NULL){
		cout<< "END => "<< root->data<< " <= "<< root->right->data<< endl;
	}else if(root->left!=NULL && root->right!=NULL){
		cout<< root->left->data << " => "<< root->data<< " <= "<< root->right->data<< endl;
	}else if(root->left==NULL && root->right ==NULL){
		cout<< "END => "<< root->data<< " <= END"<< endl;
	}

	print(root->left);
	print(root->right);
	return;
}

int main(){
	int n; cin>>n;
	int pre[n];
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	int m; cin>>m;
	int ino[m];
	for(int i=0;i<n;i++){
		cin>>ino[i];
	}
	node* root = createTree(pre,ino,0,n-1);
	print(root);

	return 0;
}

// Input Format:
// Enter the size of the preorder array N then add N more elements and store in the array 
// denoting the preorder traversal of the tree. Then enter the size of the inorder array M 
// and add M more elements and store the inorder traversal of the array.

// Constraints:
// 1 <= N, M <= 10^4

// Output Format:
// Display the tree using a modified preorder function. For each node , 
// first print its left child's data , then the data of the root itself , 
// then the data of its right child. Do this for each node in a new line in preorder manner.
//  If one of the children does not exist print END in its place. Refer to the sample testcase.

// Sample Input:
// 3
// 1 2 3
// 3
// 3 2 1

// Sample Output:
// 2 => 1 <= END
// 3 => 2 <= END
// END => 3 <= END

// Explanation:
// The above tree looks like

//          1
//        /
//      2
//    /
//  3
