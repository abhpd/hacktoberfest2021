#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int num)
{
    struct node * temp;
    temp = (struct node *) malloc(sizeof(struct node));
    if(temp == NULL){
        printf("No memory");
    }
    else{

        temp->data = num;
        temp->next = NULL;
        if(front == NULL && rear == NULL){
            front = rear = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

int dequeue()
{
    int x = -1;
    if(front == NULL && rear == NULL){
        printf("\nUnderflow / Queue is empty");
    }
    else{
        struct node * temp;
        temp = front;
        front = front->next;
        x = temp->data;
        free(temp);
        return x;
    }
}

void display()
{
    if(front == NULL && rear == NULL){
        printf("\nUnderflow / Queue is empty");
    }
    else{
        struct node * temp;
        temp = front;
        printf("\n");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void peek()
{
    if(front == NULL && rear == NULL){
        printf("\nUnderflow / Queue is empty");
    }
    printf("\n%d",front->data);
}

void queue_add(int pos)
{
    struct node * temp = front; 
    for(int i=0;i<pos-1;i++){
        temp = temp->next;
    }
    printf("\nEnter data: ");
    scanf("%d",&temp->data);

}

void main()
{   
    int num,val;
    int pos;
   while(1){
        printf("\nEnter 1 for enqueing value in the queue: ");
        printf("\nEnter 2 for dequeing value in the queue: ");
        printf("\nEnter 3 to peek value in the queue: ");
        printf("\nEnter 4 to display value in the queue: ");
        printf("\nEnter 5 to enter value at a specified position: ");
        printf("\nEnter 6 to exit\n");
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                printf("\n%d was deleted ",dequeue());
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d",&pos);
                queue_add(pos);
                break;
            case 6:
                printf("\nExiting");
                exit(0);
            default:
                printf("\nWrong input!!");
                exit(0);
        }


    }  
}
