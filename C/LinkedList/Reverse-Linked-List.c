#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
  
/* Function to reverse the linked list */
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
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
             
    new_node->data  = new_data;
    new_node->next = (*head_ref);    
    (*head_ref)    = new_node;
}
  
/* Print the linked list */
void printLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);    
        temp = temp->next;  
    }
}    
  
int main()
{
    struct Node* head = NULL;
    
     push(&head, 5);
     push(&head, 8);
     push(&head, 48); 
     push(&head, 96); 
     push(&head, 45);
     push(&head, 75);
     push(&head, 8); 
     push(&head, 976);       
      
     printf("The given linked list\n");
     printLinkedList(head);    
     reverse(&head);                      
     printf("\nReversed Linked list \n");
     printLinkedList(head);    
     getchar();
}