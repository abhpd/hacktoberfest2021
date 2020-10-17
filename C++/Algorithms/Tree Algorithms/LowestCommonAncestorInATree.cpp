#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* build(string s){
	if(s == "false"){
		return NULL;
	}
	int d;
	cin>>d;
	node* root = new node(d);
	string s1,s2;
	cin>>s1;
	root->left = build(s1);
	cin>>s2;
	root->right = build(s2);
	return root;
}

node* lca(node* root,int x,int y){
	if(root==NULL){
		return NULL;
	}

	if(root->data == x || root->data == y){
		return root;
	}

	node* lans = lca(root->left,x,y);
	node* rans = lca(root->right,x,y);

	if(lans!=NULL && rans!=NULL){
		return root;
	}

	if(lans!=NULL){
		return lans;
	}return rans;
}

int main(){
	string s;
	node* root = build("true");
	int x,y;
	cin>>x>>y;
	node* ans = lca(root,x,y);
	cout<< ans->data<< " ";

	return 0;
}


// Input Format:
// Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL next two line contains 2 element of BT

// Output Format:
// Display the LCA value.

// Sample Input:
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 50
// 60

// Sample Output:
// 10
