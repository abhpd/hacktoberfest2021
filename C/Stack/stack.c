// 3. Implement a program for stack that performs following operations using array.

// (a) PUSH (b) POP (c) PEEP (d) CHANGE(Replace top of stack value) (e) DISPLAY

#include <stdio.h>
#include <stdlib.h>

#define  size 10

int isFull();
int isEmpty();
void push(int value);
int pop();
int peep();
void change(int value);
void display();

int top = -1;
int stack[size];

int main(){
    int operation, value;

    printf("\n Ahmed Aghadi-200420107043");

    do{
        
        system("cls");
        printf("\n***********************\n");
        printf("Enter 1 to PUSH, 2 to POP, 3 to PEEP, 4 to CHANGE, 5 to DISPLAY and 6 to exit");
        printf("\n***********************\n");

        scanf("%d",&operation);

        switch(operation){
            case 1: 
            printf("\nEnter value to be pushed : ");
            scanf("%d",&value);
            push(value);
            break;

            case 2: 
            value = pop();
            printf("\n %d \n",value);
            break;

            case 3: 
            value = peep();
            printf("\n %d \n",value);
            break;
            
            case 4: 
            printf("\nEnter value to be changed : ");
            scanf("%d",&value);
            change(value);
            break;

            case 5: 
            display();
            break;

            case 6:
            break;

            default:
            printf("\nEnter value between 1 and 5.");
        }

        system("pause");
    }while(operation != 6);
}

int isFull(){
    if(top>=size-1){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push(int value){
    if(isFull()){
        printf("Stack is Full!");
        exit(0);
    }

    top++;
    stack[top] = value;
}

int pop(){
    if(isEmpty()){
        printf("Stack is Empty!");
        exit(0);
    }

    top--;
    return stack[top+1];
}

int peep(){
    if(isEmpty()){
        printf("Stack is Empty!");
        exit(0);
    }

    return stack[top];
}

void change(int value){
    if(isEmpty()){
        printf("Stack is Empty!");
        exit(0);
    }

    stack[top] = value;
}

void display(){
    int i;
    if(isEmpty()){
        printf("Stack is Empty!");
        exit(0);
    }

    for(i = 0; i <= top; i++){
        printf("\n %d",stack[top-i]);
    }
    printf("\n");
}

