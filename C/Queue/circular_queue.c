//sharmmistha roy
//circular queue

#include<stdio.h>
#include<stdlib.h>
void insert();
void display();
void search();
int delete();
#define MAX 3
int ar[MAX];
int f=-1,r=-1;
main()
{
	int p,ch,i,k;
	do
	{
		printf("enter\n1 to insert data in queue\n2 to display\n3 to search a data\n4 to delete a data\n");
		scanf("%d",&p);
		switch(p)
		{
			case 1:	
			insert();
			break;
			case 2:
			display();
			break;
			case 3:
			search();
			break;
			case 4:
			k=delete();
			printf("%d is deleted\n",k);
			break;
		}
		printf("to continue further enter 0 otherwise enter any number to exit\n");
		scanf("%d",&ch);
	}while(ch==0);
}
void insert()
{
		int d;
		printf("enter data\n");
		scanf("%d",&d);
		if(f==-1&&r==-1)
		{
			f=r=0;
			ar[f]=d;
		}	
		else
		{
			if(f==0&&r==MAX-1)
				printf("queue is full\n");
			else if(f==r+1)
				printf("queue is full\n");
			else
			{
				r=(r+1)%MAX;
				ar[r]=d;
			}
		}
}
void display()
{
	int i;
	printf("displaying data\n");
	if(f==-1)
		printf("queue is empty\n");
	else
	{
		if(f<=r)
		{
			for(i=f;i<=r;i++)
				printf("%d\n",ar[i]);
		}
		else
		{
			for(i=f;i<MAX;i++)
				printf("%d\n",ar[i]);
			//for(i=0;i<=r;i++)
			//	printf("%d\n",ar[i]);

			if(r!=0)
			{
				for(i=0;i<=r;i++)
					printf("%d\n",ar[i]);
			}
			else
				printf("%d\n",ar[r]);
		}
	}
}
void search()
{
	int i,d,flag=0;
	printf("enter the number you want to search\n");
	scanf("%d",&d);
	if(f<=r)
	{
		for(i=f;i<=r;i++)
		{
			if(ar[i]==d)
			{
				flag=1;
				break;
			}
		}
	}
	else
	{
		for(i=f;i<MAX;i++)
		{
			if(ar[i]==d)
			{
				flag=1;
				break;
			}
		}
		for(i=0;i<=r;i++)
		{
			if(ar[i]==d)
			{
				flag=1;
				break;
			}
		}
	}
	if(flag==1)
	{
		printf("FOUND\n");
	}
	else
		printf("NOT FOUND\n");


}
int delete()
{
	int u;
	if(f!=-1&&r!=-1)
	{
		if(f==r)
		{
			u=ar[f];
			f=r=-1;
		}
		else
		{
			u=ar[f];
			f=(f+1)%MAX;
		}
	}
	else
		printf("queue is empty\n");
	return u;
}
