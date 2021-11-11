// program to implement a queue using array.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Queue
{
    int capacity;
    int front, rear;
    int *ptr;
};

struct Queue* createQueue(int cap)
{
    struct Queue* Q;
    Q = (struct Queue*)malloc(sizeof(struct Queue));
    Q->capacity = cap;
    Q->rear = -1;
    Q->front = -1;
    Q->ptr = (int*)malloc(sizeof(int)*cap);
    return Q;
}

void insertion(struct Queue *Q, int data)    //inserts in Queue
{
    if(Q->rear+1==Q->capacity && Q->front==0 || Q->rear == Q->front-1)
        printf("Overflow");
    else
    {
    if(Q->front == -1 && Q->rear == -1)
    {
        Q->front++;
        Q->rear++;
    }
    else if(Q->rear+1 == Q->capacity)
        Q->rear = 0;
    else
    {
        Q->rear++;
    }
    Q->ptr[Q->rear] = data;
    }
}

void deletion(struct Queue *Q)    //pops from Queue
{
    if(Q->front==-1)
        printf("Underflow");
    else if(Q->front == Q->rear){
        Q->front = -1;
        Q->rear = -1;
    }
    else if(Q->front == Q->capacity-1){
        Q->front = 0;
    }
    else{
        Q->front++;
    }
}

void view(struct Queue *Q)    //peeks in Queue
{
    if(Q->front == -1)
        printf("\nNothing to view");
    else
        printf("%d\n",Q->ptr[Q->front]);
}

main()
{
    struct Queue *Q;
    int cap;
    printf("Enter the size of Queue : ");
    scanf("%d",&cap);
    Q = createQueue(cap);   // Q is created.

    // Now perform whatever you want to implement by calling functions made for each purpose.
}