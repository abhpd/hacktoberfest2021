//Queue using Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

struct Node *rear=NULL, *front=NULL, *newNode, *ptr;

void Insert(){
   newNode=(struct Node*)malloc(sizeof(struct Node));
   printf("Enter a number\n");
   scanf("%d", &newNode->data);
   newNode->next=NULL;
   if(front==NULL){
      front=newNode;
      rear=newNode;
   }
   else{
      if(front->next==NULL){
         front->next=newNode;
         rear=newNode;
      }
      else{
         rear->next=newNode;
         rear=newNode;
      }
   }
}

void Delete(){
   if(front==NULL){
      printf("Underflow\n");
      return;
   }
   else{
      ptr=front;
      front=front->next;
      free(ptr);
   }
}

void Display(){
   ptr=front;
   if(front==NULL){
      printf("Queue is empty\n");
   }
   else{
      printf("The values in the Queue are:\n");
      while(ptr!=NULL){
         printf("%d\n", ptr->data);
         ptr=ptr->next;
      }
   }
}

int main(){
int k;
while(k!=4){
   printf("\n1.Insert an element in the queue  2. Delete an element from the queue  3.Display the queue  4.Exit\n");
   printf("Enter your choice\n");
   scanf("%d", &k);
   switch(k){
      case 1:
      Insert();
      break;

      case 2:
      Delete();
      break;

      case 3:
      Display();
      break;

      case 4:
      printf("Exiting...");
      break;

      default:
      printf("Invalid Choice!!");
   }
}
return 0;
}