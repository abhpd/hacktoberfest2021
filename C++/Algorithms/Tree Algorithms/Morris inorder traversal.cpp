#include<iostream>
#include<stack>

using namespace std;
class node
{
	public:
	int data;
	node *left,*right;
};
node *newnode(int x)
{
	node *temp=new node;
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void inorder(node *root)
{
	node *current,*pre;
	if(root==NULL)
	return;
	
	current=root;
	while(current!=NULL)
	{
		if(current->left==NULL)
		{
			cout<<current->data<<" ";
			current=current->right;
		}
		else
		{
			pre=current->left;
			while(pre->right!=NULL&&pre->right!=current)
			{
				pre=pre->right;
			}
			if(pre->right==NULL)
			{
				pre->right=current;
				current=current->left;
			}
			else
			{
				pre->right=NULL;
				cout<<current->data<<" ";
				current=current->right;
			}
		}
	}
}
int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	inorder(root);

}
