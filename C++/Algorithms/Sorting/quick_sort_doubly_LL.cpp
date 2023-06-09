// Include header file
#include <iostream>
using namespace std;
// C++ program for
// Quicksort on doubly linked list
class LinkNode
{
	public: 
    int data;
	LinkNode *next;
	LinkNode *prev;
	LinkNode(int data)
	{
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};
class DoublyLinkedList
{
	public: LinkNode *head;
	LinkNode *tail;
	DoublyLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
	// Insert new node at end position
	void insert(int value)
	{
		// Create a node
		LinkNode *node = new LinkNode(value);
		if (this->head == nullptr)
		{
			// Add first node
			this->head = node;
			this->tail = node;
			return;
		}
		// Add node at last position
		this->tail->next = node;
		node->prev = this->tail;
		this->tail = node;
	}
	// Display node element of doubly linked list
	void display()
	{
		if (this->head == nullptr)
		{
			cout << "Empty Linked List" << endl;
		}
		else
		{
			cout << "\nLinked List Head to Tail :";
			// Get first node of linked list
			LinkNode *temp = this->head;
			// iterate linked list 
			while (temp != nullptr)
			{
				// Display node value
				cout << "  " << temp->data;
				// Visit to next node
				temp = temp->next;
			}
			cout << "\nLinked List Tail to Head :";
			// Get last node of linked list
			temp = this->tail;
			// iterate linked list 
			while (temp != nullptr)
			{
				// Display node value
				cout << "  " << temp->data;
				// Visit to prev node
				temp = temp->prev;
			}
			cout << "\n";
		}
	}
	// Get partition node
	LinkNode *partition(LinkNode *first, LinkNode *last)
	{
		LinkNode *current = first;
		LinkNode *location = first->prev;
		int temp = 0;
		while (current != nullptr && current != last)
		{
			if (current->data <= last->data)
			{
				if (location == nullptr)
				{
					location = first;
				}
				else
				{
					location = location->next;
				}
				// Swap node values
				temp = current->data;
				current->data = location->data;
				location->data = temp;
			}
			// Visit to next node
			current = current->next;
		}
		if (location == nullptr)
		{
			location = first;
		}
		else
		{
			location = location->next;
		}
		// Swap last node value
		temp = last->data;
		last->data = location->data;
		location->data = temp;
		return location;
	}
	// Perform quick sort
	void quickSort(LinkNode *first, LinkNode *last)
	{
		// Check first and last node valid or not
		if (first != last && first != nullptr && 
            last != nullptr && last->next != first)
		{
			LinkNode *node = this->partition(first, last);
			if (node != nullptr)
			{
				// Recursively sort elements
				this->quickSort(node->next, last);
				this->quickSort(first, node->prev);
			}
		}
	}
};
int main()
{
	DoublyLinkedList *dll = new DoublyLinkedList();
	// Insert linked list data
	dll->insert(4);
	dll->insert(3);
	dll->insert(7);
	dll->insert(1);
	dll->insert(-1);
	dll->insert(6);
	dll->insert(2);
	dll->insert(8);
	dll->insert(-2);
	dll->insert(0);
	cout << "\n Before Sort ";
	dll->display();
	dll->quickSort(dll->head, dll->tail);
	cout << " After Sort ";
	dll->display();
	return 0;
}