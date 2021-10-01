#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *nextAddress;
}Node;

Node *start = NULL;

void add(int no)
{
	Node *newNode, *ptr;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = no;
	newNode->nextAddress = NULL;
	if(start == NULL)
	{
		start = newNode;
		newNode->nextAddress = start;
	}
	else
	{
		ptr = start;
		while(ptr->nextAddress != start)
		{
			ptr = ptr->nextAddress;
		}
		ptr->nextAddress = newNode;
		newNode->nextAddress = start;
	}
}
void display()
{
	Node *ptr;
	ptr = start;
	printf("START->");
	while(ptr->nextAddress != start)
	{
		printf("%d->",ptr->data);
		ptr = ptr->nextAddress;
	}
	printf("%d->",ptr->data);
	printf("END");
}
int main()
{
	printf("Adding & Traversing\n");
	printf("*******************\n\n");
	printf("1: Add\n2: Display\n0: Exit\n\n");
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
		else if(choice==0)
		{
			break;
		}
	}
}