#include<stdio.h>
#include<process.h>

struct node
{
	int data;
	struct node *next;
};

struct node *rear, *front = NULL;
//struct node *front = NULL;

int num;

void add_queue();
void delete_queue();
void display_queue();

void main()
{
	
    int ch;
    while(1)
    {
    printf("\n                  MAIN MENU                \n");
    printf("-----------------------------------------------");
	printf("\nIMPLEMENTATION OF LINEAR QUEUE USING LINKED LIST\n");
	printf("-----------------------------------------------");
    printf("\n 1. Insert elements into the Queue");
    printf("\n 2. Delete elements from the Queue");
    printf("\n 3. Display elements present in the Queue");
    printf("\n 4. Exit");
    printf("\n---------------------------------------------");
    printf("\n Enter your choice :");
    scanf("%d",&ch);
    	switch(ch)
    	{
    		case 1:
    			printf("\n Inserting elements into the Queue");
    			add_queue();
    			break;
    		case 2:
    			printf("\n Deleting elements from the Queue");
    			delete_queue();
    			break;
    		case 3:
    			printf("\n Displaying elements present in the Queue");
    			display_queue();
    			break;
    		case 4:
    			printf("\n EXIT!!!");
    			exit(0); 
		}
	}
}

void add_queue()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter a number :");
	scanf("%d",&num);
	temp->data=num;
	temp->next=NULL;
	if(front==NULL)
	{
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}

void delete_queue()
{
	if(front==NULL)
	{
		printf("\n The queue is empty, nothing can be deleted");
 		return;
	}
	struct node *temp;
	temp=front;
	printf("\n The number to be deleted is : %d",temp->data);
	if(front==rear)
	{
		front=rear=NULL;
	}
	else 
	{
		front=front->next;
	}
	free(temp); 
}

void display_queue()
{
    if(front==NULL)
	{
		printf("\n The queue is empty, nothing can be displayed");
 		return;
	}
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		printf("\n Data = %d",temp->data);
		temp=temp->next;
	}
}
