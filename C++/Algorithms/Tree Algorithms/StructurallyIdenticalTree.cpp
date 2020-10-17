#include<iostream>
#include<cstring>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* build(string str){
	if(str == "false"){
		return NULL;
	}

	int d;
	cin>>d;

	node* root = new node(d);
	string str1,str2;
	cin>>str1;
	root->left = build(str1);
	cin>>str2;
	root->right = build(str2);
	
	return root;
}

bool isStructure(node* a,node* b){
	if(a==NULL && b==NULL){
		return 1;
	}

	bool l=0,r=0;
	if(((a->left!=NULL && b->left!=NULL)||(a->left==NULL&& b->left==NULL)) && isStructure(a->left,b->left)){
		l=1;
	}
	if(((a->right!=NULL&&b->right!=NULL)||(a->right==NULL&&b->right==NULL)) && isStructure(a->right,b->right)){
		r=1;
	}

	return l&r;
}

int main(){
	node* a = build("true");
	node* b = build("true");
	if(isStructure(a,b)){
		cout<< "true";
	}else{
		cout<< "false";
	}

	return 0;
}


// Input Format:
// Enter the values of all the 
// nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

// Output Format:
// Display the Boolean result

// sample Input:
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
// 10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

// Sample Output
// true
