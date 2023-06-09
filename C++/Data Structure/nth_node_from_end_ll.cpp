/*
Problem statement:
We're given a linked list, we need to write a function that returns value at the n'th node from the end of linked list.
For example:
Linked list: 10->20->30->40->50
n = 3
Output: "30"

Solution:
Two pointer method: 
  We will maintain two pointers - main pointer(curr) & reference pointer(ref_ptr).
  Firstly, move the ref_ptr to 'nth' node from head.
  Now move both pointers parallely one by one till ref_ptr reaches end.
  Now main pointer(curr) will point to 'nth' node from end.
  Print value of main pointer. 
*/

#include<bits/stdc++.h>
using namespace std;

//Node of Linked List
struct Node{
    int data;
    struct Node* next;

    //Constructor to create a new node with given data
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

//Function to insert a new node at the beginning of linked list
void insert_at_beg(struct Node** head, int x)
{
    struct Node* newNode = new Node(x);
    newNode->next=*head;
    *head=newNode;
}

//Iterative function to return K'th node from the end in a linked list
void nthNodeFromLast(struct Node* head, int n)
{
    struct Node* curr=head;
    struct Node* ref_ptr=head;


    int i=0;

    //move reference pointer 'n' nodes ahead in linked list
    while(i<n && ref_ptr!=NULL)
    {
        ref_ptr=ref_ptr->next;
        ++i;
    }

    //condition for, if 'n' is more than the total number of nodes in list
    if(ref_ptr==NULL)
    {
        cout<<n<<" is greater than no. of nodes in list!";
        return;
    }
    
    //moving 'curr' and 'ref_ptr' parallely till 'curr' reaches end of the list
    while(ref_ptr)
    {
        curr=curr->next;
        ref_ptr=ref_ptr->next;
    }
    
    //now 'curr' will contain the n'th node from end
    cout<<n<<"th node from end is: "<<curr->data;
}
int main()
{
    struct Node* head=NULL;

    //formation of linked list
    insert_at_beg(&head,10);
    insert_at_beg(&head,20);
    insert_at_beg(&head,30);
    insert_at_beg(&head,40);
    insert_at_beg(&head,50);

    nthNodeFromLast(head,4);
    return 0;
}