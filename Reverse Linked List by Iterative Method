#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
    int data; 
    struct Node* next; 
}; /* Function to reverse the linked list */
static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev   = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next; 
    while (current != NULL) 
    { 
        next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node)); 

    /* put in the data  */
    new_node->data  = new_data; 

    /* link the old list off the new node */
    new_node->next = (*head_ref);     

    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 

/* Function to print linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        printf("%d  ", temp->data);     
        temp = temp->next;   
    } 
}     

/* Driver program to test above function*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 

     push(&head, 20); 
     push(&head, 4); 
     push(&head, 15);  
     push(&head, 85);       

     printf("Given linked list\n"); 
     printList(head);     
     reverse(&head);                       
     printf("\nReversed Linked list \n"); 
     printList(head);     
     getchar(); 
} 


//Input Format:
// Enter the values of the nodes in the linked list.

// output Format:
//Display the reverse of the linked list.

//Sample Input:
// Head of following linked list  
//       1->2->6->8->NULL

//Sample Output:
//Reverse of the linked list
//      8->6->->2->1->NULL
