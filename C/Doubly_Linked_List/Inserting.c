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
void insertBeg(int no)
{
	Node *newNode, *ptr;
	ptr = start;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->leftAddress = NULL;
	newNode->data = no;
	newNode->rightAddress = NULL;

	newNode->rightAddress = ptr;
	ptr->leftAddress = newNode;
	start = newNode;
}
void insertPos(int no, int pos)
{
	Node *ptr, *newNode, *flag;
	ptr=start;
	int count=1;
	while(ptr!=NULL)
	{
		if(count==pos)
		{
			newNode = (Node *)malloc(sizeof(Node));
			newNode->leftAddress = NULL;
			newNode->data = no;
			newNode->rightAddress = NULL;

			newNode->rightAddress = ptr;
			ptr->leftAddress = newNode;
			flag->rightAddress = newNode;
			newNode->leftAddress = flag;
			break;

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
	while(ptr != NULL)
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
	while(ptr != NULL)
	{
		printf("%d<->",ptr->data);
		ptr = ptr->leftAddress;
	}
	printf("START");
}
int main()
{
	printf("Inserting & Traversing\n");
	printf("**********************\n\n");
	int choice,no,pos;
	printf("1: Add\n2: Insert\n3: Display\n4: Reverse Display\n0: Edit\n\n");
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
			printf("Enter Number : ");
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
				else if(pos==size+1)
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