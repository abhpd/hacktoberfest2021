#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*root;
struct node* create(struct node *root)
{
	int t;
	struct node *temp,*nn;
	nn=(struct node *)malloc(sizeof(struct node));
	if(nn==NULL)
	printf("ERROR : Sigstev\n");
	nn->left=NULL;
	nn->right=NULL;
	printf("Enter Data: ");
	scanf("%d",&t);
	nn->data=t;
	if(root==NULL)
		root = nn;
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			if(t>temp->data)
			{
				if(temp->right==NULL)
				{
					temp->right=nn;
					temp=NULL;
				}
				else
				temp=temp->right;
			}
			else
			{
				if(temp->left==NULL)
				{
					temp->left=nn;
					temp=NULL;
				}
				else
				temp=temp->left;
			}
		}
	}
	return root;
}
void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d  ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ",root->data);
	}
}
int main()
{
	int ch;
	printf("**************************************BINARY SEARCH TREE**************************************\n");
	do{
		printf("1. Enter Data\n2. Display Data in INORDER\n3. Display Data in PREORDER\n4. Display Data in POSTORDER\n5. To Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : root=create(root);
				break;
			case 2 : inorder(root); printf("\nContinue : "); getch();
				break;
			case 3 : preorder(root); printf("\nContinue : "); getch();
				break;
			case 4 : postorder(root); printf("\nContinue : "); getch();
				break;
		}
		system("cls");
	}
	while(ch!=5);
	return 0;
}
