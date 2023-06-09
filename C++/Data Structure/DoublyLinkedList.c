#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head;

struct node *head=NULL;

void create(int data)
{
    struct node *temp, *q;
    temp=malloc(sizeof(struct node));

    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        temp->prev=NULL;
        head=temp;
    }    
    else
    {
        q=head;
        while(q->next!=NULL)
        {
            q=q->next;
        }

        q->next=temp;
        temp->prev=q;
    }
}

void display()
{
    struct node *q;

    if(head==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("\nLinked List\n");

        q=head;

        printf("NULL->");

        while(q!=NULL)
        {
            printf("%d<->",q->data);
            q=q->next;
        }
        printf("NULL");
    }
}

void search(int s)
{
    struct node *q;

    int pos=1;

    q=head;

    while(q!=NULL)
    {
        if(q->data==s)
        {
            printf("\nElement %d Found at %d Position\n",q->data,pos);
            return;
        }
        q=q->next;
        pos++;
    }

    printf("Element Not Found\n");
}

void count()
{
    struct node *q;

    int count=0;

    if(head==NULL)
    {
        printf("Count = %d\n",count);
    }
    else
    {
        q=head;

        while(q!=NULL)
        {
            count++;
            q=q->next;
        }

        printf("\nCount = %d\n",count);
    }
}

void insert(int ins,int pos)
{
    struct node *temp, *q;
    temp=malloc(sizeof(struct node));

    temp->data=ins;

    if(pos==1)
    {
        head->prev=temp;
        temp->next=head;
        temp->prev=NULL;
        head=temp;
    }
    else
    {
        q=head;
        
        for(int i=1;i<pos-1;i++)
        {
            q=q->next; 
        }
        
        if(q->next==NULL)
        {
            temp->next=NULL;
            temp->prev=q;
            q->next=temp;
        }
        else
        {
            q->next->prev=temp;
            temp->next=q->next;
            temp->prev=q;
            q->next=temp;
        }
    }
}

void delete(int del)
{
    struct node *temp,*q;

    if(head->next==NULL)
    {
        if(head->data==del)
        {
            temp=head;
            head=NULL;
            free(temp);
            return;
        }
    }

    if(head->data==del)
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return;
    }

    q=head;

    while(q->next->next!=NULL)
    {
        if(q->next->data==del)
        {
            temp=q->next;
            q->next=temp->next;
            temp->next->prev=q;
            free(temp);
            return;
        }
        q=q->next;
    }

    if(q->next->data==del)
    {
        temp=q->next;
        q->next=NULL;
        free(temp);
        return;
    }
}

void reverse()
{
    struct node *p1,*p2;

    p1=head;
    p2=p1->next;
    p1->next=NULL;
    p1->prev=p2;

    while(p2!=NULL)
    {
        p2->prev=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p2->prev;
    }
    head=p1;
}

int main()
{
    int data,n,s,ins,pos,del;

    printf("Enter the total number of nodes = ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter data to each node = ");
        scanf("%d",&data);
        create(data);
    }
    display();
    printf("\nEnter data you want to search = ");
    scanf("%d",&s);
    search(s);
    count();
    printf("\nEnter the data you want to insert and Position = ");
    scanf("%d %d",&ins,&pos);
    insert(ins,pos);
    display();
    printf("\nEnter the data you want to delete = ");
    scanf("%d",&del);
    delete(del);
    display();
    reverse();
    display();
}
