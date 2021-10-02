#pragma once
#include <iostream>
using namespace std;

/*
Node class containing information and pointer to the next node.
*/
template<class T>
class Node
{
public:
	T info;
	Node<T>* next;

	Node(T inInfo, Node* nPtr = NULL)
	{
		info = inInfo;
		next = nPtr;
	}
};
/*
Linked List class:
A linked list is a linear dynamic data structure to store data items.
Every node is mainly divided into two parts, one part holds the data and the other part
is connected to a different node.
We can add, find and delete nodes.
*/

template<class T>
class CircularLinkedList
{
private:
	Node <T>* head;
	Node <T>* tail;
public:
	CircularLinkedList();
	CircularLinkedList(const CircularLinkedList&);
	bool isEmpty();
	void insertAtHead(T);
	void insertAtTail(T);
	bool deleteAtHead();
	bool deleteAtTail();
	void printList();
	Node<T>* getNode(unsigned int n);
	bool insertAfter(T, T);
	bool insertBefore(T, T);
	bool deleteBefore(T);
	bool deleteAfter(T);
	Node<T>* search(T);
	int getLength();
	~CircularLinkedList();
	void setHead(Node<T>* head);
	void setTail(Node<T>* tail);
	Node<T>* getHead();
	Node<T>* getTail();


};

template<class T>
void CircularLinkedList<T>::setHead(Node<T>* head)
{
	if (isEmpty())
	{
		this->head = this->tail = head;
		tail->next = this->head;
	}
}

template<class T>
void CircularLinkedList<T>::setTail(Node<T>* Tail)
{
	if (isEmpty())	//New node is head & tail
	{
		head = tail = Tail;
		tail->next = head;
	}

	else
	{
		tail->next = Tail;
		tail = Tail;
		tail->next = head;
	}
}

template<class T>
Node<T>* CircularLinkedList<T>::getHead()
{
	return head;
}

template<class T>
Node<T>* CircularLinkedList<T>::getTail()
{
	return tail;
}
template<class T>
CircularLinkedList<T>::CircularLinkedList() :head(NULL), tail(NULL)	//Empty --- NULL
{
}

template<class T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList& L)
{
	Node<T>* temp = L.head;
	while (temp)
	{
		insertAtTail(temp->info);
		temp = temp->next;
	}
}

template<class T>
bool CircularLinkedList<T>::isEmpty()
{
	return head == NULL;
}

template<class T>
void CircularLinkedList<T>::insertAtHead(T value)
{
	/*
	This function inserts a node in the start of the list.
	*/

	Node<T>* newNode = new Node<T>(value);

	if (isEmpty())	//NewNode is head & tail
	{
		this->head = this->tail = newNode;
		tail->next = head;
	}
	else
	{
		newNode->next = this->head;
		this->head = newNode;
		tail->next = head;
	}
}

template<class T>
void CircularLinkedList<T>::insertAtTail(T value)
{
	/*
	This function inserts a node at the end of the list.
	*/

	Node<T>* temp = new Node<T>(value);

	if (isEmpty())	//New node is head & tail
	{
		head = tail = temp;
		tail->next = head;
	}

	else
	{
		tail->next = temp;
		tail = temp;
		tail->next = head;
	}
}

template<class T>
bool CircularLinkedList<T>::deleteAtHead()
{

	/*
	This function delets a node from the start of the list.
	*/


	if (!isEmpty())
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
		if (isEmpty()) {
			head = NULL;
			tail = NULL;
			tail->next = NULL;
		}
		else
			tail->next = head;
		return true;
	}

	else
		return false;
}

template<class T>
bool CircularLinkedList<T>::deleteAtTail()
{
	/*
	This function deletes a node from the end of the list.
	*/

	if (!isEmpty()) {
		Node<T>* temp = head;	//To be pointed at tail
		Node<T>* temp1 = NULL;	//To be pointed 1 step behind the tail

		while (temp != tail)
		{
			temp1 = temp;
			temp = temp->next;
		}

		tail = temp1;

		if (tail)
			tail->next = head;

		delete temp;

		if (tail == NULL) {
			head = NULL;
			tail->next = NULL;
		}

		return true;
	}

	else
		return false;
}

template<class T>
void CircularLinkedList<T>::printList()
{
	/*
	This function prints the list.
	*/

	Node<T>* temp = head;
	while (temp != tail)
	{
		cout << temp->info << " --> ";
		temp = temp->next;
	}
	cout << temp->info;
	cout << endl;
}

template<class T>
Node<T>* CircularLinkedList<T>::getNode(unsigned int n)
{
	/*
	This function returns the nth index's node. Where n can be 0 to N. 0 is the first node and so on.
	*/

	if (!isEmpty()) {
		int size = getLength();
		if (n >= size)
			return tail;

		Node<T>* temp = head;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		return temp;
	}

	else
		return nullptr;
}

template<class T>
bool CircularLinkedList<T>::insertAfter(T value, T key)
{
	/*
	This function inserts a node after the founded value.
	*/

	Node<T>* found = search(key);	//founded node
	if (found)
	{
		if (found == tail) {
			insertAtTail(value);
		}

		else {
			Node<T>* newNode = new Node<T>(value);
			newNode->next = found->next;
			found->next = newNode;
		}

		return true;
	}

	else
		return false;
}

template<class T>
bool CircularLinkedList<T>::insertBefore(T value, T key)
{
	/*
	This function inserts a node before the founded value.
	*/

	Node<T>* found = head;	//founded node
	Node<T>* temp = NULL;	//one behind that

	while (found)
	{
		if (found->info == key) {
			break;
		}
		else {
			temp = found;
			found = found->next;
		}
	}

	if (found)
	{
		if (found == head)
			insertAtHead(value);

		else {
			Node<T>* newNode = new Node<T>(value);
			newNode->next = found;
			temp->next = newNode;

		}

		return true;
	}

	else
		return false;
}

template<class T>
bool CircularLinkedList<T>::deleteBefore(T key)
{
	/*
	This function deletes a node before the founded value.
	*/

	Node<T>* temp = head;	//1 behind finded node/node to be deleted
	Node<T>* temp1 = NULL; //2 behind finded node
	bool found = false;

	while (temp->next)
	{
		if (temp->next->info == key) {
			found = true;
			break;
		}

		else {
			temp1 = temp;
			temp = temp->next;
		}
	}

	if (found) {

		if (temp == head) {
			deleteAtHead();
			return true;
		}

		else if (temp) {
			temp1->next = temp->next;
			delete temp;
			return true;
		}

		return false;
	}

	else
		return false;
}

template<class T>
bool CircularLinkedList<T>::deleteAfter(T key)
{
	/*
	This function deletes a node after the founded value.
	*/

	Node<T>* found = search(key);
	if (found)
	{
		if (found == tail)
			return false;

		Node<T>* temp = found->next;
		if (temp == tail) {
			deleteAtTail();
		}
		else {
			found->next = temp->next;
			delete temp;
		}

		return true;
	}

	else
		return false;
}

template<class T>
Node<T>* CircularLinkedList<T>::search(T key)
{
	/*
	This function returns the founded value's node.
	*/

	Node<T>* temp = head;
	while (temp != tail)
	{
		if (temp->info == key)
			return temp;
		else
			temp = temp->next;
	}

	if (temp->info == key)
		return temp;
	else
		temp = temp->next;

	return NULL;
}

template<class T>
int CircularLinkedList<T>::getLength()
{
	/*
	This function returns the length of list.
	*/

	int count = 0;
	if (!isEmpty()) {
		Node<T>* temp = head;
		while (temp != tail) {
			temp = temp->next;
			count++;
		}
		return ++count;
	}

	else
		return count;
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
	//deletes the list.
	Node<T>* temp = head;
	while (temp != tail)
	{
		head = head->next;
		delete temp;
		temp = head;
	}

	delete temp;
}

