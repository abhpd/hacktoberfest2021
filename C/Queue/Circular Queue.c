//Program to implement circular queue
#include<stdio.h>
#define MAX 5
int QUEUE[MAX];
int FRONT=-1;
int REAR=-1;

// Function to insert
void CQINSERT(int ITEM)
{
    if((FRONT==0 && REAR==MAX-1) || (FRONT==REAR+1))
    {
        printf("CIRCULAR QUEUE OVERFLOW");
        return;
    }
    else if(REAR==-1)
    {
        FRONT=0;
        REAR=0;
    }
    else
    {
        if(REAR==MAX-1)
            REAR=0;
        else
            REAR+=1;
    }
    QUEUE[REAR]=ITEM;
}

// Function to Delete
int CQDELETE()
{
    int x;
    if(FRONT==-1)
    {
        printf("CIRCULAR QUEUE UNDERFLOW");
        return -1;
    }
    x=QUEUE[FRONT];
    if(FRONT==REAR)
    {
        FRONT=-1;
        REAR=-1;
    }
    else if(FRONT==MAX-1)
    {
        FRONT=0;
    }
    else
    {
        FRONT+=1;
    }
    return x;
}

// Function to traverse
void CQTRAVERSE()
{
    int i;
    if(FRONT==-1)
        printf("EMPTY!");
    else if(REAR<FRONT)
    {
        for(i=FRONT;i<MAX;i++)
            printf("%d\t",QUEUE[i]);
        for(i=0;i<=REAR;i++)
            printf("%d\t",QUEUE[i]);
    }
    else
    {
        for(i=FRONT;i<=REAR;i++)
            printf("%d\t",QUEUE[i]);
    }
}

// Main method
int main()
{
    int item,ch=0;
    while(ch!=4)
    {
        printf("\n 1.INSERT \n 2.DELETE \n 3.TRAVERSE \n 4.QUIT \n ENTER YOUR CHOICE : ");  // Taking user's choice
        scanf("%d",&ch);
        switch(ch)  // To perform according to user's choice
        {
        case 1:
            printf("\nEnter element to Insert : ");
            scanf("%d",&item);
            CQINSERT(item);
            break;
        case 2:
            item=CQDELETE();
            if(item!=-1)
                printf("%d has been Deleted",item);
            break;
        case 3:
            CQTRAVERSE();
            break;
        case 4:
            break;
        default:
            printf("INVALID CHOICE !");
        }
    }
    return 0;
}
