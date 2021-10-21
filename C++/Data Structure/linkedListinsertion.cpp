#include<bits/stdc++.h>
using namespace std;

class Node{                    //declaring a node class to create our own datatype of type "node"
    public:
        int data;
        Node* next;
    Node(int val){                //constructor function
        data=val;          
        next= NULL;
    }
};

void deletion(Node* &head, int val){            //function to delete a node from the linked list
    Node* temp= head;
    while(temp->next->data != val){
        temp= temp->next;
    }
    Node* todelete= temp->next;
    temp->next= temp->next->next;
    delete todelete;
}

void insert(Node* &head, int val){              //insert function to insert the value in the linked list
    Node* n= new Node(val);
    if(head==NULL){
        head=n;
        return;
    }

    
    Node* temp= head;
    while(temp->next!=NULL){
        temp= temp->next;
    }
    temp->next= n;
}

void display(Node* head){                 //creating the display function to print the linked list
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){                         //main function
    Node* head= NULL;               //creating the head pointer
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    display(head);
    deletion(head, 3);
    display(head);
}