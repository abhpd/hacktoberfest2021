// Simulation of Queue using Array
#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void enqueue();
void dequeue();
void display();
int front = -1, rear = -1;
int queue[maxsize];

void main ()
{

 int choice;
 while(choice != 4)
       {

         printf("\nChoose any option from below\n");
         printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
         printf("\nEnter your choice:\n");

 scanf("%d",&choice);

 switch(choice)
   {
    case 1:
    enqueue();
    break;

    case 2:
    dequeue();
    break;

    case 3:
    display();
    break;

    case 4:
    exit(0);
    break;
    default:
 printf("\nEnter valid choice??\n");
   }
       }
}

void enqueue()
{
 int item;
 printf("\nEnter the element\n");
 scanf("\n%d",&item);
 if(rear == maxsize-1)
 {
 printf("\nOVERFLOW\n");
 return;
 }
 if(front == -1 && rear == -1)
 {
 front = 0;
 rear = 0;
   queue[rear]= item;
 }
 else
 {
 rear = rear+1;
 }
 queue[rear] = item;
 printf("\nValue enqueueed ");
}

void dequeue()
{
 int item;
 if (front == -1 || front > rear)
 {
 printf("\nUNDERFLOW\n");
 return;
 }
 else
 {
 item = queue[front];
 if(front == rear)
 {
 front = -1;
 rear = -1 ;
 }
 else
 {
 front = front + 1;
 }
 printf("\nvalue dequeued ");
 }
}

void display()
{
 int i;
 if(rear == -1)
 {
 printf("\nEmpty queue\n");
 }
 else
 { printf("\n.............printing values ..............\n");
 for(i=front;i<=rear;i++)
 {
 printf("\n%d\n",queue[i]);
 }
 }
 }
