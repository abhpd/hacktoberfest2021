#include <stdio.h>
#include <stdlib.h>

struct node
{
    int seatc, seatr;
    char status;
    struct node *next;
    struct node *prev;

} * head[10], *last[10];

void display()
{
    struct node *temp;
    for (int j = 0; j < 8; j++)
    {
        temp = head[j];
        for (int i = 0; i < 6; i++)
        {
            printf("(%d,%d)", temp->seatr, temp->seatc);
            printf("%c\t", temp->status);
            temp = temp->next;
        }
        printf("\n");
    }
}

struct node *create_node(int x, int y)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nMemory not allocated");
        return 0;
    }
    else
    {
        temp->seatc = x;
        temp->seatr = y;
        temp->status = 'U';
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }
}

void ticket()
{
    for (int j = 0; j < 8; j++)
    {
        head[j] = last[j] = NULL;
        struct node *temp;
        for (int i = 1; i <= 6; i++)
        {
            temp = create_node(i, j + 1);
            if (head[j] == last[j] && head[j] == NULL)
            {
                head[j] = last[j] = temp;
                head[j]->next = last[j]->next = NULL;
                head[j]->prev = last[j]->prev = NULL;
            }
            else
            {
                temp->next = head[j];
                head[j]->prev = temp;
                head[j] = temp;
                head[j]->prev = last[j];
                last[j]->next = head[j];
            }
        }
    }
}

void book()
{
    int x, y;
    printf("\nEnter row and column: ");
    scanf(" %d", &x);
    scanf(" %d", &y);
    struct node *temp;
    temp = head[x - 1];
    for (int i = 0; i < 6; i++)
    {
        if (temp->seatc == y)
        {
            if (temp->status == 'U')
            {
                temp->status = 'B';
            }
            else
            {
                printf("\nAlready booked!\n");
            }
        }
        temp = temp->next;
    }
    display();
}

void cancel()
{
    int x, y;
    printf("\nEnter row and column to cancel booking: ");
    scanf(" %d", &x);
    scanf(" %d", &y);
    struct node *temp;
    temp = head[x - 1];
    for (int i = 0; i < 6; i++)
    {
        if (temp->seatc == y)
        {
            if (temp->status == 'B')
            {
                temp->status = 'U';
            }
            else
            {
                printf("\nRetry\n");
            }
        }
        temp = temp->next;
    }
    display();
}

int main()
{
    printf("Pradhyuman Arora - 20BPS1149");
    int ch = 1;
    ticket();
    do
    {
        printf("\nU is when seats are empty, B means seats are booked.\n");
        printf("\n1.Display Seats\n2.Book Ticket\n3.Cancel Booking\n4.EXIT\n");

        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            book();
            break;
        case 3:
            cancel();
            break;
        case 4:
            printf("\nThank you\n");
            break;
        }
    } while (ch);

    return 0;
}