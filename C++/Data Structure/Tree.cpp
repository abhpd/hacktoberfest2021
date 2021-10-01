#include<iostream>
#include<queue>

using namespace std;

class SinglyLinkedListNode {
  public:
    char key;
    SinglyLinkedListNode * left;
    SinglyLinkedListNode * right;

  SinglyLinkedListNode(char node_data) {
    this -> key = node_data;
    this -> left = NULL;
    this -> right = NULL;
  }
};

class SinglyLinkedList {
  public:
  SinglyLinkedListNode * root;
  queue q;

  SinglyLinkedList() {
    this -> root = NULL;
  }

  void insert_node_left(char node_data, SinglyLinkedListNode * ptr ) {
    /*code to insert new node at the end in linked list having node_data*/
    this -> tail -> next = ptr1;
    this -> tail = ptr1;
  }
};

void print_singly_linked_list(SinglyLinkedListNode * node) {
  /*code to print linked list separated by single space*/
  SinglyLinkedListNode * walker = node;
  while (walker != NULL) {
    cout << walker -> data << " ";
    walker = walker -> next;
  }
  cout<<endl;
}

SinglyLinkedListNode * removeDuplicates(SinglyLinkedListNode * head) {
  /*code to remove duplicates*/
  SinglyLinkedListNode * w1 = head;
  SinglyLinkedListNode * w2 = head -> next;
  while (w2 != NULL) {
    if (w1 -> data == w2 -> data) {
      SinglyLinkedListNode * temp = w2;
      w2 = w2 -> next;
      w1 -> next = w2;
      delete temp;
    } else {
      w1 = w1 -> next;
      w2 = w2 -> next;
    }
  }
  return head;
}

int main() {
  int test_cases;
  cin >> test_cases;
  SinglyLinkedListNode * listfinal[test_cases];
  for (int i = 0; i < test_cases; i++) {
    SinglyLinkedList * LS = new SinglyLinkedList();

    /*code to read input and insert node in linked list*/
    int num_node;
    cin >> num_node;
    for (int a = 0; a < num_node; a++) {
      int value;
      cin >> value;
      if (a == 0) {
        SinglyLinkedListNode * ptr = new SinglyLinkedListNode(value);
        LS -> head = ptr;
        LS -> tail = ptr;
      } else {
        LS -> insert_node(value);
      }
    }
    LS -> head = removeDuplicates(LS -> head);
    listfinal[i] = LS -> head;
  }
  for (int i = 0; i < test_cases; i++) {
    print_singly_linked_list(listfinal[i]);
    cout << endl;
  }
  return 0;
}
