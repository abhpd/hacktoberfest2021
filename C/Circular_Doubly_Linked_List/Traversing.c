#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *leftAddress;
	struct node *rightAddress;
}Node;

Node *start=NULL, *end=NULL;

void add(int no)
{
	Node *newNode, *ptr, *flag;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->leftAddress = NULL;
	newNode->data = no;
	newNode->rightAddress = NULL;
	if(start==NULL)
	{
		start = newNode;
		newNode->rightAddress = start;
		newNode->leftAddress = start; 
		end = newNode;
	}
	else
	{
		ptr = start;
		flag = start;
		while(ptr->rightAddress != start)
		{
			ptr = ptr->rightAddress;
		}
		ptr->rightAddress = newNode;
		newNode->leftAddress = ptr;

		flag->leftAddress = newNode;
		newNode->rightAddress = flag;

		end = newNode;
	}
}
void display()
{
	Node *ptr;
	ptr = start;
	printf("<->START<->");
	while(ptr->rightAddress != start)
	{
		printf("%d<->",ptr->data);
		ptr = ptr->rightAddress;
	}
	printf("%d<->",ptr->data);
	printf("END<->");
}
void revDisplay()
{
	Node *ptr;
	ptr = end;
	printf("<->END<->");
	while(ptr->leftAddress != end)
	{
		printf("%d<->",ptr->data);
		ptr = ptr->leftAddress;
	}
	printf("%d<->",ptr->data);
	printf("START<->");
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