
#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	struct Node* link;
	Node(int data)
	{
		this->data = data;
		link = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	
	void reverse()
	{
		
		Node* current = head;
		Node *prev = NULL, *link = NULL;

		while (current != NULL) {
			
			link = current->link;

			
			current->link = prev;

			
			prev = current;
			current = link;
		}
		head = prev;
	}

	
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->link;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->link = head;
		head = temp;
	}
};


int main()
{
	
	LinkedList l;
	l.push(1);
	l.push(2);
	l.push(3);
	l.push(4);

	cout << "Original Linked list :\n";
	l.print();

	l.reverse();

	cout << "\nLinked list after reversal :\n";
	l.print();
	return 0;
}
