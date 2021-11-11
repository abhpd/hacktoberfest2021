#include<stdio.h>
#include<math.h>

#define Size 10

void push(int stack[], int *top, int value)
{
    if(*top == Size-1)
        printf("\n Stack is already full.");
    else{
        (*top)++;
        stack[*top] = value;
        printf("\n Insertion successful..!!");
    }
}

void pop(int stack[], int *top)
{
    if(*top == -1)
        printf("\n Stack is empty, can't delete");
    else{
        (*top)--;
        printf("\n Deletion successful..!!");
    }
}

void peek(int stack[], int *top)
{
    if(*top == -1)
        printf("\n Stack is empty");
    else{
        printf(" %d",stack[*top]);
    }
}

int main()
{
    int stack[Size], top=-1;
    int value,choice;
    while(1)
    {
        printf("\n\n****MENU****\n");
        printf("\n 1. Insert item into the stack");
        printf("\n 2. Delete item from the stack");
        printf("\n 3. Peek into the stack");
        printf("\n 4. Exit");
        printf("\n Choose an option : ");
        scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\n Enter the value : ");
            scanf("%d",&value);
            push(stack,&top,value);
            break;
        case 2:
            pop(stack,&top);
            break;
        case 3:
            peek(stack,&top);
            break;
        case 4:
            return 0;
        default:
            printf("\n Invalid choice\n");
    }
    }
}