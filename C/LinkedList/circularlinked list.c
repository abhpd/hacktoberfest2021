//To implement a menu driven progam for circular linked list
#include<string.h>
#include <stdio.h>
#include<stdlib.h>
struct node
{
  int info;
  struct node *next;
};//creating structure containing 2 elements
struct node *start;//declaring start variable
void traverse ();
void insertatbegin ();
void insertatend ();
void insertatspecific ();
void insertafternode ();
void deletefrombegin();
void deleteatend();
void deleteafternode();
void deleteatspecific();
int
main ()
{
  int ch;
  printf ("enter ur choice\n");
  while (1)
    {
      printf
	("1:insert at begin\n2:insert at end\n3:insert fter a given node\n4:insert at a specific location\n5:display\n6:exit\n7:delete from beginning\n8:delete at end\n9:delete after a given node\n10:delete at specific position\n");
      scanf ("%d", &ch);//entering the choice from the menu
      switch (ch)
	{
	case 1:
	  insertatbegin ();
	  break;
	case 2:
	  insertatend ();
	  break;
	case 3:
	  insertafternode ();
	  break;
	case 4:
	  insertatspecific ();
	  break;
	case 5:
	  traverse ();
	  break;
	case 6:
	  exit (0);
	  break;
	  case 7:
	  deletefrombegin();
	  break;
	  case 8:
	  deleteatend();
	  break;
	  case 9:
	  deleteafternode();
	  break;
	  case 10:
	  deleteatspecific();
	  break;
	default:
	  printf ("wrong choice\n");
	}//end of switch

    }//end of while
}//end of main

void
traverse ()
{
  struct node *temp;
  temp = start;
  do
    {
      printf ("%d ", temp->info);
      temp = temp->next;
    }
  while (temp != start);//finding upto last element
  printf("\n");
}

void
insertatbegin ()
{
  struct node *temp, *temp1;
  temp = (struct node *) malloc (sizeof (struct node));//create a memory space for a node
  if(temp==NULL)
  {
      printf("memory not allocated");
  }
  else
  {
  printf ("enter the value\n");
  scanf ("%d", &temp->info);//input for number
  temp->next = NULL;
  if (start == NULL)//only for first node
    {
      start = temp;
      temp->next = start;
    }//end of if
  else
    {
      temp->next = start;//keep the 1st node address in new node
      temp1 = temp->next;
      while (temp1->next != NULL)//find the last node
	{
	  temp1 = temp1->next;
	}//end of while
      start = temp;//changing the start
      temp1->next = start;//next of last node change
    }//end of inner else
  }//end of outer else
}//end of function

void
insertatend ()
{
  struct node *temp, *temp1;
  temp = (struct node *) malloc (sizeof (struct node));//memory space for node
  if (temp == NULL)
    {
      printf ("memory nit allocated\n");
    }
  else
    {
      printf ("enter the no want to insert\n");
      scanf ("%d", &temp->info);
      if (start == NULL)//for 1st node
	{
	  start = temp;
	  temp->next = start;
	}//end of if
      else
	{
	  temp1 = start;
	  while (temp1->next != start)//find last node
	    {
	      temp1 = temp1->next;
	    }
	  temp->next = start;//next of new node will be start
	  temp1->next = temp;//last node keep the new last node
	}//end of inner else
    }//end of outer else
}//end of main

void
insertafternode ()
{
  struct node *temp, *temp1;
  int no;//for node value
  temp = (struct node *) malloc (sizeof (struct node));//memory for new node
  if (temp == NULL)
    {
      printf ("memory not allocated\n");
    }
  else//1
    {
      printf ("enter the no want to insert\n");
      scanf ("%d", &temp->info);//input for new node
      if (start == NULL)
	{
	  start = temp;
	  temp->next = start;
	}//if no node is present
      else//2
	{
	  printf ("enter the node value after u want to insert\n");
	  scanf ("%d", &no);
	  temp1 = start;
	  do
	    {
	      temp1 = temp1->next;
	    }
	  while (temp1 != start && temp1->info != no);//search the node value
	  if (temp1 == start)//if process reaches the end of list
	    {
	      printf ("node i s not present\n");
	    }
	  else 
	    {
	      temp->next = temp1->next;//keep address of previous node in new node
	      temp1->next = temp;//keep address of  new node in previous node 
	    }
	}//end of else 2
    }//end of else 1
}//end of function

void
insertatspecific ()
{
  struct node *temp, *temp1, *temp2;
  int pos;
  temp = (struct node *) malloc (sizeof (struct node));//memory for new node
  if (temp == NULL)
    {
      printf ("memory not allocated\n");
    }
  else //1
    {
      printf ("enter the no want to insert\n");
      scanf ("%d", &temp->info);//input for new node
      if (start == NULL)
	{
	  start = temp;
	  temp->next = start;
	}
      else //2
	{
	  int k = 1;
	  printf ("enter the position where want to insert\n");
	  scanf ("%d", &pos);
	  temp1 = start;
	  if (pos == 1)//if entering in 1st position
	    {
	      temp->next = start;
	      while (temp1->next != start)
		{
		  temp1 = temp1->next;
		}
		start=temp;
	      temp1->next = start;
	    }
	  else //3
	    {
	      do
		{
		  temp2 = temp1;
		  temp1 = temp1->next;
		  k++;
		}
	      while (temp1 != start && k != pos);//searching the position
	      if (temp1 == start)
		{
		  printf ("position not found\n");
		}
	      else
		{
		  temp->next = temp2->next;
		  temp2->next = temp;
		}
	    }//end of 3
	}//end of 2
    }//end of 1
}//end of fun^n
void deletefrombegin()
{
    struct node *temp,*temp1;
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else //1
    {
        temp=start;
        temp1=start;
        if(start->next==start)//if only one node is present
        {
            printf("deleted value=%d\n",start->info);
            start=NULL;
        }
        else //2
        {
        printf("deleted value=%d",temp->info);
        while(temp1->next!=start)
        {
            temp1=temp1->next;
        }
        start=temp->next;
        temp1->next=start;
        free(temp);//free the memory
        }//end of 2
    }//end of 1
}//end of fun^n
void deleteatend()
{
    struct node *temp,*temp1;
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else //1
    {
        if(start->next==start)//if only one node is there
        {
            printf("deleted value=%d\n",start->info);
            start=NULL;
        }
        else //2
        {
            temp=start;
            while(temp->next!=start)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next=start;
            printf("deleted value=%d\n",temp->info);
            free(temp);//free memory
        }//end of 2
    }//end of 1
}//end of fun^n
void deleteafternode()
{
    struct node *temp,*temp1;
    int no;
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else //1
    {
    if(start->next==start)//only one node is present
    {
        printf("deleted value =%d\n",start->info);
        start=NULL;
    }
    else //2
    {
        temp=start;
        printf("enter the node after value after u want to delete\n");
        scanf("%d",&no);
        while(temp->next!=start && temp->info!=no)//find the node value
        {
            temp=temp->next;
        }
        if(temp->next==start)
        {
            printf("node value is not present or it is the last node\n");
        }
        else
        {
            temp1=temp->next;
            printf("deleted value=%d\n",temp1->info);
            temp->next=temp1->next;
            free(temp1);//free memory
        }
    }//end 2
    }//end 1
}//end of fun^n
void deleteatspecific()
{
    struct node *temp,*temp1;
    int pos,k=1;
    if(start==NULL)
    {
        printf("list is empty\n");
    }
    else //1
    {
        temp=start;
        temp1=start;
        printf("enter the location want to delete\n");
        scanf("%d",&pos);
        if(pos==1 && start->next!=start)//if input and list directs to 1st node
        {
            printf("deleted value =%d\n",temp->info);
            free(temp);
            start=NULL;
            
        }
        else if(pos==1)//if input is 1st node
        {
            printf("deleted value=%d\n",temp->info);
            while(temp->next!=start)
            {
                temp=temp->next;
            }
            start=temp1->next;
            temp->next=start;
            free(temp1);
        }
        else //2
        {
        do
        {
            temp1=temp;
            temp=temp->next;
            k++;
        }
        while(temp!=start && k!=pos);//find the position
        if(temp==start)
        {
            printf("location not found\n");
        }
        else
        {
            temp1->next=temp->next;
            printf("deleted value=%d\n",temp->info);
            free(temp);//releasing memory for temp
        }
        }//end 2
    }//end 1
}//end of fun^n




