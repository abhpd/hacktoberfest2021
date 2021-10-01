#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *nextAddress;
}Node;

Node *start = NULL;

int sizeofList()
{
	int count=0;
	Node *ptr;
	ptr = start;
	while(ptr->nextAddress != start)
	{
		count = count + 1;
		ptr = ptr->nextAddress;
	}
	count = count + 1;
	return count;
}
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
void insertBeg(int no)
{
	Node *newNode, *ptr;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->data = no;

	ptr = start;
	while(ptr->nextAddress != start)
	{
		ptr = ptr->nextAddress;
	}
	ptr->nextAddress = newNode;
	newNode->nextAddress = start;
	start = newNode;
}
void insertPos(int no, int pos)
{
	Node *newNode, *ptr, *flag;
	ptr = start;
	int count = 1;
	while(ptr->nextAddress != start)
	{
		if(count==pos)
		{
			newNode = (Node *)malloc(sizeof(Node));
			newNode->data = no;
			newNode->nextAddress = NULL;

			newNode->nextAddress = flag->nextAddress;
			flag->nextAddress = newNode;
			break;
		}
		count = count + 1;
		flag = ptr;
		ptr = ptr->nextAddress;
	}
	if(count==pos && ptr->nextAddress == start)
	{
		newNode = (Node *)malloc(sizeof(Node));
		newNode->data = no;
		newNode->nextAddress = NULL;

		newNode->nextAddress = flag->nextAddress;
		flag->nextAddress = newNode;
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
	printf("START");
}
int main()
{
	printf("Inserting & Traversing\n");
	printf("**********************\n\n");
	printf("1: Add\n2: Insert\n3: Display\n0: Exit\n\n");
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
			printf("Enter Number   : ");
			scanf("%d",&no);
			while(1)
			{
				printf("Enter Position : ");
				scanf("%d",&pos);
				if(pos==1)
				{
					insertBeg(no);
					break;
				}
				else if(pos == size+1)
				{
					add(no);
					break;
				}
				else if(pos<1 || pos>size+1)
				{
					continue;
				}
				else
				{
					insertPos(no,pos);
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
		else if(choice==0)
		{
			break;
		}
	}
}