#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} * start, *extra, *ptr, *temp;

void create();
void beginsert();
void endinsert();
void posinsert();
void display();
void begdel();
void enddel();
void posdel();
int n = 0;

void newNode(int item)
{
    extra = (struct node *)malloc(sizeof(struct node));
    extra->data = item;
    extra->next = NULL;
    n++;
}

void menu()
{
    int ch;
    printf("\n1. Create a linked list\n2. Insert node at beginning\n3. Insert node at end\n4. Insert node somewhere\n5. Delete from beginning\n6. Delete from end\n7. Delete in specific location\n8. Display linked list\n9. Exit\n>>>");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        create();
        break;
    case 2:
        beginsert();
        break;
    case 3:
        endinsert();
        break;
    case 4:
        posinsert();
        break;
    case 5:
        begdel();
        break;
    case 6:
        enddel();
        break;
    case 7:
        posdel();
        break;
    case 8:
        display();
        break;
    case 9:
        return;
    default:
        printf("Wrong choice\n>>>");
    }
    menu();
}

int main()
{
    menu();
    return 0;
}

void create()
{
    int item;
    printf("Enter 1st item: ");
    scanf("%d", &item);
    newNode(item);

    start = extra;
    ptr = start;
    while (1)
    {
        printf("Enter value of next node, -1 to end: ");
        scanf("%d", &item);
        if (item == -1)
            break;
        newNode(item);
        ptr->next = extra;
        ptr = ptr->next;
    }
}

void beginsert()
{
    int item;
    printf("Enter item: ");
    scanf("%d", &item);
    newNode(item);
    ptr = start;
    start = extra;
    extra->next = ptr;
}

void endinsert()
{
    int item;
    printf("Enter item: ");
    scanf("%d", &item);
    newNode(item);
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = extra;
}

void posinsert()
{
    int item, pos;
    printf("Enter item: ");
    scanf("%d", &item);
    printf("Enter position: ");
    scanf("%d", &pos);
    newNode(item);
    ptr = start;
    for (int i = 0; i < pos - 1; i++)
        ptr = ptr->next;
    temp = ptr->next;
    ptr->next = extra;
    extra->next = temp;
}

void display()
{
    ptr = start;
    while (ptr)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("\b\b  ");
}

void begdel()
{
    ptr = start;
    start = start->next;
    free(ptr);
    n--;
}

void enddel()
{
    ptr = start;
    while (1)
    {
        temp = ptr;
        ptr = ptr->next;
        if (ptr->next == NULL) //2 steps ahead of temp
        {
            temp->next = NULL;
            free(ptr);
            n--;
            return;
        }
    }
}

void posdel()
{
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);
    ptr = start;

    if (pos >= n || pos < 0)
    {
        printf("Out of range\n");
        return;
    }

    if (pos == n - 1)
    {
        enddel();
        return;
    }

    if (pos == 0)
    {
        begdel();
        return;
    }

    for (int i = 0; i < pos ; i++)
    {
        temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    free(ptr);
}
