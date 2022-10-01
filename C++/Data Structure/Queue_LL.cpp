// Implementation of Queue using linked list.

#include <iostream>
using namespace std;
 
struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int y)
    {
        data = y;
        next = NULL;
    }
};
 
struct Queue {
    QueueNode *front, *rear;
    Queue() { front = rear = NULL; }
 
    void enQueue(int x)
    {
 
        // Creating a new Linked List node
        QueueNode* temp = new QueueNode(x);
 
        // If queue is empty, then new node is front and rear both
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
 
        // Adding the new node at the end of queue and changing the rear
        rear->next = temp;
        rear = temp;
    }
 
    // Function to remove a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;
 
        // Store previous front and move front one node ahead
        QueueNode* temp = front;
        front = front->next;
 
        // If front is NULL, then assign rear as NULL
        if (front == NULL)
            rear = NULL;
 
        delete (temp);
    }
};
 
int main()
{
 
    Queue q;
    q.enQueue(40);
    q.enQueue(10);
    q.deQueue();
    q.deQueue();
    q.enQueue(20);
    q.enQueue(70);
    q.enQueue(60);
    q.deQueue();
    cout << "Queue Front : " << (q.front)->data << endl;
    cout << "Queue Rear : " << (q.rear)->data;
}