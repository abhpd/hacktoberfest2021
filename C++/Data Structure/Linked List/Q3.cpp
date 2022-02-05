/*. Create  linked list to enroll the students who wish to participate for a gaming   
    event by taking details like Name, Register No., Age, Phone number. Ensure that no more  
    than five members are there in the list with same age. Perform insertion(), deletion() and 
    display() operations on the Linked List.
*/

#include<iostream>
using namespace std;

struct student{
    string name;
    int regNo;
    int age;
    int phoneNo;
    struct student *next;
};

void insertion();
void deletion();
void display();
int counter(int);
struct student *head = NULL;
int main(){
    int choice;
    cout<<"**Game Event**"<<endl;
    head=0;
    cout<<"1.Register for the event."<<endl;
    cout<<"2.Delete registration."<<endl;
    cout<<"3.Display participant list."<<endl;
    cout<<"4.Exit"<<endl;
    while(choice!=4){
        cout<<"Enter Choice :";
        cin>>choice;
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            cout<<"Exiting..."<<endl;
            break;
        default:
            cout<<"Enter Valid Choice."<<endl;
            break;
        }
    }
    return 0;
}
int counter(int x){
    struct student *c = head;
    int count = 0;
    while(c!=NULL){
        if(c->age == x){
            count+=1;
        }
        c = c->next;
    }
    return count;
}
void insertion(){
    struct student *p = head;
    struct student *temp = new (struct student);
    cout<<"Enter name : ";
    cin>>temp->name;
    cout<<"Enter register no. : ";
    cin>>temp->regNo;
    cout<<"Enter age : ";
    cin>>temp->age;
    cout<<"Enter phone number : ";
    cin>>temp->phoneNo;
    if(head==NULL){
        head = temp;
        temp->next = NULL;
        cout<<"Successfully Registered !!"<<endl;
    } else {
        int count = counter(temp->age);
        if(count<=4){
            while(p->next!=NULL){
                p = p->next;
            }
            temp->next = NULL;
            p->next = temp;
            cout<<"Successfully Registered !!"<<endl;
        } else {
            cout<<"More than 5 members of same age not allowed"<<endl;
        }
    }
}
void deletion(){
    struct student *p = head;
    if(head==NULL){
        cout<<"Nothing to delete"<<endl;
    } else {
        head = head->next;
        delete(p);
        cout<<"Deleted Successfully!!"<<endl;
    }
}
void display(){
    struct student*p = head;
    if(head==NULL){
        cout<<"Nothing to Delete!!"<<endl;
    } else {
        while(p!=NULL){
            cout<<"Student Name: "<<p->name<<endl;
            cout<<"Student Register No: "<<p->regNo<<endl;
            cout<<"Student Age: "<<p->age<<endl;
            cout<<"Student Phone No: "<<p->phoneNo<<endl;
            cout<<endl;
            p = p->next;
        }
    } 
}