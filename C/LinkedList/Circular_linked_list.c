#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void circularLLTraversal(struct node *head)
{
    struct node *ptr = head;

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertAtfirst(struct node *head, int data)
{
    //ptr will be the node we will insert
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    //p is a help pointer
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    //after the while loop p is pointing to the last node of the list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct node *insertAtEnd(struct node *head, int data)
{
    //ptr will be the node we will insert
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    struct node *p = head->next;
    while (p->next != head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;

    return head;
}

struct node *insertInIndex(struct node *head, int data, int index)
{
    //ptr will be the node we will insert
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    
    struct node *p = head;
    int i = 0;
    // to find the element we use a while loop
    while (i != index - 1)
    {
    // we use index-1 because we want the pointer to stand before the element we are inserting and we can use the next of that pointer
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;

}



int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    // allocate memory for nodes in circular linked list in heap as its dynamic
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    //linking first and second nodes
    head->data = 8;
    head->next = second;

    //linking second and third nodes
    second->data = 11;
    second->next = third;

    //linking third and fourth nodes
    third->data = 19;
    third->next = fourth;

    //linking fourth and fifth nodes
    fourth->data = 15;
    fourth->next = fifth;

    // to end this we point the next of last element to the head again so it is a circular linked list
    fifth->data = 35;
    fifth->next = head;

    printf("CICULAR LINKED LIST BEFORE INSERTION\n");
    circularLLTraversal(head);

    printf("CIRCULAR LINKED LIST INSERTING AT FIRST\n");
    head = insertAtfirst(head, 79);
    circularLLTraversal(head);
   
    printf("CIRCULAR LINKED LIST INSERTING AT END\n");
    head = insertAtEnd(head, 87);
    circularLLTraversal(head);

    printf("\nCIRCULAR LINKED LIST AFTER INSERTION at the given node\n");
    head = insertInIndex(head, 50, 3);
    circularLLTraversal(head);

    return 0;
}










/*
some other examples

traversal

    // we use this so once ptr is printed that is head now and then we go to next element so we can use the while loop or else it wont start because ptr is pointing to head
    printf("Element: %d\n",ptr->data);
    ptr=ptr->next;

    //because of the above stmt now ptr is not pointing to head its pointing to the head ka next (head->next)
    while (ptr != head)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }

*/