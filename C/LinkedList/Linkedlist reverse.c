#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node *link;
};
struct node* insert_begin(struct node *head,int value)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->link=head;
	head=temp;
	return head;
}
struct node* insert_end(struct node *head, int value)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	p=head;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=temp;
	temp->link=NULL;
	return head;
}
struct node* insert_any_position(struct node *head,int value)
{
	struct node *temp,*p;
	int pos,i;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	printf("Enter your position to insert:\n");
	scanf("%d",&pos);
	p=head;
	for(i=1;i<pos-1;i++)
		p=p->link;
	temp->link=p->link;
	p->link=temp;
	return head;
}
struct node* delete(struct node *head,int item)
{
	struct node *temp,*p;
	temp=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("List is empty");
		return head;
	}
	if(head->link==NULL && head->data==item)
	{
		temp=head;
		head=NULL;
		free(temp);
		return head;
	}
	else if(head->link==NULL && head->data!=item)
	{	
		printf("element not found\n");
		return head;
	}
	if(head->data==item)
	{
		temp=head;
		head=head->link;
		free(temp);
		return head;
	}
	p=head;
	while(p->link!=NULL)
	{
		if(p->link->data==item)
		{
			temp=p->link;
			p->link=temp->link;
			free(temp);
			return head;
		}
	p=p->link;
	}
}
struct node* reverse(struct node *head)
{
	struct node *ptr,*prev,*next;
	ptr=head;
	prev=NULL;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	head=prev;
	return head;
}
void display(struct node *head)
{
	struct node *p;
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}	
	p=head;
	printf("The single link list is:\n");
	while(p->link!=NULL)
	{
		printf("%d->",p->data);
		p=p->link;
	}
	printf("%d\n",p->data);

}
int main(void)
{
	int n,ch,value,item;
	struct node *head=NULL;
	while(1)
	{
		printf("link menu is:\n");
		printf("1. insert at begin\n");
		printf("2. insert at end\n");
		printf("3. insert any position\n");
		printf("4. delete item\n");
		printf("5. reverse the link list:\n");
		printf("6. display\n");
		printf("7. exit\n");
		printf("Enter your choice(1-7):\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value to insert:\n");
						  scanf("%d",&value);
						  head=insert_begin(head,value);
					 	 break;
			case 2: printf("Enter the value to insert:\n");
						  scanf("%d",&value);
						  head=insert_end(head,value);
					 	  break;
			case 3: printf("Enter the value to insert any position:\n");
						  scanf("%d",&value);
						  head=insert_any_position(head,value);
					 	  break;
			case 4: printf("Enter the item to delete in the link list:\n");
						  scanf("%d",&item);
						  head=delete(head,item);
					 	  break;
			case 5: head=reverse(head);
					 	  break;
			case 6: display(head);
					 	  break;
			case 7: exit(0);
		}
	}
	return 0;
}
							
		
	
	
	