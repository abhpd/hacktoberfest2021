#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<stdlib.h>
typedef struct Node
{
	int val;
       struct Node *next;

}node;
node *getnode(int num)
{
	node *newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->val=num;
	newnode->next=NULL;
	return newnode;
}
void enqueue(node **tail)
{
	node *nn;
	int num ;
	printf("\n enter the data");
	scanf("%d",&num);
	nn=getnode(num);
	if(*tail==NULL)
	{

		*tail=nn;
		(*tail)->next=NULL;
		(*tail)->next;
	}
	else
	{
		nn->next=(*tail)->next;
		(*tail)->next=nn;;
		(*tail)=nn;
	}
}
void dequeue(node **tail)
{
	node *temp;
	if(*tail==NULL)
	{
		printf("\n list is empty");
	}
	else
	{
		  temp=(*tail)->next;
		  (*tail)->next=(*tail)->next->next;
		  free(temp);
	}
}
void display(node *tail)
{
	node *p;
	p=tail->next;
	do
	{
		 printf("\n %d value",p->val);
		 p=p->next;
	}
	while(p!=tail->next);

}
void main()
{
	 node *tail=NULL;
	 int ch,n;
	 clrscr();
	while(1)
	{
		printf("\n menu ");
		printf("\n1 insertion \n2 deletion \n3 display\n4 exit");
		printf("\n enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1 : enqueue(&tail);
		       break;
		case 2 : dequeue(&tail);
			break;
		case 3: display(tail);
			break;
		case 4: exit(0);
		}
	}
	getch();
}
