#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *leftAddress;
	struct node *rightAddress;
}Node;

Node *start = NULL, *end = NULL;

void add(int no)
{
	Node *newNode, *ptr;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->leftAddress = NULL;
	newNode->data = no;
	newNode->rightAddress = NULL;
	if(start == NULL)
	{
		start = newNode;
	}
	else
	{
		ptr = start;
		while(ptr->rightAddress != NULL)
		{
			ptr = ptr->rightAddress;
		}
		ptr->rightAddress = newNode;
		newNode->leftAddress = ptr;
		end = newNode;
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
	printf("Adding & Traversing\n");
	printf("*******************\n\n");
	printf("1: Add\n2: Display\n3: Reverse Display\n0: Exit\n\n");
	int choice,no;
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
			display();
			printf("\n\n");
		}
		else if(choice==3)
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