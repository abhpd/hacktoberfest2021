#pragma once
#include <iostream>
using namespace std;

template<class T>
class DList;

/*
DNode class containing information and pointer to the next node.
*/

template<class T>
class DNode
{
public:
	friend DList<T>;
	T info;
	DNode<T>* next;
	DNode<T>* prev;

	DNode(T inInfo, DNode* nPtr = NULL, DNode* pPtr = NULL)
	{
		info = inInfo;
		next = nPtr;
		prev = pPtr;
	}
};

/*
Double Linked List class:
A Double linked list is a linear dynamic data structure to store data items.
Every node is mainly divided into three parts, one part holds the data and the other two parts
is connected to a different node. One next and one to the previous
We can add, find and delete nodes.
*/

template<class T>
class DList
{
private:
	DNode <T>* head;
	DNode <T>* tail;
public:
	DList();
	DList(const DList&);
	void setHead(DNode<T>* head);
	void setTail(DNode<T>* tail);
	DNode<T>* getHead();
	DNode<T>* getTail();
	bool isEmpty();
	void insertAtHead(T);
	void insertAtTail(T);
	bool deleteAtHead();
	bool deleteAtTail();
	void printList();
	DNode<T>* getNode(unsigned int n);
	DNode<T>* search(T);
	bool insertAfter(T, T);
	bool insertBefore(T, T);
	bool deleteBefore(T);
	bool deleteAfter(T);
	int getLength();
	~DList();
	void reverse() {
	
		DNode<T>* temp1 = head;
		DNode<T>* temp2 = tail;	
		head = tail;
	
		while (tail != temp1) {
			temp2->next = tail->prev;
			tail = tail->prev;
			temp2 = temp2->next;
		}
		temp2->next = NULL;
		head->prev = NULL;
		temp1 = head->next;
		temp2 = head;
		while (temp1) {
			temp1->prev = temp2;
			temp1 = temp1->next;
			temp2 = temp2->next;
		}


	}

};



template<class T>
DList<T>::DList() :head(NULL), tail(NULL)	//Empty --- NULL
{
}

template<class T>
DList<T>::DList(const DList& L)
{
	DNode<T>* temp = L.head;
	while (temp)
	{
		insertAtTail(temp->info);
		temp = temp->next;
	}
}

template<class T>
void DList<T>::setHead(DNode<T>* head)
{
	if (isEmpty())	//NewNode is head & tail
	{
		this->head = this->tail = head;
	}
}

template<class T>
void DList<T>::setTail(DNode<T>* tail)
{
	if (isEmpty())	//New node is head & tail
	{
		this->head = this->tail = tail;
	}

	else
	{
		tail->prev = this->tail;
		this->tail->next = tail;
		this->tail = tail;
	}
}

template<class T>
DNode<T>* DList<T>::getHead()
{
	return head;
}

template<class T>
DNode<T>* DList<T>::getTail()
{
	return tail;
}

template<class T>
bool DList<T>::isEmpty()
{
	return head == NULL;
}

template<class T>
void DList<T>::insertAtHead(T value)
{
	/*
	This function inserts a node in the start of the list.
	*/

	DNode<T>* newNode = new DNode<T>(value);

	if (isEmpty())	//NewNode is head & tail
	{
		this->head = this->tail = newNode;
	}
	else
	{
		this->head->prev = newNode;
		newNode->next = this->head;
		this->head = newNode;
	}
}

template<class T>
void DList<T>::insertAtTail(T value)
{
	/*
	This function inserts a node at the end of the list.
	*/

	DNode<T>* temp = new DNode<T>(value);

	if (isEmpty())	//New node is head & tail
	{
		head = tail = temp;
	}

	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
}

template<class T>
bool DList<T>::deleteAtHead()
{

	/*
	This function delets a node from the start of the list.
	*/

	if (!isEmpty())
	{
		DNode<T>* temp = head;
		head = head->next;
		delete temp;
		if (isEmpty())
			tail = NULL;
		else
			head->prev = NULL;
		return true;
	}

	else
		return false;
}

template<class T>
bool DList<T>::deleteAtTail()
{
	/*
	This function deletes a node from the end of the list.
	*/

	if (!isEmpty()) {
		DNode<T>* temp = tail;	//To be pointed at tail
		DNode<T>* temp1 = tail->prev;	//To be pointed 1 step behind the tail

		tail = temp1;

		if (tail)
			tail->next = NULL;

		delete temp;

		if (tail == NULL)
			head = NULL;

		return true;
	}

	else
		return false;
}

template<class T>
void DList<T>::printList()
{
	/*
	This function prints the list.
	*/

	DNode<T>* temp = head;
	while (temp)
	{
		cout << temp->info << " " << temp->prev << " " << temp->next << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

template<class T>
DNode<T>* DList<T>::getNode(unsigned int n)
{
	/*
	This function returns the nth index's node. Where n can be 0 to N. 0 is the first node and so on.
	*/

	if (!isEmpty()) {
		int size = getLength();
		if (n >= size)
			return tail;

		DNode<T>* temp = head;
		for (int i = 0; i < n; i++) {
			temp = temp->next;
		}
		return temp;
	}

	else
		return nullptr;
}

template<class T>
bool DList<T>::insertAfter(T value, T key)
{
	/*
	This function inserts a node after the founded value.
	*/

	DNode<T>* found = search(key);	//founded node
	if (found)
	{

		if (found == tail) {
			insertAtTail(value);
		}

		else {
			DNode<T>* newNode = new DNode<T>(value);
			newNode->next = found->next;
			found->next->prev = newNode;
			found->next = newNode;
			newNode->prev = found;
		}

		return true;
	}

	else
		return false;
}

template<class T>
bool DList<T>::insertBefore(T value, T key)
{
	/*
	This function inserts a node before the founded value.
	*/

	DNode<T>* found = search(key);	//founded node

	if (found)
	{
		if (found == head)
			insertAtHead(value);

		else {
			DNode<T>* temp = found->prev;	//one behind founded Node
			DNode<T>* newNode = new DNode<T>(value);
			newNode->next = found;
			found->prev = newNode;
			temp->next = newNode;
			newNode->prev = temp;
		}

		return true;
	}

	else
		return false;
}

template<class T>
bool DList<T>::deleteBefore(T key)
{
	/*
	This function deletes a node before the founded value.
	*/
	DNode<T>* found = search(key);	//founded node
	if (found) {
		DNode<T>* temp = found->prev;	//1 behind finded node/node to be deleted

		if (temp == head) {
			deleteAtHead();
			return true;
		}

		else if (temp) {
			DNode<T>* temp1 = temp->prev; //2 behind finded node
			temp1->next = found;
			found->prev = temp1;
			delete temp;
			return true;
		}

		return false;
	}

	else
		return false;
}

template<class T>
bool DList<T>::deleteAfter(T key)
{
	/*
	This function deletes a node after the founded value.
	*/

	DNode<T>* found = search(key);
	if (found)
	{
		DNode<T>* temp = found->next;
		if (found == tail)
			return false;

		else if (temp) {
			if (temp == tail)
				deleteAtTail();

			else
			{
				found->next = temp->next;
				temp->next->prev = found;
				delete temp;
			}

			return true;
		}

		else
			return false;
	}

	else
		return false;
}

template<class T>
DNode<T>* DList<T>::search(T key)
{
	/*
	This function returns the founded value's node.
	*/

	DNode<T>* temp = head;
	while (temp)
	{
		if (temp->info == key)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

template<class T>
int DList<T>::getLength()
{
	/*
	This function returns the length of list.
	*/

	int count = 0;
	if (!isEmpty()) {
		DNode<T>* temp = head;
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
DList<T>::~DList()
{
	//deletes the list.
	DNode<T>* temp = head;
	while (temp)
	{
		head = head->next;
		delete temp;
		temp = head;
	}
}

int main() {

	DList<int> l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(4);
	l.insertAtTail(5);
	l.insertAtTail(6);
	l.printList();
	l.reverse();
	l.printList();
	return 0;
}