#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *head = NULL;
void addnode(int data)
{
    Node *temp = new Node;

    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void reverse_iter()
{
    Node *currnode, *prevnode, *nextnode;
    currnode = nextnode = head;
    prevnode = NULL;
    while (currnode != NULL)
    {
        nextnode = currnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    head = prevnode;
}
Node *reverse_rec(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest = reverse_rec(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
void display(Node *node)
{
    Node *ptr;
    ptr = node;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}
int main()
{
    addnode(5);
    addnode(10);
    addnode(35);
    addnode(15);
    addnode(20);
    addnode(25);

    display(head);
    // reverse_iter();
    // display(head);
    Node *rest = reverse_rec(head);
    head = rest;
    display(rest);
    return 0;
}
