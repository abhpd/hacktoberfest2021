#include <iostream>
using namespace std;

struct node{
    int age;
    string name;
    string disease;
    string doctor;
    struct node *next;
};

int choice;
void enqueue();
void dequeue();
void display();
struct node*head = NULL;
int main(){
    while (choice != 4){
        cout<<"1. Admit a patient"<<endl;
        cout<<"2. Discharge a patient"<<endl;
        cout<<"3. Display patient list"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice){
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"Exiting"<<endl;
            break;
        default:
            cout<<"Invalid Choice"<<endl;
        };
    }
    return 0;
}

void enqueue() {
    struct node *temp = new (struct node);
    cout<<"Patient's name: ";
    cin>>temp->name;
    cout<<"Patient's age: ";
    cin>>temp->age;
    cout<<"Disease of patient: ";
    cin>>temp->disease;
    cout<<"Doctor assigned to patient: ";
    cin>>temp->doctor;
    if (head == NULL){
        head = temp;
        head->next = NULL;
    }
    else if (head->next == NULL){
        if (head->age > temp->age){
            head->next = temp;
            temp->next = NULL;
        } else {
            temp->next = head;
            head = temp;
        }
    } else {
        struct node *r;
        r = head;
        while (r->next != NULL){
            if (r->next->age > temp->age){
                r = r->next;
            } else {
                break;
            }
        } 
        if (r == head) {
            temp->next = head;
            head = temp;
        } else {
            temp->next = r->next;
            r->next = temp;
        }
    }
}
void dequeue (){  
    struct node *ptr;  
    if(head == NULL){  
        cout<<"No patient to discharge"<<endl;  
        return;  
    } else {  
        ptr = head;  
        head = head -> next;  
        delete(ptr); 
        cout<<"Patient Discharged"<<endl; 
    }  
}  
void display(){
    int c = 0;
    struct node *r;
    r = head;
    while (r != NULL){
        c++;
        cout<<"Patient  No. : "<<c<<endl;
        cout<<"Name: "<<r->name<<endl;
        cout<<"Age: "<<r->age<<endl;
        cout<<"Disease: "<<r->disease<<endl;
        cout<<"Doctor: "<<r->doctor<<endl;
        cout<<endl;
        r = r->next;
    }
}



