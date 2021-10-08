#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* createNode()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    return(ptr);
};

void insertAtLast(struct node **lastptr, int value)
{
    struct node *temp = createNode();
    temp->data = value;
    if(*lastptr == NULL)
        temp->next = NULL;
    else
    {
        temp->next = (*lastptr)->next;
        (*lastptr)->next = temp;
    }
    *lastptr = temp;
}

void insertAtFirst(struct node **lastptr, int value)
{
    struct node *temp = createNode();
    temp->data = value;
    if(*lastptr == NULL)
    {
        temp->next = NULL;
        *lastptr = temp;
    }
    if((*lastptr)->next == NULL)
        temp->next = *lastptr;
    else
        temp->next = (*lastptr)->next;
    (*lastptr)->next = temp;
}

void insertAfter(struct node **lastptr, int value, int pos)
{
    if(pos<0)
        printf("Not a valid position\n");
    else if(pos == 0)
        insertAtFirst(lastptr,value);
    else
    {
    struct node *t, *temp;
    temp = createNode();
    temp->data = value;
    t = (*lastptr)->next;
    for(int i=0; i<pos-1; i++)
        t = t->next;
    temp->next = t->next;
    t->next = temp;
    if(t == *lastptr)
        *lastptr = temp;
    }
}

void deleteFirst(struct node **lastptr)
{
    struct node *t;
    if(*lastptr == NULL)
        printf("Underflow");
    else if((*lastptr)->next == NULL)
    {
        t = *lastptr;
        *lastptr = NULL;
        free(t);
    }
    else
    {
        t = (*lastptr)->next;
        (*lastptr)->next = t->next;
        free(t);
    }
}

void deleteLast(struct node **lastptr)
{
    struct node *t;
    if(*lastptr == NULL)
        printf("Underflow");
    else if((*lastptr)->next == NULL)
    {
        t = *lastptr;
        *lastptr = NULL;
        free(t);
    }
    else
    {
        struct node *temp;
        temp = *lastptr;
        t = (*lastptr)->next;
        while(t->next != *lastptr)
        {
            t = t->next;
        }
        *lastptr = t;
        t->next = temp->next;
        free(temp);
    }
}

void display(struct node **lastptr)
{
    struct node *t;
    if(*lastptr == NULL)
        printf("List is empty");
    t = (*lastptr)->next;
    if(t == NULL)
        printf("%d",(*lastptr)->data);
    else
    {
        while(t!=*lastptr)
        {
            printf("%d\t",t->data);
            t = t->next;
        }
        printf("%d",(*lastptr)->data);
    }

}

int main()
{
    struct node *last = NULL;
    int value,choice;
    while(1)
    {
        printf("\n\n****MENU****\n");
        printf("\n 1. Insert item at first in the LinkedList");
        printf("\n 2. Delete item from first in the LinkedList");
        printf("\n 3. Insert item at last in the LinkedList");
        printf("\n 4. Delete item from last in the LinkedList");
        printf("\n 5. Insert item after a particular position in LinkedList");
        printf("\n 6. Display the LinkedList");
        printf("\n 7. Exit");
        printf("\n Choose an option : ");
        scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("\n Enter the value : ");
            scanf("%d",&value);
            insertAtFirst(&last,value);
            break;
        case 2:
            deleteFirst(&last);
            break;
        case 3:
            printf("\n Enter the value : ");
            scanf("%d",&value);
            insertAtLast(&last,value);
            break;
        case 4:
            deleteLast(&last);
            break;
        case 5:
            int pos;
            printf("\n Enter the position : ");
            scanf("%d",&pos);
            printf("\n Enter the value : ");
            scanf("%d",&value);
            insertAfter(&last,value,pos);
            break;
        case 6:
            display(&last);
            break;
        case 7:
            return 0;
        default:
            printf("\n Invalid choice\n");
    }
    }
}