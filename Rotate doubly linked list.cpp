#include <bits/stdc++.h> 
using namespace std; 
struct Node { 
    char data; 
    struct Node* prev; 
    struct Node* next; 
}; 

void rotate(struct Node** head_ref, int N) 
{ 
    if (N == 0) 
        return; 
    struct Node* current = *head_ref;  
    
    int count = 1; 
    while (count < N && current != NULL) { 
        current = current->next; 
        count++; 
    } 
  
 if (current == NULL) 
        return; 
 struct Node* NthNode = current; 
  while (current->next != NULL) 
        current = current->next; 
        current->next = *head_ref;
        (*head_ref)->prev = current;
        *head_ref = NthNode->next; 
        (*head_ref)->prev = NULL; 
        NthNode->next = NULL; 
} 
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node =  new Node; 
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = (*head_ref); 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
   *head_ref = new_node; 
} 
  
  void printList(struct Node* node) 
{ 
    while (node->next != NULL) { 
        cout << node->data << " "
             << "<=>"
             << " "; 
        node = node->next; 
    } 
    cout << node->data; 
} 
int main(void) 
{ 
     struct Node* head = NULL; 
  
      linked list a<->b<->c<->d<->e<->f<->g<->h */
    push(&head, 'e'); 
    push(&head, 'd'); 
    push(&head, 'c'); 
    push(&head, 'b'); 
    push(&head, 'a'); 
    push(&head, 'f'); 
    push(&head, 'g');
    push(&head, 'h'); 
  
    int N = 4; 
  
    cout << "Given linked list \n"; 
    printList(head); 
    rotate(&head, N); 
  
    cout << "\nRotated Linked list \n"; 
    printList(head); 
  
    return 0; 
} 

//Input Format:
//Enter the value of the nodes of the doubly linked list and the number from where it has to be rotated.

//Output Format:
//Rotation of the doubly linked list from the given number.

//Sample Input Format.
//a  b  c  d  e  f  g  h   N = 4

//Sample Output Format:
// e  f  g  h  a  b  c  d 

  
  
