#include<stdio.h>
#include<stdlib.h>
#include<process.h>

void Input_restricted();
void Output_restricted();

void Insert_front();
void Insert_rear();
void Delete_front();
void Delete_rear();
void Display_Dequeue();

int Dequeue[100],front=-1,rear=-1,size;

int main()
{
  int choice;

  while(1)
  {
   printf("\n\nCHOOSE THE TYPE OF DEQUEUE:\n");
   printf("\n1 - Input restricted Dequeue.\n2 - Output restricted Dequeue.\n3 - Stop executing.\n");
   scanf("%d",&choice);

   switch(choice)
   {
	      case 1: Input_restricted();
		          break;
		  case 2: Output_restricted();
		          break;
          case 3: exit(0);
                  break;
		  default: printf("Wrong Choice!");
		           break;
   }
  }
  return 0;
}


void Input_restricted()
{
    int ch;
    printf("Enter the size of Dequeue to be formed: ");
    scanf("%d",&size);
    while(1)
    {
       printf("\n\nOPERATIONS ON INPUT RESTRICTED DEQUEUE\n");
       printf("\nChoose:\n1 - Insert from end.\n2 - Delete from beginning.\n3 - Delete from end.\n4 - Display the dequeue.\n5 - Stop executing.\n");
       scanf("%d",&ch);

       switch(ch)
       {
	      case 1: Insert_rear();
		          break;
		  case 2: Delete_front();
		          break;
          case 3: Delete_rear();
                  break;
          case 4: Display_Dequeue();
                  break;
          case 5: front=rear=-1;
                  return;
		  default: printf("Wrong Choice!");
		           break;
       }
    }

}


void Output_restricted()
{
    int ch;
    printf("Enter the size of Dequeue to be formed: ");
    scanf("%d",&size);
    while(1)
    {
       printf("\n\nOPERATIONS ON INPUT RESTRICTED DEQUEUE\n");
       printf("\nChoose:\n1 - Insert from beginning.\n2 - Insert from end.\n3 - Delete from beginning.\n4 - Display the dequeue.\n5 - Stop executing.\n");
       scanf("%d",&ch);

       switch(ch)
       {
	      case 1: Insert_front();
		          break;
		  case 2: Insert_rear();
		          break;
          case 3: Delete_front();
                  break;
          case 4: Display_Dequeue();
                  break;
          case 5: front=rear=-1;
                  return;
		  default: printf("Wrong Choice!");
		           break;
       }
    }

}

void Insert_front()
{
    int element,i;
    if(front==0 && rear==size-1)
        {
          printf("\nOVERFLOW!Cannot insert more elements!");
          return;
        }
    else if(front==0)
       printf("\nCannot be inserted from the front!\n");

    else
    {
        printf("\nEnter element to be inserted in the Queue: ");
        scanf("%d",&element);
        if(front==-1)
        {   front=0;
            rear=0;
            printf("\nSince the Queue is empty, the element %d cannot be inserted from the front.",element);
            Dequeue[rear]=element;
            printf("\nElement %d has been inserted from the rear.\n",element);
        }
        else
        {
            front-=1;
            Dequeue[front]=element;
            printf("\nElement %d has been inserted from the front.\n",element);
        }

    }
}

void Insert_rear()
{
     int element;
    {
       if(rear==size-1)
        {
          printf("\nOVERFLOW!Cannot insert more elements!");
          return;
        }
       else
       {
          printf("\nEnter element to be inserted in the Queue: ");
          scanf("%d",&element);
          if(front==-1)
          {   front=0;
              rear=0;
          }
          else
              rear+=1;
          Dequeue[rear]=element;
          printf("\nElement %d has been inserted from the rear.\n",element);
       }
    }

}

void Delete_front()
{
     if(front==-1)
         printf("\nUNDERFLOW! Empty dequeue! No elements found for deletion.\n");
     else
     {
  	     if(front==rear)
  	        front=rear=-1;
  	     else
  	        front+=1;
         printf("\nElement %d has been deleted from the front.\n",Dequeue[front-1]);
  	 }
}

void Delete_rear()
{
     if(front==-1)
         printf("\nUNDERFLOW! Empty queue! No elements found for deletion.\n");
     else
     {
  	     if(front==rear)
  	        front=rear=-1;
  	     else
  	        rear-=1;
        printf("\nElement %d has been deleted from the rear.\n",Dequeue[rear+1]);
  	 }
}

void Display_Dequeue()
{
	int i;
	if(front==-1)
	   printf("Empty queue! No elements found.\n");
	else
	{
	    printf("\nNow the Queue is: \n");
		for(i=front;i<=rear;i++)
		     printf("%d   ",Dequeue[i]);
	}
}


