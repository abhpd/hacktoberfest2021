#include <stdio.h>  
  
# define max 5 
int queue[max];  // array declaration  
int front=-1;  
int rear=-1;  
// function to insert an element in a circular queue  
void enqueue(int element)  
{  
    if(front==-1 && rear==-1)   // condition to check queue is empty  
    {  
        front=0;  
        rear=0;  
        queue[rear]=element;  
    }  
    else if((rear+1)%max==front)  // condition to check queue is full  
    {  
        printf("Queue is overflow..\n");  
    }  
    else  
    {  
        rear=(rear+1)%max;       // rear is incremented  
        queue[rear]=element;     // assigning a value to the queue at the rear position.  
    }  
}  
  
// function to delete the element from the queue  
int dequeue()  
{  
    if((front==-1) && (rear==-1))  // condition to check queue is empty  
    {  
        printf("Queue is underflow..\n");  
    }  
 else if(front==rear)  
{  
   printf("\nThe dequeued element is %d\n", queue[front]);  
   front=-1;  
   rear=-1;  
}   
else  
{  
    printf("\nThe dequeued element is %d\n", queue[front]);  
   front=(front+1)%max;  
}  
}  
// function to display the elements of a queue  
void display()  
{  
    int i;  
    printf("Queue elements are\n");
    if((front==-1) && (rear==-1))  // condition to check queue is empty  
    {  
        printf("Queue is underflow..\n");  
    } 
    else if (front > rear)
    {
        for (i = front; i < max; i++)
        {
            printf("%d\t ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d\t ", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t ", queue[i]);
    }
}

int main()  
{  
    int choice=1,x;   // variables declaration  
      
    while(choice<4 && choice!=0)   // while loop  
    {  
    printf("\t Press 1: Insert an element");  
    printf("\tPress 2: Delete an element");  
    printf("\tPress 3: Display the element");  
    printf("\nEnter your choice\n");  
    scanf("%d", &choice);  
      
    switch(choice)  
    {  
          
        case 1:  
      
        printf("Enter the element which is to be inserted\n");  
        scanf("%d", &x);  
        enqueue(x);  
        break;  
        case 2:  
        dequeue();  
        break;  
        case 3:  
        display();  
  
    }}  
    return 0;  
} 