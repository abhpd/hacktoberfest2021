//Author : Sanjana Sawant

#include <stdio.h>
#include <stdlib.h>

struct cslink{
    int data;
    struct cslink *next;
};
typedef struct cslink node;
node *head;
int nodectr=0;

node* getnode ();
void create_cslist();

void insert_node();
void insert_beg();
void insert_mid();
void insert_end();

void delete_node();
void delete_beg();
void delete_mid();
void delete_end();

void display();

//Create a new node
node* getnode()
{
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    printf("\nEnter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

//Create a circular single linked list
void create_cslist()
{
    node *newnode, *temp;
    int n;

    printf("\nEnter the number of nodes : ");
    scanf("%d", &n);
    nodectr = n;
    for(int i =0; i<n; i++)
    {
       newnode = getnode();
       if (head == NULL)
       {
            head = newnode;
       }
       else
       {
           temp =head;
           while(temp->next != head)
           {
               temp =temp->next;
           }
           temp->next = newnode;
       }
       newnode->next =head;
    }

}

//Insert a new node
void insert_node()
{
    int n;
    printf("\n*****************");
    printf("\n1. Insert node at the beginning");
    printf("\n2. Insert node at the mid");
    printf("\n3. Insert node at the end");
    printf("\n\nEnter your choice : ");
    scanf("%d",&n);
    switch (n)
    {
        case 1: insert_beg();
                break;
        case 2: insert_mid();
                break;
        case 3: insert_end();
                break;
        default: printf("\nInvalid Choice !!");
    }
}

//Insert a new node at the beginning
void insert_beg()
{
    node *last, *newnode;
    newnode = getnode();
    if (head == NULL)
        head = newnode;
    else
    {
        last = head;
        while(last -> next != head)
        {
            last = last->next;
        }
        newnode->next = head;
        head = newnode;
        last->next = head;
    }
    printf("\nNode inserted at the beginning ");
    nodectr++;
}

//Insert a new node at the middle
void insert_mid()
{
    node *temp, *prev, *newnode;
    int pos;

    printf("\nEnter a middle position : ");
    scanf("%d", &pos);
    if (pos>1 && pos<nodectr)
    {
        newnode = getnode();
        temp =head;
        prev = temp;
        int i =1;
        while(i<pos)
        {
            prev =temp;
            temp= temp->next;
            i++;
        }
        prev ->next = newnode;
        newnode->next = temp;
        nodectr++;
        printf("\nNode inserted at position %d",pos);
    }
    else
        printf("\nInvalid position !!");
}

//Insert a new node at the end
void insert_end()
{
    node *temp, *newnode;
    newnode = getnode();
    if (head == NULL)
        head = newnode;
    else
    {
        temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode ->next = head;
    }
    printf("\nNode inserted at the end");
    nodectr++;
}

//Delete a node
void delete_node()
{
    int n;
    printf("\n*****************");
    printf("\n1. Delete node at the beginning");
    printf("\n2. Delete node at the mid");
    printf("\n3. Delete node at the end");
    printf("\n\nEnter your choice : ");
    scanf("%d",&n);
    switch (n)
    {
        case 1: delete_beg();
                break;
        case 2: delete_mid();
                break;
        case 3: delete_end();
                break;
        default: printf("\nInvalid Choice !!");
    }
}

//Delete the first node
void delete_beg()
{
    node *temp, *last;
    if (head == NULL)
    {
        printf("\nEMPTY LIST !!");
        return;
    }
    else
    {
        last = temp = head;
        while(last->next !=head)
        {
            last =last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
        nodectr--;
        printf("\nNode at beginning deleted");
        if (nodectr==0)
        {
            head =NULL;
        }
    }
}

//Delete a node in the middle of the list
void delete_mid()
{
    node *temp, *prev;
    int i=1, pos;
    if (head == NULL)
    {
        printf("\nEMPTY LIST !!");
        return;
    }
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    if (pos >1 && pos<nodectr)
    {
        temp = head;
        prev = head;
        while(i < pos)
        {
            prev = temp;
            temp = temp->next ;
            i++;
        }
        prev->next = temp->next;
        free(temp);
        nodectr--;
        printf("\nNode at position %d deleted", pos);
        if (nodectr==0)
        {
            head =NULL;
        }
}
}

//Delete last node
void delete_end()
{
    node *temp, *prev;
    if (head == NULL)
    {
        printf("\nEMPTY LIST !!");
        return;
    }
    else
    {
        temp =head;
        prev = head;
        while(temp ->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
        nodectr--;
        printf("\nNode at end deleted");
        if (nodectr==0)
        {
            head =NULL;
        }
    }
}

//Display the list
void display()
{
    node *temp;
    if (head == NULL)
        printf("\nEMPTY LIST !!");
    else
    {
        printf("\nThe contents of the list are : \n");
        temp =head;
        do
        {
            printf("\n %d ", temp->data);
            temp = temp->next;
        }while(temp != head);
    }
}

//Menu for selecting function
int menu()
{
    int ch;
    printf("\n-----------------------------------------------------------------");
    printf("\n1. Create a circular list");
    printf("\n2. Insert a node");
    printf("\n3. Delete a node");
    printf("\n4. Display list");
    printf("\n5. Exit");
    printf("\n\nEnter your choice (1-5): ");
    scanf("%d",&ch);
    return ch;
}

int main()
{
    int ch;
    printf("Program to implement circular single linked list\n\n");
    while (1)
    {
        ch = menu();
        switch (ch)
        {
            case 1: create_cslist();
                    break;
            case 2: insert_node();
                    break;
            case 3: delete_node();
                    break;
            case 4: display();
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice !!!");
        }
    }
}
