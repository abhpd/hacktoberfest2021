// Created by Utkarsh Nagdev;
// An implementation of singly linked list in C++;


#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

/*
  Constructor for SinglyLinkedList for new Object
  Points to NULL i.e there are no objects in the list
*/
List::List(): head(0){
}

/*
  Destructor for SinglyLinkedList for freeing Object
  if List is empty returns to the calling function
  if list is not empty it starts from head till the last element and deletes/frees each node
*/
List::~List() {
  if(emptyList())
    return;
  NODEPTR p,q;
  for(p = head; p->next!=NULL; p = p->next)
    delete p;
}

/*
  inline and const because a small function and does not change anything inside the object
  Private function to be used by other member functions
  Returns 1 if the list is empty otherwise 0 by checking the head 
*/
int List::emptyList() const {
  return(head==0);
}

/*
  Inserts an element at the start of the list
*/
int List::push(int insertValue) {
  
  NODEPTR newNode;
  newNode = new Node;
  newNode->info = insertValue;
  if(head == NULL) {  head = newNode; head->next = NULL; return 0;}
  newNode->next = head;
  head = newNode;
  // delete p;
}

/*
  Inserts an element after the given node value
*/
int List::insertAfter(int prevValue, int insertValue) {
  NODEPTR traverseNode = head;
  while(traverseNode->info != prevValue && traverseNode->next!=NULL) {
    traverseNode = traverseNode->next;
  }
  if(traverseNode->next == NULL) return 0;
  NODEPTR newNode = new Node;
  newNode->next = traverseNode->next;
  traverseNode->next = newNode;
}

/*
 Removes the top element of the linked list
*/
int List::pop() {
  if(head == NULL) cerr << "List is empty" << endl;
  int oldVal = head->info;
  NODEPTR oldNode = head;
  head = head->next;
  delete oldNode;
}

/*
  
*/
void List::del(int delValue) { 
}
void List::print() const {
  NODEPTR traverseNode = head;
  int count = 1;
  while(traverseNode->next != NULL) {
    cout << "||------------------------------||" << endl;;
    cout << "||Node " << count++ << " :\t\t\t||" << endl; 
    cout << "||\t info = " << traverseNode->info << "  \t\t||"  << endl;
    cout << "||------------------------------||" << endl;
      cout << "\t \t|| " << endl;
      cout << "\t \t|| " << endl;
      cout << "\t \t|| " << endl;
      cout << "\t \tvv " << endl;
    traverseNode = traverseNode->next;
  }
    cout << "||------------------------------||" << endl;;
    cout << "||Node " << count++ << " :\t\t\t||" << endl; 
    cout << "||\t info = " << traverseNode->info << "  \t\t||"  << endl;
    cout << "||------------------------------||" << endl;
}
/* sample main */
int main() {
//  cout << "In main" << endl;
  List list1;
  list1.push(10);
  list1.push(20);
  list1.print();
}
