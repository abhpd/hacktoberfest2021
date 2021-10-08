
// program for double circular linked list
#include<iostream>
using namespace std;
 
//Stucture of the double circular linked list
class node{
 
    public:
    int data;
    node* next;
    node* prev;
 
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

//function to insert from the head of the linked list
void insertAtHead(node* &head, int val){
    node* n=new node(val);
 
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}
//function to insert from the tail of the linked list
void insertAtTail(node* &head, int val){
 
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
 
    node* n = new node(val);
    node* temp=head;
 
    while(temp->next!=head){
        temp=temp->next;
    }
 
    temp->next=n;
    n->next=head;
    n->prev=temp;
    head->prev=temp;
}

// function to delete the node from the head of the linked list 
void deleteAtHead(node* &head){
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
 
    node* todelete=head;
    temp->next=head->next;
    head=head->next;
 
    delete todelete;
}
// function to delete the node from the linked list from the fixed position
void deletion(node* &head, int pos){
 
    if(pos==1){
        deleteAtHead(head);
        return;
    }
      node* temp=head;
      int count=1;
 
      while(count!=pos-1){
          temp=temp->next;
          count++;
      }
 
      node* todelete=temp->next;
      temp->next=temp->next->next;
 
      delete todelete;
}
//fuction to display the linked list
void display(node* head){
 
 
    node* temp=head;
    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    } while (temp!=head);
    cout<<endl;
    
}
 
 
int main(){
 
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    deletion(head,1);
    display(head);
    
 
    return 0;
}