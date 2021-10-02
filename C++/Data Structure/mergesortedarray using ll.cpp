#include <iostream>
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
using namespace std;

Node *takeinput()
{

    int data;
    cin >> data;
    Node *head1 = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head1 == NULL)
        {
            head1 = newnode;
            tail = newnode;
        }
        else
        {

            tail->next = newnode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head1;
}
void print(Node *head1)
{
    Node *temp = head1;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

Node *merge(Node *head1, Node *head2)
{

    Node *head = NULL, *tail = NULL;
    if (head1->data < head2->data)
    {
       head = head1;
        tail = head1;
        head1 = head1->next;
    }
    else if (head1->data >= head2->data)
    {
        head = head2;
        tail = head2;
        head2 = head2->next;
    }
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
            tail->next = NULL;
        }
        else if (head1->data >= head2->data)
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
            tail->next = NULL;
        }
    }
    if (head1)
    {
        tail->next = head1;
    }
    if (head2)
    {
        tail->next = head2;
    }

    return head;
}
int main()
{
    Node *head1 = takeinput();

    print(head1);

    Node *head2 = takeinput();
    print(head2);

    Node *head = merge(head1, head2);
    print(head);
}