/*
 Write a program to implement queue data structure using linked list.
*/

#include <stdio.h>
#include <stdlib.h>

// creating a node
struct Node{
  int data;
  struct Node* next;
};

// two trackers front and rear to keep track of front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// function to insert elements in the queue
void enqueue(){
   int num;
   struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));

   printf("Enter the number you want to insert: ");
   scanf("%d", &num);

   temp ->data = num;
   temp ->next = NULL;
   if(front == NULL && rear == NULL){
       front = rear = temp;
   }
   else {
      rear ->next = temp;
      rear = temp;
   }
}

// function to delete element from the queue
void dequeue(){
   struct Node* temp = front;
   if (front == NULL){
      printf("The list is empty");
   }
   else if ( front == rear){
      front = rear = NULL;
   }
   else {
      front = front->next;
      free(temp);
   }
}

// to display the queue
void display(){
   struct Node* temp = front;
   printf("The list is: ");
   while (temp != NULL){
      printf(" %d ", temp ->data);
      temp = temp ->next;
   }
   printf("\n");
}

int main()
{
    // asking user for the choices to perform an operation
   int choice;
   while(1){
      printf("Enter your choice: \n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit\n");
      scanf("%d", &choice);
      switch(choice){
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
            return 0;
         default:
            printf("Enter valid choice");
            break;
      }
   }
}
