#include<stdio.h>
#include<stdlib.h>
struct node
{	
	int data;
	struct node *link;
};
struct node* push(struct node *top,int value)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=value;
	temp->link=NULL;
	if(top==NULL)
	{
		top=temp;
		return top;
	}
	else{
	
		temp->link=top;
		top=temp;
		return top;
	}
}
struct node* pop(struct node *top)
{
	struct node *temp;
	if(top==NULL)
	{
		printf("stack is empty!\n");
		return top;
	}
	else{
		temp=top;
		printf("poped element is: %d\n",temp->data);
		top=top->link;
		free(temp);
		return top;
	}
}

void display(struct node *top)
{
	struct node *p;
	p=top;
	if(top==NULL)
	{
		printf("stack is empty!\n");
	}
	printf("The stack is:\n")
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
	struct node *top=NULL;
	while(1)
	{
		printf("stack menu is:\n\n");
		printf("1. push element\n");
		printf("2. pop element\n");
		printf("3. display\n");
		printf("4. exit\n\n");
		printf("Enter your choice(1-4):\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value to push:\n");
			        scanf("%d",&value);
				 top=push(top,value);
				 break;
			case 2: top=pop(top);
			        break;
			case 3: display(top);
				 break;
			case 4: exit(0);
			default: printf("Wrong choice!\n");
		}
	}
	return 0;
}
							
		
	