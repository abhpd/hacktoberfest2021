#include<bits/stdc++.h>
using namespace std;
class node{
public :
 int data;
 node* next;
 node* prev;
 node(int data){
 this->data = data;
 this->next = NULL;
 this->prev = NULL;
 }
};
void insertAtHead(node* &head, int data){
 node* temp = new node(data);
 temp->next = head;
 temp->prev = NULL;
 head = temp;
}
void insertAtTail(node* &head, int data){
 node* temp = head;
 while(temp->next!=NULL){
 temp = temp->next;
 }
 temp->next = new node(data);
 temp->next->next = NULL;
 temp->next->prev = temp;
}
void insertAtAnyPos(node* &head, int data, int pos){
 if(pos == 1){
 insertAtHead(head,data);
 return;
 }
 int len = 0;
 node* temp = head;
 while(temp!=NULL){
 len++;
 temp = temp->next;
 }
 if(len+1 == pos){
 insertAtTail(head,data);
 return;
 }
 if(pos > len){
 cout<<"Wrong position"<<endl;
 return;
 }
 temp = head;
 while(temp->next!=NULL and pos!=2){
 temp = temp->next;
 pos--;
 }
 node* n = new node(data);
 n->next = temp->next;
 n->prev = temp;
 temp->next->prev = n;
 temp->next = n;
}
void insertion(node* &head){
 int ch, data;
 cout<<"1)Insert at Head\n";
 cout<<"2)Insert at Tail\n";
 cout<<"3)Insert at any position \n";
 cout<<"Enter choice : \n";
 cin>>ch;
 cout<<"Enter the data : \n";
 cin>>data;
 switch(ch){
 case 1 : insertAtHead(head,data);
 break;
 case 2 : insertAtTail(head,data);
 break;
 case 3 : cout<<"Enter the position : \n";
 int pos;
 cin>>pos;
 insertAtAnyPos(head,data,pos);
 break;
 default : cout<<"Wrong Choice\n"<<endl;
 }
}
void deleteAtHead(node* &head){
 node* temp = head;
 head = head->next;
 head->prev = NULL;
 delete temp;
}
void deleteAtTail(node* &head){
 node* temp = head;
 while(temp->next->next!=NULL){
 temp = temp->next;
 }
 node* toDel = temp->next;
 temp->next = NULL;
 delete toDel;
}
void deleteAtAnyPos(node* &head, int pos){
 if(pos == 1){
 deleteAtHead(head);
 return;
 }
 int len = 0;
 node* temp = head;
 while(temp!=NULL){
 len++;
 temp = temp->next;
 }
 if(pos > len){
 cout<<"Wrong position\n";
 return;
 }
 if(len == pos){
 deleteAtTail(head);
 return;
 }
 temp = head;
 while(temp->next!=NULL and pos!=2){
 pos--;
 temp = temp->next;
 }
 node* toDel = temp->next;
 temp->next = temp->next->next;
 temp->next->prev = temp;
 delete toDel;
}
void deletion(node* &head){
 int ch;
 cout<<"1)Delete at Head\n";
 cout<<"2)Delete at Tail\n";
 cout<<"3)Delete at any position \n";
 cout<<"Enter choice : \n";
 cin>>ch;
 switch(ch){
 case 1 : deleteAtHead(head);
 break;
 case 2 : deleteAtTail(head);
 break;
 case 3 : cout<<"Enter the position : \n";
 int pos;
 cin>>pos;
 deleteAtAnyPos(head,pos);
 break;
 default : cout<<"Wrong Choice\n";
 }
}
void display(node* head){
 node* temp = head;
 cout<<"Link List => ";
 while(temp!=NULL){
 cout<<temp->data<<" -> ";
 temp = temp->next;
 }
 cout<<endl;
}
void displayReverse(node* head){
 node* temp = head;
 while(temp->next!=NULL){
 temp = temp->next;
 }
 cout<<"Link List in reverse => ";
 while(temp!=NULL){
 cout<<temp->data<<" -> ";
 temp = temp->prev;
 }
 cout<<endl;
}
void search(node* head){
 int data,pos = 1;
 cout<<"Enter the data to find : ";
 cin>>data;
 node* temp = head;
 while(temp!=NULL){
 if(temp->data == data){
 cout<<"Element Found at position "<<pos<<endl;
 return;
 }
 pos++;
 temp = temp->next;
 }
 cout<<"Element not found"<<endl;
}
void isEmpty(node* head){
 if(head==NULL){
 cout << "LL is empty" <<endl;
 }else{
 cout << "LL is not empty" << endl;
 }
}
int main(){
 node* head = NULL;
 int ch;
 cout<<"1)Insert\n";
 cout<<"2)Deletion\n";
 cout<<"3)Search\n";
 cout<<"4)Display\n";
 cout<<"5)Display reverse"<<endl;
 cout<<"6)check is empty\n"<<endl;
 cout<<"Enter your choice : \n";
 cin>>ch;
 while(ch >= 1 and ch <= 6){
 switch(ch){
 case 1 : insertion(head);
 display(head);
 break;
 case 2 : deletion(head);
 display(head);
 break;
 case 3 : search(head);
 display(head);
 break;
 case 4 : display(head);
 break;
 case 5 : displayReverse(head);
 break;
 case 6 : isEmpty(head);
 break;
 }
 cout<<"Enter your choice : \n";
 cin>>ch;
 }
}
