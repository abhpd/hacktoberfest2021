#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<string>
#include<string.h>
using namespace std;
template<int n>
#define ll long long 
const int MAX = 1000001;
#define rep(a,b,c) for(ll a=b;a<c;a++)

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

void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    {
        head->prev=n;
    }
    head=n;
}

void insertattail(node* &head,int val){
    if(head==NULL){
        insertathead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;


}
void printdoublelinkedlist(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"NULL\n";
    }

void deleteathead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}
void deleteatpos(node* &head,int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
temp->prev->next=temp->next;
if(temp->next!=NULL)
temp->next->prev=temp->prev;
delete temp;
}
int main(){
node* head=NULL;
insertattail(head,3);
insertattail(head,6);
insertattail(head,9);
insertattail(head,9);
printdoublelinkedlist(head);
deleteatpos(head,3);
printdoublelinkedlist(head);




    return 0;
}
