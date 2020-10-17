#ifndef BREADTHFIRST_H
#define BREADTHFIRST_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include<queue>
using namespace std;

class node
{
public:
	int data;
	node * next;
};
class adjacencyList {
public:

	node* head;
	node* current;
	adjacencyList() {
		
		head = NULL;
		current = NULL;
	}
	void insert(const int& newNode) {

		node* temp = new node();

		if (head == NULL) {
			temp->data = newNode;
			head = temp;
			current = head;
			temp->next = NULL;
		}

		else {
			while (current->next != NULL)
			{
				current = current->next;
			}
			temp->data = newNode;
			current->next = temp;
			current = temp;
			temp->next = NULL;
		}
	}

	
};


class Graph{

public:

	adjacencyList* arr;
	int Vertices;
	Graph(int maxVertices) {

		Vertices = maxVertices;
		arr = new adjacencyList[maxVertices];
		for (int i = 0; i < maxVertices; i++) {
			arr[i].head = NULL;
			arr[i].current = NULL;
			
		}

	}

	
	void insertEdge(int src, int dest) {

		if (src > Vertices || dest > Vertices) {
			cout << "Invalid Index" << endl;
			return;
		}

		node* newnode = new node();
		newnode->next = NULL;
		newnode->data = dest;
		arr[src].insert(newnode->data);

		newnode->data = src;
		arr[dest].insert(newnode->data);

	}

	int BFS(int startnode, int end) {
		bool visited[Vertices];
		int routes = 0;
		for (int i = 0; i < Vertices; i++) {
			visited[i] = false;
		}
		visited[startnode] = true;

		queue<int> Queue;
		Queue.push(startnode);

		while (!Queue.empty()) {

			int curr = Queue.front();
			Queue.pop();
			routes++;

			node* temp = arr[curr].head;
			while (temp) {

				if (temp->data == end) {
					return routes;
				}
				if (!visited[temp->data]) {
					Queue.push(temp->data);
					visited[temp->data] = true;
				}
				temp = temp->next;

			}
		}

	
	}



};
#endif


