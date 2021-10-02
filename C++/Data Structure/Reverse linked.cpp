// Given pointer to the head node of a linked list, the task is to reverse the linked list. We need to reverse the list by changing the links between nodes.
/*
Input: Head of following linked list 
1->2->3->4->NULL 
Output: Linked list should be changed to, 
4->3->2->1->NULL
*/

#include<bits/stdc++.h>
using namespace std;



struct Node{
  int data;
  Node* next;
};
Node* reverse(Node* head){
    Node *newHead = NULL;
    while(head != NULL){
        Node *next = head->next;
        head->next = newHead;
        newHead = head;
        head=next;
    }
    return newHead;
}
int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    
    Node *head = NULL;
    
    int n;
    cin>>n;
    int x;
    Node* temp;
    cin>>x;
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next=NULL;
    head = new_node;
    temp = new_node;
    
    while(n--)
    {
        cin>>x;
        Node *new_node = new Node();
        new_node->data = x;
        new_node->next=NULL;
        temp->next = new_node;
        temp=new_node;
    }
    head = reverse(head);
    temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
return 0;
}
