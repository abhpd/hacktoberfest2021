#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front=-1,rear=-1,c_queue[MAX];
void insert();
void delete();
int main(void)
{
	int ch;
	while(1)
	{
		printf("\nCircular queue menu is:\n");
		printf("1. insert\n");
		printf("2. delete\n");
		printf("3. exit\n");
		printf("\nEnter your choice (1-3):\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: insert();
				 break;
			case 2: delete();
				 break;
			case 3: exit(0);
			default: printf("Wrong Choice!\n");
				 	
		}
	}
}
void insert(){
	int val;
	if(front==(rear+1)%MAX)
		printf("Circular queue is full!\n");
	else
	{
		if(front==-1)
		front=0;
		printf("Enter the element to insert in circular queue is:\n");
		scanf("%d",&val);
		rear=(rear+1)%MAX;
		c_queue[rear]=val;
	}		
}
void delete(){
	if(front==-1 && rear==-1)
		printf("Circular queue is empty!\n");
	else if(front==rear){	
		printf("Deleted element from circular queue is: %d\n",c_queue[front]);
		front=-1;
		rear=-1;
	}
	else{	
		printf("Deleted element from circular queue is: %d\n",c_queue[front]);
		front=(front+1)%MAX;
	}
}

