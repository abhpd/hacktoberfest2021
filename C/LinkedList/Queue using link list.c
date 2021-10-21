#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node *link;
}*front=NULL,*rear=NULL;
void enqueue(int value)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->link=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else{
	
		rear->link=temp;
		rear=temp;	
	}
}
void dequeue()
{
	struct node *temp;
	if(front==NULL)
	{
		printf("queue is empty!\n");
	}
	else{
		temp=front;
		printf("deleted element is: %d\n",temp->data);
		front=front->link;
		free(temp);
	}
}

void display()
{
	struct node *p;
	p=front;
	if(front==NULL)
	{
		printf("queue is empty!\n");
	}
	printf("The queue is:\n");
	while(p->link!=NULL)
	{
		printf("%d->",p->data);
		p=p->link;
	}
	printf("%d\n",p->data);

}
int main(void)
{
	int n,ch,value;
	while(1)
	{
		printf("stack menu is:\n\n");
		printf("1. insert element\n");
		printf("2. delete element\n");
		printf("3. display\n");
		printf("4. exit\n\n");
		printf("Enter your choice(1-4):\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value to insert in queue:\n");
			        scanf("%d",&value);
				 enqueue(value);
				 break;
			case 2: dequeue();
			        break;
			case 3: display();
				 break;
			case 4: exit(0);
			default: printf("Wrong choice!\n");
		}
	}
	return 0;
}
							
		