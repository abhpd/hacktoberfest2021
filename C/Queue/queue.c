// program to implement a linked queue.
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// defining structure of a node in SLL
struct node{
    int data;
    struct node *next;
};


// function to delete first node of SLL
// DeQueue operation
struct node *delete_Beg(struct node *head) {
    struct node *ptr;
    ptr = head; // so that we can free the initial space occupied by head later

    if(head == NULL){
        printf("SLL is empty! (UNDERFLOW)");
        exit(0);
    }
    else{
        head=head->next;
        free(ptr);
        return head;
    }

}




// function to insert element(node) at the end of linked list
// EnQueue operation
struct node *insert_end(struct node *head, int ele) {
    struct node *new_node, *ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    ptr=head;

    new_node->data= ele;
    new_node->next= NULL;

    if(ptr == NULL){
        ptr=new_node;
        head=ptr;
    }
    else {

        // Traverse to the last node
        while (ptr != NULL && ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node; // Link address part
    }

    return head;

}



// peek function
// peek function
int peek(struct node *top)
{
    if(top == NULL)
        return -1;
    else
        return top->data;
}


 // function to print the elements of Linked List
 // For Queue (Front and Rear has been added , otherwise same as Linked List)
void display(struct node *head)
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr = head;
    printf(" Front -> ");
    while(ptr != NULL)
    {
        printf(" %d ", ptr -> data);
        if(ptr->next != NULL){
            printf("->");
        }
        ptr = ptr -> next;
    }
    printf(" -> Rear");
    free(ptr);
}


// main function
int main()
{
    int val, option;
    struct node *q;
    q =(struct node *)malloc(sizeof(struct node));
    q = NULL;

    do{
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT\n");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("\n Enter the number to insert in the queue:");
                scanf("%d", &val);
                q = insert_end(q, val);
                break;
            case 2:
                q = delete_Beg(q);
                break;
            case 3:
                val = peek(q);
                if(val != -1)
                    printf("\n The value at front of queue is : %d\n", val);
                break;
            case 4:
                display(q);
                break;
        }
    }while(option != 5);

    return 0;
}
