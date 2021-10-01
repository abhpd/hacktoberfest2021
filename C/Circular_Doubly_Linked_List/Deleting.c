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
	if(start == NULL)
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
		newNode->rightAddress = start;
		flag->leftAddress = newNode;
		end = newNode;
	}
}
void deleteBeg()
{
	Node *ptr, *flag;
	ptr = start;
	flag = ptr->rightAddress;
	while(ptr->rightAddress != start)
	{
		ptr = ptr->rightAddress;
	}
	ptr->rightAddress = flag;
	flag->leftAddress = ptr;
	start = flag;
}
void deleteEnd()
{
	Node *ptr, *flag, *temp;
	ptr = start;
	temp = start;
	while(ptr->rightAddress != start)
	{
		flag = ptr;
		ptr = ptr->rightAddress;
	}
	flag->rightAddress = start;
	end = flag;
	temp->leftAddress = end;
	free(ptr);
}
void deletePos(int pos)
{
	Node *ptr, *flag;
	ptr = start;
	int count = 1;
	while(ptr->rightAddress != start)
	{
		if(count==pos)
		{
			flag->rightAddress = ptr->rightAddress;
			ptr->rightAddress->leftAddress = flag;
			free(ptr);
			break;
		}
		flag = ptr;
		ptr = ptr->rightAddress;
		count = count + 1;
	}
}
void delete()
{
	Node *ptr;
	ptr = start;
	free(ptr);
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
	if(ptr->data == 0)
	{
		printf("END<->");
		return;
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
	if(ptr->data == 0)
	{
		printf("END<->");
		return;
	}
	printf("%d<->",ptr->data);
	printf("START<->");
}
int main()
{
	printf("Deleting & Traversing\n");
	printf("*********************\n\n");
	printf("1: Add\n2: Delete\n3: Display\n4: Reverse Display\n0: Exit\n\n");
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
					if(size==1)
					{
						delete();
						break;
					}
					deleteBeg();
					break;
				}
				else if(pos<1 || pos>size)
				{
					continue;
				}
				else if(pos==size)
				{
					deleteEnd();
					break;
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