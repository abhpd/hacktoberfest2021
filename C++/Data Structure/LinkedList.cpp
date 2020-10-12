#include <iostream>
using namespace std;

class node {
public:
	int data;
	node*next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

// Linked List Class (Object Oriented)
// class LinkedList{
// 	node*head;
// 	node*tail;

// public:
// 	LinkedList(){

// 	}

// 	void insert(int d){
// 		...
// 		...

// 	}
// }

// Functions (Procedural programming)

void insertAtHead(node *&head, int val) {

	if (head == NULL) {
		head = new node(val);
		return;
	}

	node *temp = new node(val);
	//(*temp).next = head;
	temp->next = head;

	head = temp;
}

int length(node*head) {
	int count = 0;
	while (head != NULL) {
		head = head->next;
		count++;
	}

	return count;

}

void insertAtTail(node *&head, int val) {
	if (head == NULL) {
		head = new node(val);
		return;
	}

	// Take curr to last node
	node *curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}

	node *temp = new node(val);
	curr->next = temp;
}

void insertAtMiddle(node *&head, int pos, int val) {

	if (head == NULL || pos == 0) {
		insertAtHead(head, val);
		return;
	} else if (pos > length(head)) {
		insertAtTail(head, val);
		return;
	}

	// take pos-1 jumps
	node *curr = head;
	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = new node(val);

	temp->next = curr->next;
	curr->next = temp;
}

void deleteHead(node *&head) {
	if (head == NULL) {
		return;
	}
	node *temp = head;
	head = head->next;
	delete temp;
}

void deleteTail(node *&head) {
	node *curr =  head;
	while (curr->next->next != NULL) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = NULL;
	delete temp;
}

void deleteMiddle(node *&head, int pos) {

	if (head == NULL) {
		return;
	} else if (pos > length(head)) {
		deleteTail(head);
		return;
	} else if (pos == 0) {
		deleteHead(head);
		return;
	}

	node *curr = head;

	for (int i = 0; i < pos - 1; i++) {
		curr = curr->next;
	}

	node *temp = curr->next;
	curr->next = temp->next; // or curr->next->next;
	delete temp;

}

bool search(node *head, int key) {
	node *curr = head;

	while (curr != NULL) {
		if (curr->data == key) return 1;
		curr = curr->next;
	}

	return 0;
}

bool searchRecursive(node *head, int key) {

	// Base Case
	if (head == NULL) {
		return 0;
	}

	if (head->data == key) {
		return 1;
	}
	return searchRecursive(head->next, key);

}

void print(node *head) {
	while (head != NULL) {
		cout << head->data << "->";
		head = head->next;
	} cout << endl;
}

// Taking input

// void take_input(node *&head){
// 	// declare head pointer in the main function and then take input
// }

node* take_input() {

	node *head = NULL;
	int x;

	while (cin >> x) {
		insertAtTail(head, x);

	}

	return head;

}

int main() {
	// node *head = NULL;
	// insertAtHead(head, 1);
	// insertAtHead(head, 2);
	// insertAtHead(head, 3);
	// insertAtHead(head, 4);
	// insertAtHead(head, 5);

	// insertAtMiddle(head, 0, 100);
	// insertAtMiddle(head, 4, 555);
	// insertAtTail(head, 200);

	// deleteHead(head);
	// deleteTail(head);
	// deleteMiddle(head, 4);
	// deleteMiddle(head, 0);

	// cout << search(head, 555) << endl << search(head, 70) << endl;
	// cout << searchRecursive(head, 555) << endl << searchRecursive(head, 70) << endl;

	// print(head);
	cout << "Give input: " << endl;
	node *head = take_input();
	print(head);

}