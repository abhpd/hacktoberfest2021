#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *top=0;

void push()
{
    int x;
    printf("Enter digit: ");
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}

void pop()
{
    struct node *temp=top;
    if(top==0)
    {
        printf("Empty stack\n");
    }
    else
    {
        
        printf("The deleted item is %d",temp->data);
        top=temp->next;
        free(temp);
        
    }
}

void display()
{
    struct node *temp=top;
    if(top==0)
    {
        printf("Empty stack\n");
    }
    else
    {
        while(temp->next!=0)
        {
            printf("%d",temp->data);
            temp=temp->next;
            
        }
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
            break;
            case 2: pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
        }
        
    }
}
