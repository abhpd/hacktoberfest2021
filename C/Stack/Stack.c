#include <stdio.h>
#include<string.h>

#define MAXSIZE 800 

// Defininging Stack with char for string
char stack[MAXSIZE][100];    

// Defininging Top
int top = -1;            

// Checking if the stack is empty or not
int isempty() {
   if(top == -1)
      return 1;
   else
      return 0;
}


// Checking if the satack is full or not
int isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}


// Printing the top element of the Stack
void peek() {
   printf("\n%s",stack[top]);
}

// Writing pop function i.e deleting the topmost element
void pop() {
   char data[100];
   if(!isempty()) {
    //   data = stack[top];
    strcpy(data,stack[top]);
      printf("\n%s -> deleted\n",data);
      top = top - 1;   
      
   } else {
      printf("Could not retrieve data, Stack is empty.\n\n");
   }
}


// Writing the push function or function for entering element
void push(char data[]) {

   if(!isfull()) {
      top = top + 1;   
    //   stack[top] = data;
      strcpy(stack[top],data);
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}


// Writing the display function to display the numbers entered
void display(){
    if(!isempty()){
        int i=0;
        printf("Items in the Stacks are.\n");
        for(i=top;i>=0;i--){
            printf("%d item -> %s\n",i+1,stack[i]);
        }
    }
    else{
        printf("Empty Stack");
    }
}

int main() {
   // push items on to the stack 
   push("Hi");
  push("There");
  push("How");
  push("Are");
  push("You");
  push("Fine");
//   Displaying elements that are pushed to top
   display();
   
//  Deleting tthe topmost element from stack
  pop();
   
   printf("\n");
   
   
//   Displaying elements that are pushed to top
  display();
 
   
   return 0;
}