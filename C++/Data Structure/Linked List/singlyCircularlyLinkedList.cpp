#include<iostream>
using namespace std;
int i, j, choice, count = 0;
struct node{
    int data;
    struct node* next;
};
void display();
void insertAtBegin();
void insertAtEnd();
void deleteAtBegin();
void deleteAtEnd();
struct node* head = NULL;
int main(){
    cout<<"1. DISPLAY THE LIST"<<endl;
    cout<<"2. INSERT AT BEGGINING"<<endl;
    cout<<"3. INSERT AT END"<<endl;
    cout<<"4. DELETE AT BEGGINING"<<endl;
    cout<<"5. DELETE AT END"<<endl;
    cout<<"6. EXIT"<<endl;
    while(choice!=6){
        cout<<"Enter your choice ? "<<endl;
        cin>>choice;
        switch(choice){
        case 1:
        display();
        cout<<"Number of elements in Linked List: "<<count<<endl;
        break;
        case 2:
        insertAtBegin();
        cout<<"Number of elements in Linked List: "<<count<<endl;
        break;
        case 3:
        insertAtEnd();
        cout<<"Number of elements in Linked List: "<<count<<endl;
        break;
        case 4:
        deleteAtBegin();
        cout<<"Number of elements in Linked List: "<<count<<endl;
        break;
        case 5:
        deleteAtEnd();
        cout<<"Number of elements in Linked List: "<<count<<endl;
        break;
        case 6:
        cout<<"Exiting..."<<endl;
        break;
        default:
        cout<<"Invalid input"<<endl;
        }
    }
    return 0;
} 
void display(){
    struct node *p;
    p = head;
    if(head==NULL){
        cout<<"List is empty, Nothing to print"<<endl;
    } else {
        cout<<"<--Printing Linked List Elements-->"<<endl;
        while(p->next!=head){
            cout<<"\t"<<p->data<<endl;
            p = p->next;
        }
        cout<<"\t"<<p->data<<endl;
    }
} 
void insertAtBegin(){
    struct node *p;
    struct node *temp = new(struct node);
    int num;
    cout<<"Enter data to be inserted: "<<endl;
    cin>>num;
    temp->data = num;
    if(head==NULL){
        head = temp;
        temp->next = head;
        cout<<"Node Inserted at Beginning"<<endl;
        count+=1;
    } else {
        p = head;
        while(p->next!=head){
            p = p->next;
        }
        temp->next = head;
        p->next = temp;
        head = temp;
        cout<<"Node Inserted at Beginning"<<endl;
        count+=1;
    }
} 

void insertAtEnd(){
    struct node *temp,*r;
    temp = new(struct node);
    r = head;
    int num;
    cout<<"Enter data to be inserted: "<<endl;
    cin>>num;
    temp->data = num;
    if(head==NULL){
        head = temp;
        temp->next = head;
        cout<<"Node Inserted at Ending"<<endl;
        count+=1;
    } else {
        while(r->next!=head){
            r = r->next;
        }
        r->next = temp;
        temp->next = head;
        cout<<"Node Inserted at Ending"<<endl;
        count+=1;
    }
}
void deleteAtBegin(){
    struct node *p = head;   
    if(head == NULL){  
        cout<<"Nothing to delete."<<endl;    
    } else if(head->next == head){  
        head = NULL;  
        delete(head);  
        cout<<"Node Deleted at Beginning."<<endl;
        count-=1;  
    } else {   
        while(p -> next != head){
            p = p -> next;
        }      
        p->next = head->next;  
        delete(head);
        head = p->next;  
        cout<<"Node Deleted at Beginning."<<endl;
        count-=1;  
    }
}
void deleteAtEnd(){
    struct node *p, *t;  
    if(head==NULL){  
        cout<<"Nothing to delete."<<endl;  
    } else if (head ->next == head){  
        head = NULL;  
        delete(head);  
        cout<<"Node Deleted at Ending."<<endl;
        count-=1;  
    } else {  
        p = head;  
        while(p ->next != head){  
            t = p;  
            p = p->next;  
        }  
        t->next = p -> next;  
        delete(p);  
        cout<<"Node Deleted at Ending."<<endl;
        count-=1;  
    }  
}