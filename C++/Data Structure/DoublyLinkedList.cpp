//Implementation of Doubly Linked List by Gunjan Dhanuka

#include <iostream>
using namespace std;

//create the node strucute for a Doubly Linked List
class DllNode
{
public:
    DllNode()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    DllNode(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
    virtual ~DllNode()
    {
        //dtor
    }
    int getData()
    {
        return data;
    }
    bool setData(int value)
    {
        data = value;
        return true;
    }
    DllNode *getNextPtr()
    {
        return next;
    }
    DllNode *getPrevPtr()
    {
        return prev;
    }
    bool setNextPtr(DllNode *ptr)
    {
        next = ptr;
        return true;
    }
    bool setPrevPtr(DllNode *ptr)
    {
        prev = ptr;
        return true;
    }

protected:
    int data;
    DllNode *next;
    DllNode *prev;
};

//Doubly Linked List ADT
class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    virtual ~DoublyLinkedList()
    {
        //dtor
    }

    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }

        return false;
    }

    //Add an item at the beginning of the list
    void addB(DllNode *nodePtr)
    {
        if (isEmpty())
        {
            head = nodePtr;
            tail = nodePtr;
            return;
        }
        else
        {
            nodePtr->setNextPtr(head);
            head->setPrevPtr(nodePtr);
            head = nodePtr;
        }
    }

    //Add the item after the tail of the list
    void addE(DllNode *nodePtr)
    {
        if (isEmpty())
        {
            addB(nodePtr);
            return;
        }

        tail->setNextPtr(nodePtr);
        nodePtr->setPrevPtr(tail);
        tail = nodePtr;
    }

    

protected:
    DllNode *head;
    DllNode *tail;
};

int main()
{
    //The input should consist of "1" only once and in the first line (assumed as instructed)
    int input;
    cin >> input;

    DoublyLinkedList dll;

    while (cin >> input)
    {
        switch (input)
        {
        case 1:
        {
            DoublyLinkedList dll;
            break;
        }
        case 2:
        {
            int value;
            cin >> value;
            DllNode *node = new DllNode();
            node->setData(value);
            dll.addB(node);
            break;
        }

        case 3:
        {
            int value;
            cin >> value;
            DllNode *node = new DllNode();
            node->setData(value);
            dll.addE(node);
            break;
        }


        default:
        {
            cout << "Invalid Option." << endl;
            break;
        }
        }
    }
}