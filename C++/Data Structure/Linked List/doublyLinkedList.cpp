#include<iostream>
using namespace std;
int i, j, choice, count = 0;
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
void insertAtBegin();
void insertAtEnd() ;
void insertAtLocation();
void deleteValue();
void display();
struct node *head = NULL;
int main(){
    cout<<"1. DISPLAY THE LIST"<<endl;
    cout<<"2. INSERT AT BEGGINING"<<endl;
    cout<<"3. INSERT AT END"<<endl;
    cout<<"4. INSERT AT PARTICULAR POSITION"<<endl;
    cout<<"5. DELETE BY VALUE"<<endl;
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
        insertAtLocation();
        cout<<"Number of elements in Linked List: "<<count<<endl;
        break;
        case 5:
        deleteValue();
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
    struct node* p;
    p = head;
    if(p==NULL){
        cout<<"Linked List is empty"<<endl;
    } else {
        cout<<"<--Printing Linked List Elements-->"<<endl;
        while(p!=NULL){
            cout<<p->data<<"<->";
            p = p->next;
        }
        cout<<"NULL"<<endl;
    }
}

void insertAtBegin(){
    struct node *temp = new(struct node);
    int num;
    if(temp==NULL){
        cout<<"Node not created"<<endl;
    } else {
        cout<<"Enter Element To Be Inserted ?"<<endl;
        cin>>num;
        temp->data = num;
        if(head==NULL){
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
            cout<<"Node inserted at beginning."<<endl;
            count++;
        } else {
            temp->next = head;
            temp->prev = NULL;
            head->prev = temp;
            head = temp;
            cout<<"Node inserted at beginning."<<endl;
            count++;
        }
    }
} 

void insertAtEnd(){
    struct node *temp, *p;
    temp = new(struct node);
    p = head;
    int num;
    if(temp==NULL){
        cout<<"Node not created"<<endl;
    } else {
        cout<<"Enter Element To Be Inserted ?"<<endl;
        cin>>num;
        temp->data = num;
        if(head==NULL){
            temp->next = NULL;
            temp->prev = NULL;
            head = temp;
            cout<<"Node inserted at ending."<<endl;
            count++;
        } else {
            while(p->next!=NULL){
                p = p->next;
            }
            temp->next = NULL;
            temp->prev = p;
            p->next = temp;
            cout<<"Node inserted at ending."<<endl;
            count++;
        }
    }
}

void insertAtLocation(){
    int pos;
    int num;
    cout<<"Enter the position at which you want to insert Node: "<<endl;
    cin>>pos;
    struct node *temp,*r, *t;
    r = head;
    if(pos==1){
        insertAtBegin();
    } else if (pos==count+1){
        insertAtEnd();
    } else if(pos>count+1){
        cout<<"There are less than "<<pos<<" Elements in linked list!!"<<endl;
    } else {
        for(i=1;i<pos;i++){
            t = r;
            r = r->next;
        }
        cout<<"Enter data to be inserted: "<<endl;
        cin>>num;
        temp = new(struct node);
        temp->data = num;
        temp->next = t->next;
        temp->prev = t;
        r->prev = temp;
        t->next = temp;
        cout<<"Node inserted at postion: "<<pos<<endl;
        count+=1;
    }
}

void deleteValue(){
    int num;
    cout<<"Enter the number you want to delete ? "<<endl;
    cin>>num;
    struct node *r, *t;
    r = head;
    if(r==NULL){
        cout<<"Linked List is empty"<<endl;
    } else {
        while(r!=NULL){
            if(r->data==num){
                if(r==head){
                    head = r->next;
                    head->prev = NULL;
                    delete(r);
                    cout<<num<<" is deleted from the linked list"<<endl;
                    count-=1;
                    return;
                } else {
                    t->next = r->next;
                    r->next->prev = t;
                    delete(r);
                    count-=1;
                    cout<<num<<" is deleted from the linked list"<<endl;
                    return;
                }
            } else {
                t = r;
                r = r->next;
            }
        }
        cout<<num<<" not found in the linked list"<<endl;
    }
} 
