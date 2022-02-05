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
void insertAtLocation();
void deleteValue();
void deleteAtLocation();
void searchElement();
void reverseList();
void countOddEven();

struct node* head = NULL;

int main(){

    while(choice!=10){
        cout<<"1. DISPLAY THE LIST"<<endl;
        cout<<"2. INSERT AT BEGGINING"<<endl;
        cout<<"3. INSERT AT END"<<endl;
        cout<<"4. INSERT AT PARTICULAR POSITION"<<endl;
        cout<<"5. DELETE AT PARTICULAR POSITION"<<endl;
        cout<<"6. DELETE BY VALUE"<<endl;
        cout<<"7. SEARCH AN ELEMENT"<<endl;
        cout<<"8. REVERSE THE LIST"<<endl;
        cout<<"9. COUNT ODD AND EVEN ELEMENTS"<<endl;
        cout<<"10. EXIT"<<endl;
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
                deleteAtLocation();
                cout<<"Number of elements in Linked List: "<<count<<endl;
                break;
            case 6:
                deleteValue();
                cout<<"Number of elements in Linked List: "<<count<<endl;
                break;
            case 7:
                searchElement();
                break;
            case 8:
                reverseList();
                break;
            case 9:
                countOddEven();
                break;
            case 10:
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
            cout<<p->data<<"->";
            p = p->next;
        }
        cout<<"head"<<endl;
    }
}

void insertAtBegin(){
    struct node *temp = new(struct node);
    int num;
    cout<<"Enter data to be inserted: "<<endl;
    cin>>num;
    temp->data = num;
    if(head==NULL){
        temp->next = NULL;
        head = temp;
        cout<<"Node Inserted at Beginning"<<endl;
        count+=1;
    } else {
        temp->next = head;
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
        temp->next = NULL;
        head = temp;
        cout<<"Node Inserted at Ending"<<endl;
        count+=1;
    } else {
        while(r->next!=NULL){
            r = r->next;
        }
        temp->next = NULL;
        r->next = temp;
        cout<<"Node Inserted at Ending"<<endl;
        count+=1;
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
        t->next = temp;
        temp->next = r;
        cout<<"Node inserted at postion: "<<pos<<endl;
        count+=1;
    }
}

void deleteAtLocation(){
    int pos;
    int num;
    struct node *temp,*r, *t;
    cout<<"Enter the position at which you want to delete Node: "<<endl;
    cin>>pos;
    r = head;
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
    } else if(pos>count+1){
        cout<<"There are less than "<<pos<<" Elements in linked list!!"<<endl;
    } else if(pos==1){
        head = r->next;
        delete(r);
        cout<<"Node deleted at position: "<<pos<<endl;
        count-=1;
    } else {
        for(i=1;i<pos;i++){
            t = r;
            r = r->next;
        }
        t->next = r->next;
        delete(r);
        cout<<"Node deleted at position: "<<pos<<endl;   
        count-=1;
    }
}

void countOddEven(){
    int even = 0;
    int odd = 0;
    struct node* p;
    p = head;
    if (head==NULL){
        cout<<"Linked List is empty"<<endl;
    } else {
        while(p!=NULL){
            if(p->data%2==0){
                even+=1;
            } else {
                odd+=1;
            }
            p = p->next;
        }
    }
    cout<<"Number of odd elements: "<<odd<<endl;
    cout<<"Number of even elements: "<<even<<endl;
}

void searchElement(){
    int toSearch, pos=1;
    bool isFound;
    struct node* p;
    p = head;
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
    } else {
        cout<<"Enter the element you want to search ? "<<endl;
        cin>>toSearch;
        while(p!=NULL){
            if(p->data==toSearch){
                cout<<toSearch<<" is found at position "<<pos<<endl;
                isFound=true;
                return;
            } else {
                isFound=false;
            }
            p = p->next;
            pos+=1;
        }
        if(!isFound){
            cout<<"Element not found!!"<<endl;
        }
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
                    delete(r);
                    cout<<num<<" is deleted from the linked list"<<endl;
                    count-=1;
                    return;
                } else {
                    t->next = r->next;
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

void reverseList(){
    struct node *prev, *curr, *next;
    prev = NULL;
    curr = head;
    next = curr->next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    display();
}