#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *nextAddress;
}Node;

Node *start = NULL;

int sizeofList()
{
	Node *ptr;
	ptr = start;
	int count=0;
	while(ptr != NULL)
	{
		count = count + 1;
		ptr = ptr->nextAddress;
	}
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
	}
	else
	{
		ptr = start;
		while(ptr->nextAddress!=NULL)
		{
			ptr = ptr->nextAddress;
		}
		ptr->nextAddress = newNode;
	}
}
void deleteBeg()
{
	Node *ptr;
	ptr = start;
	start = ptr->nextAddress;
	free(ptr);
}
void deletePos(int pos)
{
	Node *ptr, *flag;
	ptr = start;
	int count = 1;
	while(ptr != NULL)
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
void display()
{
	Node *ptr;
	ptr = start;
	printf("START->");
	while(ptr != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->nextAddress;
	}
	printf("END");
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
			while(1)
			{
				printf("Enter Position : ");
				scanf("%d",&pos);
				int size = sizeofList();
				if(pos==1)
				{
					deleteBeg();
					break;
				}
				else if(pos>size || pos<1)
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