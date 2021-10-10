#include<stdio.h>
int q[10],choice,queue_size,f,r,x,i; // Declaration of variables

void insert_rear();
void insert_front();
void delete_rear();
void delete_front();
void display();

int main()
{
 r = -1; 
 f=0;
 printf("\n Enter the size of QUEUE : ");
 scanf("%d",&queue_size);
 printf("\nQUEUE IMPLEMENTATION USING ARRAYS\n");
 do
 {
 printf("\n1.insert rear \n2.insert front \n3.delete front \n4.delete rear\n5.DISPLAY\n6.EXIT\n");
 printf("\nEnter the choice : ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 insert_rear();
 break;
 case 2:
 insert_front();
 break;
 case 3:
 delete_front();
 break;
 case 4:
 delete_rear();
 break;
 case 5:
 display();
 break;
 case 6:
 {
 break;
 }
 default:
 {
 printf ("\nInvalid Choice\n");
 }}}
 while(choice!=6);
 return 0;
}

void insert_rear()
{
 if(r==queue_size-1)        
 {
 printf("\n QUEUE OVERFLOW\n");    

 }
 else
 {
 printf("Enter a value to be pushed : ");
 scanf("%d",&x);
 r++;             
 q[r] = x;   
 }}

void insert_front()
{
    if(f==0 && r==-1)
    {
        printf("Enter a value to be pushed : ");
        scanf("%d",&x);
        q[++(r)]=x;
    }
    else if(f!=0)
    {
        printf("Enter a value to be pushed : ");
        scanf("%d",&x);
        q[--(f)]=x;
    }
    else
    printf("Front insertion not possible\n");
}

void delete_front()
{
 if(f>r)
 {
 printf("\nQUEUE UNDERFLOW\n");
 }
 else
 {
 printf("\nThe  element  deleted is %d",q[(f)++]);        
 }
if(f>r)
    f=0,r=-1;
}
void delete_rear()
{
 if(f>r)
 {
 printf("\nQUEUE UNDERFLOW\n");
 }
 else
 {
 printf("\nThe  element  deleted is %d",q[(r)--]);        
 }
if(f>r)
    f=0,r=-1;
}
void display()
{
 if(f>r)
 {
 printf("\n QUEUE is empty\n");
 }
 else
 {
 printf("\n Contents of queue are\n");
 for (i=f;i<=r;i++)
 {
     printf("%d\t",q[i]);
 }
 }}