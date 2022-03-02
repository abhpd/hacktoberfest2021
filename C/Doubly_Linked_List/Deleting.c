#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *leftAddress;
	struct node *rightAddress;
}Node;

Node *start=NULL, *end=NULL;

int sizeofList()
{
	int count=0;
	Node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		count = count + 1;
		ptr = ptr->rightAddress;
	}
	return count;
}
void add(int no)
{
	Node *newNode, *ptr;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->leftAddress = NULL;
	newNode->data = no;
	newNode->rightAddress = NULL;
	if(start==NULL)
	{
		start = newNode;
	}
	else
	{
		ptr = start;
		while(ptr->rightAddress!=NULL)
		{
			ptr = ptr->rightAddress;
		}
		ptr->rightAddress = newNode;
		newNode->leftAddress = ptr;
		end = newNode;
	}
}
void deleteBeg()
{
	Node *ptr;
	ptr = start;
	start = ptr->rightAddress;
	ptr->rightAddress->leftAddress = NULL;
	free(ptr);
}
void deletePos(int pos)
{
	Node *ptr,*flag;
	ptr = start;
	int count=1;
	while(ptr!=NULL)
	{
		if(count==pos)
		{
			flag->rightAddress = ptr->rightAddress;
			ptr->rightAddress->leftAddress = flag;
		}
		flag = ptr;
		ptr = ptr->rightAddress;
		count = count + 1;
	}
}
void display()
{
	Node *ptr;
	ptr = start;
	printf("START<->");
	while(ptr!=NULL)
	{
		printf("%d<->",ptr->data);
		ptr = ptr->rightAddress;
	}
	printf("END");
}
void revDisplay()
{
	Node *ptr;
	ptr = end;
	printf("END<->");
	while(ptr!=NULL)
	{
		printf("%d<->",ptr->data);
		ptr = ptr->leftAddress;
	}
	printf("START");
}
int main()
{
	printf("Deleting & Traversing\n");
	printf("*********************\n\n");
	printf("1: Add\n2: Delete\n3: Display\n4: Reverse Display\n\n");
	int choice,no,pos;
	while(1)
	{
		printf("Enter Choice : ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter Number : ");
			scanf("%d",&no);
			printf("\n");
			add(no);
		}
		else if(choice==2)
		{
			int size = sizeofList();
			while(1)
			{
				printf("Enter Position : ");
				scanf("%d",&pos);
				if(pos==1)
				{
					deleteBeg();
					break;
				}
				else if(pos<1 || pos>size)
				{
					continue;
				}
				else
				{
					deletePos(pos);
					break;
				}
			}
			printf("\n");
		}
		else if(choice==3)
		{
			display();
			printf("\n\n");
		}
		else if(choice==4)
		{
			revDisplay();
			printf("\n\n");
		}
		else if(choice==0)
		{
			break;
		}
	}
}