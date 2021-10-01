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
	if(start==NULL)
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
void deleteBeg()
{
	Node *ptr, *flag;
	ptr = start;
	flag = start;
	while(ptr->nextAddress != start)
	{
		ptr = ptr->nextAddress;
	}
	start = flag->nextAddress;
	ptr->nextAddress = start;
	free(flag);
}
void deletePos(int pos)
{
	Node *ptr, *flag;
	ptr = start;
	int count=1;
	while(ptr->nextAddress != start)
	{
		if(count==pos)
		{
			flag->nextAddress = ptr->nextAddress;
			free(ptr);
			break;
		}
		flag = ptr;
		ptr = ptr->nextAddress;
		count = count + 1;
	}
}
void deleteEnd()
{
	Node *ptr, *flag;
	ptr = start;
	while(ptr->nextAddress != start)
	{
		flag = ptr;
		ptr = ptr->nextAddress;
	}
	flag->nextAddress = start;
	free(ptr);
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
	printf("Deleting & Traversing\n");
	printf("*********************\n\n");
	int choice,pos,no;
	printf("1: Add\n2: Delete\n3: Display\n0: Exit\n\n");
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
				else if(pos==size)
				{
					deleteEnd();
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
		else if(choice==0)
		{
			break;
		}
	}
}