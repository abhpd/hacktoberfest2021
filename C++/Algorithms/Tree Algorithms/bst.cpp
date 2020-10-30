#include<bits/stdc++.h>
using namespace std;

typedef struct tree
{
	int val;
	struct tree* right;
	struct tree* left;

}tree;

tree* newnode(int data)
{
	tree* newtree  = (tree*)malloc(sizeof(tree));
	newtree->left=NULL;
	newtree->right=NULL;
	newtree->val=data;

	return newtree;
}
void insert (int data, tree* root)
{
	if (root->val<data)
	{
		if (root->right!=NULL)
		insert (data,root->right);
	
		else
		{
			tree* temp=newnode(data);
			root->right=temp;
		}
	}
	else if (root->val>data)
	{
		if (root->left!=NULL)
		insert (data,root->left);

		else
		{
			tree* temp=newnode(data);
			root->left=temp;
		}
	}
}

int search (int data, tree* root)
{
	if (root->val<data)
	{
		if (root->right!=NULL)
		return search(data,root->right);

		else
		return 0;
	}	

	else if (root->val>data)
	{
		if (root->left!=NULL)
		return search(data,root->left);

		else
		return 0;
	}

	else if (root->val==data)
	return data;	
}

void inorder (tree* root)
{
	if (root==NULL)
	return;

	inorder(root->left);
	cout<<root->val<<" ";

	inorder(root->right);
}

int main () {
	tree* bst = newnode(10);
		
	insert (2,bst);	
	insert (14,bst);	
	insert (17,bst);	
	insert (7,bst);	
	insert (1,bst);			
	insert (8,bst);	
	insert (19,bst);	
	insert (4,bst);	
	insert (11,bst);	
	insert (16,bst);	

	int ans=search (1,bst);
	if (ans==0)
		cout<<"NOT FOUND\n";
	else
	cout<<"FOUND "<<ans<<"\n";
	
	inorder(bst);
	cout<<"\n";i
}
