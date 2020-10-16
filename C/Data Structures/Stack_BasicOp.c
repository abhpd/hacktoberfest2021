#include<stdio.h>
#include<stdlib.h>
#define MAX 8
int stack[MAX];
char charstack[MAX];
int top=-1,TOP=-1;

void push(void);
void pop(void);
int peek(void);
int isfull(int);
int isempty(int);
int pushchar(void);
void popchar(void);
void peekchar(void);

int main()
{
int ch;
printf("Stack Operation Menu:\n 1. Push integer\n 2. Pop integer\n 3. Peek integer\n 4. Push character\n 5. Pop character\n 6. Peek character\n 7. Exit\n");
while(1){
printf("\n Which operation do you want to perform: ");
scanf("%d",&ch);
switch(ch){
    case 1:
            {
                push();
                break;
            }
    case 2:
            {
                pop();
                break;
            }
    case 3:
            {
                int result=peek();
                if(result==-1){
                    printf("Stack is Empty!\n");
                }
                else
                    printf("The top element is: %d\n",result);
                break;
            }
    case 4:
            {
                int Result=pushchar();
                if(Result==0){
                    printf("OVERFLOW! Stack is Full.\n");
                }
                else{
                    char s;
                    printf("Enter the character to be inserted: ");
                    scanf(" %c",&s);
                    charstack[TOP]=s;
                    printf("%c inserted successfully\n",s);
                }
                break;
            }
    case 5:
            {
                popchar();
                break;
            }
    case 6:
            {
                peekchar();
                break;
            }
    case 7:
            {
                exit(0);
            }
    default:
                printf("Choose from Operation 1-6\n");
                break;
    }
}
return 0;
}

void push()             //to add an element to the top of stack (number)
{
    int ele;
    top++;
    if(isfull(top))
        printf("OVERFLOW! Stack is Full.\n");
    
    else
    {
        printf("Enter the element to be inserted: ");
        scanf("%d",&ele);
        stack[top]=ele;
        printf("%d inserted successfully\n",ele);
    }
}

void pop()              //to delete the top element from stack (number)
{
    if(isempty(top))
    {
        printf("UNDERFLOW! Stack is Empty.\n");
    }
    else
    {
        printf("Top element: %d deleted successfully\n",stack[top]);
        top--;
    }
}

int peek()              //to view top element of the stack (number)
{
    if(isempty(top))
        return -1;
    
    else
        return stack[top];
    
}

int pushchar()          //to add an element to the top of stack (character)
{
    TOP++;
    if(isfull(TOP)){
        return 0;
    }
    else{
        return 1;
    }
}

void popchar()              //to delete the top element from stack (character)
{
    if(isempty(TOP)){
        printf("UNDERFLOW! Stack is Empty.\n");
    }
    else{
        printf("Top element: %c deleted successfully\n",charstack[TOP]);
        TOP--;
    }
}

void peekchar()             //to view top element of the stack (character)
{
    if(isempty(TOP))
        printf("Stack is Empty.\n");
    
    else
        printf("The top element is: %c\n",charstack[TOP]);
}

int isfull(int Top)         //To check if stack if full or not
{
    if(Top==MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(int Top)        //To check if stack is empty or not
{
    if(Top==-1)
        return 1;
    
    else
        return 0;
}
