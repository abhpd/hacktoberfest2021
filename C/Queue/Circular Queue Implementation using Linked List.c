#include<stdio.h>
#include<stdlib.h>
#define m 5

struct node
{
	int data;
	struct node *nxt;
};

typedef struct
{
	struct node *r;
}queue;

int insert(queue *q, int n)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Insetion Not Possible.\n");
		return 1;
	}
	ptr->data=n;
	ptr->nxt=NULL;
	if(q->r==NULL)
	{
		q->r=ptr;
		q->r->nxt=q->r;
	}
	else
	{
		ptr->nxt=q->r->nxt;
		q->r->nxt=ptr;
		q->r=ptr;
	}
	return 0;
}

int delete(queue *q, int *n)
{
	if(q->r==NULL)
	{
		printf("Deletion Not Possible.\n");
		return 1;
	}
	if(q->r==q->r->nxt)
	{
		*n=q->r->data;
		free(q->r);
		q->r=NULL;
	}
	else
	{
		struct node *ptr=q->r->nxt;
		q->r->nxt=ptr->nxt;
		*n=ptr->data;
		free(ptr);
	}
	return 0;
}

int main()
{
	queue q;
	q.r=NULL;
	int n,x,y;
	for(int i=0; i<m;i++)
	{
		scanf("%d",&n);
		x=insert(&q,n);
	}
	y=delete(&q,&n);
	printf("%d ",n);
	y=delete(&q,&n);
	printf("%d ",n);
	printf("\n");
}
