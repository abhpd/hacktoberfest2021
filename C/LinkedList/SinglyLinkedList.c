#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node*next;
};
struct node *head;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void main()
{
 int choice = 0;
 while(choice!=9)
 {
  printf("\n\n***** Main Menu *****\n");
  printf("\n Choose one optionfrom the following list ... \n");
  print("\n =============================================== \n");
  printf("\n 1. Insert in begining \n 2. Insert at last \n 3. Insert at any randomlocation \n 4. Delete from beginning \n 5. Delete from last \n 6. Delete node after specified location \n 7. Search for an element \n 8. Show \n 9. Exit \n");
  printf("\n Enter your choice? \n");
  scanf("\n %d", &choice);
  switch(choice)
  {
   case 1:beginsert();
          break;
   case 2:lastinsert();
          break;
   case 3:randominsert();
          break;
   case 4:begin_delete();
          break;
   case 5:last_delete();
          break;
   case 6:random_delete();
          break;
   case 7:search();
          break;
   case 8:display();
          break;
   case 9:exit(0);
          break;
   default:printf("Please enter valid choice...");
  }
 }
}

void beginsert()
{
 struct node *ptr;
 int item;
 ptr = (struct node *)malloc(sizeof(struct node*));
 if(ptr==NULL)
 {
  printf("\n Overflow");
 }
 else
 {
  printf("\n Enter value \n");
  scanf("%d", &item);
  ptr->data = item;
  ptr->next = head;
  head = ptr;
  printf("\n Node inserted");
 }
}

void lastinsert()
{
 struct node *ptr,*temp;
 int item;
 ptr = (struct node*)malloc(sizeof(struct node));
 if(ptr==NULL)
 {
  printf("\n Overflow");
 }
 else
 {
  printf("\n Enter value \n");
  scanf("%d", &item);
  ptr->data = item;
  if(head==NULL)
  {
   ptr->next = NULL;
   head = ptr;
   printf("\n Node inserted");
  }
  else
  {
   temp = head;
   while(temp->next!=NULL)
   {
    temp=temp->next;
   }
   temp->next=ptr;
   pt->next=NULL;
   printf("\n Node inserted");
  }
 }
}

void randominsert()
{
 int i, loc, item;
 struct node *ptr, *temp;
 ptr = (struct node*)malloc(sizeof(struct node));
 if(ptr==NULL)
 {
  printf("\n Overflow");
 }
 else
 {
  printf("\n Enter element value");
  scanf("%d", &item);
  ptr->data = item;
  printf("\n Enter the location after which you want to insert");
  scanf("\n %d", &loc);
  temp = head;
  for(i=0;i<loc;i++)
  {
   temp = temp->next;
   if(temp==NULL)
   {
    printf("\n Can't insert \n");
    return;
   }
  }
  ptr->next = temp->next;
  temp->next = ptr;
  printf("\n Node inserted");
 }
}

void begin_delete()
{
 struct node *ptr;
 if(head==NULL)
 {
  printf("\n List is empty \n");
 }
 else
 {
  ptr = head;
  head = ptr->next;
  free(ptr);
  printf("\n Node deleted from the begining... \n");
 }
}

void last_delete()
{
 struct node *ptr, *ptr1;
 if(head==NULL)
 {
  printf("\n List is empty");
 }
 else if(head->next==NULL)
 {
  head = NULL;
  free(head);
  printf("\n Only node the list deleted... \n");
 }
 else
 {
  ptr=head;
  while(ptr->next!=NULL)
  {
   ptr1=ptr;
   ptr=ptr->next;
  }
  ptr1->next=NULL;
  free(ptr);
  printf("\n Deleted node from the last... \n");
 }
}

void random_delete()
{
 struct node *ptr, *ptr1;
 int loc,i;
 printf("\n Enter the location of the node after which you want to perform deletion \n");
 scanf("%d", &loc);
 ptr=head;
 for(i=0;i<loc;i++)
 {
  ptr1=ptr;
  ptr=ptr->next;
  if(ptr==NULL)
  {
   printf("\n Can't delete");
   return;
  }
 }
 ptr1->next=ptr->next;
 free(ptr)
 printf("\n Deleted node %d", loc+1);
}

void search()
{
 struct node *ptr;
 int item, i=0, flag;
 ptr=head;
 if(ptr==NULL)
 {
  printf("\n Empty List \n");
 }
 else
 {
  printf("\n Enter item which you want to search? \n");
  scanf("%d", &item);
  while(ptr!=NULL)
  {
   if(ptr->data==item)
   {
    printf("item found at location %d", i+1);
    flag=0;
   }
   else
   {
    flag=1;
   }
   i++;
   ptr=ptr->next;
  }
  if(flag==1)
  {
   printf("Item not found \n");
  }
 }
}

void display()
{
 struct node *ptr;
 ptr=head;
 if(ptr==NULL)
 {
  printf("Nothing to print");
 }
 else
 {
  printf("\n printing values...\n");
  while(ptr!=NULL)
  {
   printf("\n %d", ptr->data);
   ptr=ptr->next;
  }
 }
} 
