#include <stdio.h>
#include <stdlib.h>
struct node
{
	int value;
	struct node*lptr;
	struct node*rptr;
};
void insertatfront(struct node**L,struct node**R,int val)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	if(*L==NULL)
	{
		*L=*R=newnode;
		(*L)->lptr=NULL;
		(*L)->rptr=NULL;
	}
	newnode->rptr=*L;
	newnode->lptr=NULL;
	(*L)->lptr=newnode;
	*L=newnode;
	(*R)->rptr=*L;
}
void insertatend(struct node**L,struct node**R,int val)
{
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	if(*L==NULL)
	{
		*L=*R=newnode;
		(*L)->lptr=NULL;
		(*L)->rptr=NULL;
	}
	newnode->lptr=*R;
	newnode->rptr=NULL;
	(*R)->rptr=newnode;
	*R=newnode;
	(*L)->lptr=*R;
}
void insertinorder(struct node**L,struct node**R,int val)
{
	struct node*newnode;
	struct node*temp=*L;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	if(*L==NULL)
	{
		*L=*R=newnode;
		(*L)->lptr=NULL;
		(*L)->rptr=NULL;
	}
	if(val<=(*L)->value)
	{
		newnode->rptr=*L;
		newnode->lptr=NULL;
		(*L)->lptr=newnode;
		*L=newnode;
	}
	else if(val>=(*R)->value)
	{
		newnode->lptr=*R;
		newnode->rptr=NULL;
		(*R)->rptr=newnode;
		*R=newnode;
	}
	else
	{
		while(temp->value<=val)
		{
			temp=temp->rptr;
		}
		newnode->lptr=temp->lptr;
		newnode->rptr=temp;
		temp->lptr->rptr=newnode;
		temp->lptr=newnode;
	}
}
void insertafter(struct node**L,struct node**R,int val)
{
	int sval,n;
	struct node*newnode;
	struct node*temp=*L;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=val;
	do
	{
		printf("Enter after which element you want to insert = ");
		scanf("%d",&sval);
		n=1;
		temp=*L;
		while(temp->value!=sval)
		{
			temp=temp->rptr;
			if(temp==NULL)
			{
				printf("Your value is not found");
				n=0;
				break;
			}
		}
	}while(n==0);
	newnode->lptr=temp;
	newnode->rptr=temp->rptr;
	if(temp!=*R)
	{
		temp->rptr->lptr=newnode;
	}
	temp->rptr=newnode;
	if(temp==*R)
		*R=newnode;
		(*L)->lptr=*R;
}
void deleteatfront(struct node**head,struct node**Rear)
{
	struct node*deletenode;
	if(*head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	if((*head)->rptr==NULL && (*head)->lptr==NULL)
	{
		printf("%d is removed\n",(*head)->value);
		free(*head);
		*head=*Rear=NULL;
		return;
	}
	deletenode=*head;
	*head=(*head)->rptr;
	(*head)->lptr=*Rear;
	(*Rear)->rptr=*head;
	printf("%d is removed\n",deletenode->value);
	free(deletenode);
}
void deleteatend(struct node**head,struct node**Rear)
{
	struct node*deletenode;
	deletenode=*Rear;
	if(*head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	if(*head==*Rear)
	{
		printf("%d is removed\n",(*head)->value);
		free(*head);
		*head=*Rear=NULL;
		return;
	}
	deletenode=*Rear;
	*Rear=(*Rear)->lptr;
	(*Rear)->rptr=*head;
	(*head)->lptr=*Rear;
	printf("%d is removed\n",deletenode->value);
	free(deletenode);
}
void deleteafter(struct node**head,struct node**Rear,int val)
{
	struct node*temp;
	temp=*head;
	if(*head==NULL)
	{
		printf("Empty list\n");
		return;
	}
	if(val==(*head)->value)
	{
		if(*head==*Rear)
		{
			printf("%d is removed\n",(*head)->value);
			free(*head);
			*head=*Rear=NULL;
			return;
		}
		else
		{
			temp=*head;
			*head=(*head)->rptr;
			(*head)->lptr=*Rear;
			(*Rear)->rptr=*head;
			printf("%d is removed\n",temp->value);
			free(temp);	
		}
	}
	else if(val==(*Rear)->value)
	{
		temp=*Rear;
		*Rear=(*Rear)->lptr;
		(*Rear)->rptr=*head;
		(*head)->lptr=*Rear;
		printf("%d is removed\n",temp->value);			
		free(temp);	
	}
	else
	{
		while(temp!=NULL && temp->value!=val)
			temp=temp->rptr;
		if(temp==NULL)
			printf("value is not found\n");
			return;
		temp->lptr->rptr=temp->rptr;
		temp->rptr->lptr=temp->lptr;
		printf("%d is removed\n",temp->value);
		free(temp);
	}
}
void display(struct node*H)
{
	struct node*temp;
	temp=H;
	if(temp==NULL)
		printf("List is empty\n");
		
		printf("The number in list is....");
	do
	{
		printf("%d\n",temp->value);
		temp=temp->rptr;
	}while(temp!=H);
}
void main() {
	int val,n,sval;
	struct node*head;
	struct node*Rear;
	head=Rear=NULL;
	printf("1. Insert At Front \n2. Insert At End \n3. Insert in order  \n4.Insert after element \n5. Delete at Front \n6. Delete at End \n7. Delete after element \n8. Display\n 9. EXIT ");
	do
	{
		printf("\nEnter choice : ");
		scanf("%d",&n);
		switch(n)
			{
			case 1:printf("Enter value to insert at front : ");
				scanf("%d",&val);
				insertatfront(&head,&Rear,val);
				break;
			case 2:printf("Enter value to insert at end : ");
				scanf("%d",&val);
				insertatend(&head,&Rear,val);
				break;
			case 3:printf("Enter value you want to insert = ");
				scanf("%d",&val);
				insertinorder(&head,&Rear,val);
				break;
			case 4:
				printf("Enter the value of node = ");
				scanf("%d",&val);
				insertafter(&head,&Rear,val);
				break;
			case 5:deleteatfront(&head,&Rear);
				break;
			case 6:deleteatend(&head,&Rear);
				break;
			case 7:printf("Enter value to be deleted : ");
				scanf("%d",&val);
				deleteafter(&head,&Rear,val);
				break;
			case 8: printf("Linked List : ");
				display(head);
				break;
			case 9:printf("EXIT");
		}
	}while(n!=9);
}
/* ""OUTPUT""

1. Insert At Front
2. Insert At End
3. Insert in order
4.Insert after element
5. Delete at Front
6. Delete at End
7. Delete after element
8. Display
 9. EXIT
Enter choice : 1
Enter value to insert at front : 10

Enter choice : 2
Enter value to insert at end : 20

Enter choice : 2
Enter value to insert at end : 30

Enter choice : 3
Enter value you want to insert = 25

Enter choice : 8
Linked List : The number in list is....
10
20
25
30

Enter choice : 4
Enter the value of node = 27
Enter after which element you want to insert = 25

Enter choice : 8
Linked List : The number in list is....
10
20
25
27
30

Enter choice : 5
10 is removed

Enter choice : 6
30 is removed

Enter choice : 7
Enter value to be deleted : 27
27 is removed

Enter choice : 8
Linked List : The number in list is....
20
25

Enter choice : 9
EXIT

*/