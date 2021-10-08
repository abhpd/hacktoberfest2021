#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode()
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    return(ptr);
}

void pushInQueue(struct node **front, struct node **rear, int value)
{
    struct node *temp;
    temp = createNode();
    temp->data = value;
    temp->next = NULL;
    if(*rear == NULL)
        *front = *rear = temp;
    else{
        *rear->next = temp;
    }
}

void popFromQueue(struct node **front, struct node **rear)
{
    struct node *t;
    if(*front == NULL)
        printf("\nUnderflow");
    else if(*front == *rear)
    {
        free(*front);
        *front = NULL;
        *rear = NULL;
    }
    else{
        t = *front;
        *front = *front->next;
        free(t);
    }
}

main()
{
    struct node* front = NULL;
    struct node *rear = NULL;
}