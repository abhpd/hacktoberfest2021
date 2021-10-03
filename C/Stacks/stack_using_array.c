//#include <stdio.h>
//#include <stdlib.h>
int stack[100], SIZE, top=-1;

//function prototypes
int push(int);
int pop();
void traverse();


void main ()
{
 int choice, ret, data;
 printf("Enter the size of your stack: \t");
 scanf("%d",&SIZE);

 while(1)
 {

 printf("\n----------------------------------------------\n");
 printf("\t Stack operations using array \t");
 printf("\n----------------------------------------------\n");
 printf("1.Push \t 2.Pop \t 3.Traverse \t 4.Exit \n");
 printf("\nEnter your choice: ");
 scanf("%d",&choice);
 if(SIZE<=100)

{
 if(choice==1)
 {
printf("Enter data to push into stack: ");
 scanf("%d",&data);
 if(top>=SIZE-1)
 {
printf("*** Stack Overflow, can't add more element element to stack.\n");
 }
 else
 {
printf("*** Data pushed to stack.\n");
 push(data);
 }
 
 }
 else if(choice==2)
 {
if(top==-1)
{
printf("*** Stack underflow.\n");
}
else
{ ret=pop();
printf("*** Data removed ==> %d\n",ret);
}
 
 }
 else if(choice==3)
 {
if(top==-1)
{
 printf("Stack is empty");
 }
else
{
 traverse();
}
 
 }
 else if(choice==4)
 {
 printf("Exiting....\n");
 break;
 }
 else
 {
 printf("Please Enter valid choice ");
 }
 }
 }
}



int push(int data)
{
 stack[++top]=data;
}



int pop()
{
 return stack[top--];
}


void traverse()
{
 for(int i=top;i>=0;i--)
 printf("\n%d",stack[i]);
}
