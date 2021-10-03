#include<bits/stdc++.h>
using namespace std;

class Node{                      //class to define the node of linked list
    public:
    int data;
    Node* next;

    Node(int val){               //constructor
        data= val;
        next=NULL;
    }
};

int length(Node* head){           //function to find the length of the linked list
    int l=0;
    Node* temp= head;
    while(temp!= NULL){
        l++;
        temp= temp->next;
    }
    return l;
}

void insertAtTail(Node* &head, int val){            //function to insert a node at the tail of the current linked list

    Node* n= new Node(val);

    if(head==NULL){
        head= n;
        return;
    }

    Node* temp= head;
    while(temp->next== NULL){
        temp= temp->next;
    }
    temp->next= n;
    return;
    
}

Node* kAppend(Node* &head, int k){   //function to append the last k nodes of the linked list to the begining of the list
    Node* newHead;
    Node* newTail;
    Node* tail= head;
    int l= length(head);
    k=k%l;
    int count=1;

    while(tail->next!=NULL){
        if(count== l-k){
            newTail= tail;
        }
        if(count== l-k+1){
            newHead= tail;
        }
        tail= tail->next;
        count++;
    }
    newTail->next= NULL;
    tail->next= head;
    return newHead;
}

void display(Node* head){               //display function to display the linked list 
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
    return;
}

int main(){                           //main function
    Node* head= NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i=0; i<6; i++){
        insertAtTail(head, arr[i]);
    }
    display(head);
    Node* newHead= kAppend(head, 3);
    display(head);
}