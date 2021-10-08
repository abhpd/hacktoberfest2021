#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct queue
{
	int q[max];
	int rear,front;
	
}queue;
int empty(int f,int r);
int isfull(int f,int r);
void enqueue(queue *,int val);
int dequeue(queue *);
void display(queue);
int main()
{
	queue qt;
	qt.rear=-1;
	qt.front=-1;
	int ch,ele;
	do
	{
		printf("\n***MENU***\n");
		printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter  element to insert:");
				scanf("%d",&ele);
				enqueue(&qt,ele);
				break;
			case 2:
				ele=dequeue(&qt);
				printf("Element deleted=%d",ele);
				break;
			case 3:
				display(qt);
				break;
			case 4:
				exit(0);
				
		}
	}while(1);
}
int isfull(int f,int r)
{
	if((f==0 && r==max-1) || (f==r+1))
		  return 1;
	else
	  return 0;
}
int isempty(int f,int r)
{
	if(f==-1 && r==-1)
	  return 1;
	  
	else
	  return 0;
}
void enqueue(queue *qt,int val)
{
	if(isfull(qt->front,qt->rear))
	   {
	   	printf("Queue full");
	   	return;
	   }
	   qt->rear=((qt->rear)+1)%max;
	   qt->q[qt->rear]=val;
	   
	   if(qt->front==-1)
	     (qt->front)++;
}
int dequeue(queue *qt)
{
	  int val;
		if(isempty(qt->front,qt->rear))
	   {
	   	printf("Queue empty");
	   	return -1;
	   }
	   
	   val=qt->q[qt->front];
	   
	   if(qt->front==qt->rear)
	     {
	     	qt->front=-1;
	     	qt->rear=-1;
		 }
		 else
		   qt->front=((qt->front)+1)%max;
		   
	return val;
	     
}

void display(queue qt)
{
	int i;
	if(isempty(qt.front,qt.rear))
	{    
	  printf("Queue empty");
	  return;
}
	else
	{
	
	printf("Elements in queue:\n");
	for(i=qt.front;i!=qt.rear;i=(i+1)%max)
	    printf("%d\n",qt.q[i]);
	    
	printf("%d\n",qt.q[i]);
  }
}

