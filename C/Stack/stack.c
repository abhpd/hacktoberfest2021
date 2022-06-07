#include<stdio.h>
#include<stdlib.h>

//**Stack is a last in first out data structure.**

//we define a stack of size 4 to keep integer values
#define size 4 

//this stack is created using an array. Variable top is used as the stack pointer  
int top=-1, stack[size];

//push function is used to push a new integer into the stack
void push(int input);

//retrieve the latest value inserted 
void pop();

//function to display the entire stack at the current point of time
void display();
  
int main()
{
    int choice;
    int inp;
    int popped;
     
    while(1)    
    {
        printf("\nSelect the operation");
        printf("\n1.Push element\n2.Pop element\n3.Display the stack\n4.Quit");
        printf("\n\nEnter the choice:");
        scanf("%d",&choice);
         
        // this switch manages the user's choise
        switch(choice)
        {
            case 1: printf("\nPlease input the integer value to push : ");
            		scanf("%d",&inp);
					push(inp);
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
             
            default: printf("\nInvalid choice!!");
        }
    }
}
  
void push(int input)
{
     
    if(top==size-1)
    {
        printf("\n--Oops!!Overflow situation\n");
    }
    else
    {
        top=top+1;
        stack[top]=input;
    }
}
  
void pop()
{
    if(top==-1)
    {
        printf("\n--Oops!!Underflow situation\n");
        
    }
    else
    {
        printf("\n--Popped values is : %d\n",stack[top]);
        top=top-1;
    }
}
  
void display()
{   
	int i;
    if(top==-1)
    {
        printf("\n--Stack is Empty-- \n\n");
    }
    else
    {
        printf("\n--Elements in the stack: \n");
        for(i=top;i>=0;--i)
            printf(" %d ",stack[i]);
    }
}

