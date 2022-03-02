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
	while(ptr->rightAddress != start)
	{
		count = count + 1;
		ptr = ptr->rightAddress;
	}
	count = count + 1;
	return count;
}
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
		newNode->leftAddress = start;
		newNode->rightAddress = start;
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

		newNode->rightAddress = flag;
		flag->leftAddress = newNode;

		end = newNode;
	}
}
void insertBeg(int no)
{
	Node *newNode, *ptr, *flag;
	ptr = start;
	flag = start;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->leftAddress = NULL;
	newNode->data = no;
	newNode->rightAddress = NULL;

	while(ptr->rightAddress != start)
	{
		ptr = ptr->rightAddress;
	}
	start = newNode;
	newNode->rightAddress = flag;
	flag->leftAddress = newNode;
	newNode->leftAddress = ptr;
	ptr->rightAddress = newNode;

}
void insertPos(int no, int pos)
{
	Node *ptr, *flag, *newNode;
	ptr = start;
	int count=1;

	newNode = (Node *)malloc(sizeof(Node));
	newNode->leftAddress = NULL;
	newNode->data = no;
	newNode->rightAddress = NULL;
	
	while(ptr->rightAddress != start)
	{
		if(count==pos)
		{
			flag->rightAddress = newNode;
			newNode->leftAddress = flag;
			newNode->rightAddress = ptr;
			ptr->leftAddress = newNode;
			break;
		}
		flag = ptr;
		ptr = ptr->rightAddress;
		count = count + 1;
	}
	if(ptr->rightAddress==start || count==pos)
	{
		flag->rightAddress = newNode;
		newNode->leftAddress = flag;
		newNode->rightAddress = ptr;
		ptr->leftAddress = newNode;
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
	printf("<->START<->");
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
	printf("Inserting & Traversing\n");
	printf("**********************\n\n");
	int choice,no,pos;
	printf("1: Add\n2: Insert\n3: Display\n4: Reverse Display\n0: Exit\n\n");
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
				else if(pos<1 || pos>size+1)
				{
					continue;
				}
				else if(pos==size+1)
				{
					add(no);
					break;
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