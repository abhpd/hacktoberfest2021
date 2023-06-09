#include <iostream>
using namespace std;

/* *
   The structure Node forms the doubly linked list node which 
   contains the data and a pointer to the next and previous linked list node.
*/

struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
};

struct Node* head = NULL;

// The function insert() inserts the data into the beginning of the linked list

void insert(int newdata) {
   
   // create a new node and inserts the number in the data field of the newnode.

   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = head;
   if(head != NULL)
      head->prev = newnode ;
   head = newnode;
}

// The function display() displays the whole doubly linked list. 

void display() {
   struct Node* ptr;
   ptr = head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
   insert(0);
   insert(10);
   insert(20);
   insert(34);
   cout<<"The doubly linked list is: ";
   display();
   return 0;
}