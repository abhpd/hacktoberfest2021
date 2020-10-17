#include<iostream>
#ifndef queue_H
#define queue_H
using namespace std;
template <class T>
struct Node
{
	Node* next;
	T dataItem;
	int priority;
	Node()
	{
		priority=0;
		next=NULL;
	}
};
template <class T>
class Queue
{
protected:
	Node<T>* head; 
	Node<T>* tail;
	int noOfNodes;
public:
	Queue()
	{
		head = NULL;
		tail = NULL;
		noOfNodes = 0;
	}
	~Queue()
	{
		delete head;
		delete tail;
		noOfNodes = 0;
	}
	void enqueue(T dataItem, int priority=0)
	{
		Node<T>* newNode = new Node<T>();
		newNode->dataItem = dataItem;
		newNode->priority = priority;
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
			
		}
		else
		{
			if(head->priority> priority)
			{
				
				newNode->next=head;
				head=newNode;
			}
			else
			{
				Node<T>* temp= head;
				while(temp->next != NULL && temp->next->priority <=priority)
					temp=temp->next;
				newNode->next= temp->next;
				temp->next= newNode;
			
			}
			
		}
		noOfNodes++;
	}
	int size() // returns the size of the queue;
	{
		return noOfNodes;
	}
	T front()
	{
		T value;
		value=head->dataItem;
		return value;
	
	}
	T dequeue()
	{
		T value;
		if (head == NULL)
		{
			return T();
		}
		Node<T>* temp = new Node<T>;
		temp = head->next;
		value = head->dataItem;
		delete head;
		head = temp;
		noOfNodes--;
		return value;
	}
};
#endif

