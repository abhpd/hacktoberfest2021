//Author : Sanjana Sawant

#include <stdio.h>
#include <stdlib.h>

struct cdlink{
    struct cdlink *left;
    int data;
    struct cdlink *right;
};

typedef struct cdlink node;
node *start = NULL;
int nodectr;

int menu();
int create_list();
int insert_node();
int delete_node();
void display();

node* getnode();

void insert_beg();
void insert_mid();
void insert_end();

void delete_beg();
void delete_mid();
void delete_end();


//Deletes a specified node
int delete_node()
{
    int ch;

    printf("\n---------------");
    printf("\n1. Delete node at the beginning");
    printf("\n2. Delete node at the middle");
    printf("\n3. Delete node at the end");
    printf("\nEnter your choice(1-3): ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: delete_beg();
                break;
        case 2: delete_mid();
                break;
        case 3: delete_end();
                break;
        default: printf("\nInvalid Choice !!");
                return 0;
    }
}

//Deletes first node
void delete_beg()
{
    node *temp;

    if (start==NULL)
    {
        printf("\nEMPTY LIST !!");
        return;
    }
    else
    {
       nodectr--;
       if (nodectr==0)
       {
           free(start);
           start=NULL;
       }
       else
       {
           temp=start;
           start=start->right;
           start->left=temp->left;
           temp->left->right=start;
           free(temp);
       }
       printf("\nNode deleted!!");
    }
}

//Deletes specified node
void delete_mid()
{
    int pos, c=1;
    node *temp;

    printf("\nEnter position: ");
    scanf("%d",&pos);

    if (pos>nodectr)
    {
        printf("\nPosition out of range ");
        return;
    }
    if (pos>1 && pos<=nodectr)
    {
        temp=start;
        while(c<pos)
        {
            temp=temp->right;
            c++;
        }
        temp->right->left=temp->left;
        temp->left->right=temp->right;
        free(temp);
        nodectr--;
        printf("\nNode deleted !!");
    }
    else
    {
        printf("\nNot middle position");
    }
}

//Deletes last node
void delete_end()
{
    node *temp;

    if (start==NULL)
    {
        printf("\nEMPTY LIST !!");
        return;
    }
    else
    {
        nodectr--;
        if (nodectr==0)
        {
            free(start);
            start=NULL;
        }
        else
        {
            temp=start->left;
            temp->left->right=start;
            start->left=temp->left;
            free(temp);
        }
        printf("\nNode deleted ");
    }
}

//Displays the complete list
void display()
{
   node *temp;
   temp=start;
   if (start == NULL)
   {
       printf("\nList is EMPTY !!");
       return;
   }
   else
   {
       printf("\nContents of the list are: \n");
       printf(" %d \n", temp->data);
       temp=temp->right;
       while(temp!=start)
       {
           printf(" %d \n", temp->data);
           temp=temp->right;
       }
   }
}

//Creates a new node and returns its pointer
node* getnode()
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node)); //Dynamic allocation for new node

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->left=NULL;         //Pointing to NULL
    newnode->right=NULL;        //Pointing to NULL
    return newnode;
}

//Inserts a new node
int insert_node()
{
    int ch;

    printf("\n---------------");
    printf("\n1. Insert node at beginning");
    printf("\n2. Insert node at the middle");
    printf("\n3. Insert node at the end");
    printf("\nEnter your choice(1-3): ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: insert_beg();
                break;
        case 2: insert_mid();
                break;
        case 3: insert_end();
                break;
        default: printf("\nInvalid Choice !!");
                return 0;
    }
}

//Inserts a new node at the beginning of the list
void insert_beg()
{
    node *newnode;
    newnode=getnode();
    if (start == NULL)      //If no list exists
    {
        start = newnode;
        start->left=start;
        start->right=start;
    }
    else
    {
       newnode->left=start->left;
       newnode->right=start;
       start->left->right=newnode;
       start->left=newnode;
       start=newnode;
    }
    nodectr++;
    printf("\nNode inserted!!\n");
}

void insert_mid()
{
    node *newnode, *temp;
    int pos, c=1;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos>nodectr)
    {
        printf("\nPosition out of range");
        return;
    }
    if (pos>1 && pos<=nodectr)
    {
        newnode=getnode();
        temp=start;

        while(c<pos-1)
        {
            temp=temp->right;
            c++;
        }
        newnode->left=temp;
        newnode->right=temp->right;
        temp->right->left=newnode;
        temp->right=newnode;
        nodectr++;
        printf("\nNode inserted !!");
    }
    else
    {
        printf("\nNot a middle position");
    }

}

void insert_end()
{
    node *newnode;
    newnode=getnode();
    if (start == NULL)      //If no list exists
    {
        start = newnode;
        start->left=start;
        start->right=start;
    }
    else
    {
        newnode->left=start->left;
        newnode->right=start;
        start->left->right=newnode;
        start->left=newnode;
    }
}

//Creating a new list
int create_list()
{
    int n;
    node *newnode;

    if (start == NULL)
    {
        printf("\nEnter number of nodes : ");
        scanf("%d",&n);
        nodectr = n;

        while(n!=0)
        {
            newnode = getnode(); //Creates a new node pointing to NULL
            if (start == NULL)
            {
                start = newnode;
                start->right=start;
                start->left =start;
            }
            else
            {
                newnode->left = start->left;    // END<--NEW
                newnode->right=start;           //       NEW-->START
                start->left->right=newnode;     // END-->NEW
                start->left=newnode;            //       NEW<--START
            }
            n--;
        }
    }
    else
    {
        printf("\n\nList already exists !!");
    }
}

int menu()
{
    int n;

    printf("\n\n---------Menu-----------");
    printf("\n1. Create list");
    printf("\n2. Insert node");
    printf("\n3. Delete node");
    printf("\n4. Display list");
    printf("\n5. Exit");
    printf("\n\nEnter your choice(1-5): ");
    scanf("%d", &n);
    return n;
}

int main()
{
    char ch;
    printf("-----Program for Circular Double Linked List-----");

    while(1)
    {
       ch = menu();
       switch(ch)
       {
           case 1: create_list();
                    break;
           case 2: insert_node();
                    break;
           case 3: delete_node();
                    break;
           case 4: display();
                    break;
           case 5: exit(0);
                    break;
           default: printf("\nINVALID CHOICE!!!");
                    return 0;

       }
    }
}
