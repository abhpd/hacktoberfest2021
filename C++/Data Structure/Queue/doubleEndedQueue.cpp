#include<iostream>
using namespace std;

int deQueue[100], MAXSIZE, choice, f = -1, r = -1;

bool isEmpty();
bool isFull();
void enQueueFront();
void enQueueRear();
void deQueueFront();
void deQueueRear();
void getFront();
void getRear();
void display();

int main(){
    cout<<"Enter number of elements in DE Queue ? "<<endl;
    cin>>MAXSIZE;
    cout<<"******************************"<<endl;
    cout<<"1. ENQUEUE FRONT"<<endl<<"2. ENQUEUE REAR"<<endl<<"3. DEQUEUE FRONT"<<endl<<"4. DEQUEUE REAR"<<endl<<"5. GET FRONT ELEMENT"<<endl<<"6. GET REAR ELEMENT"<<endl<<"7. DISPLAY DE QUEUE"<<endl<<"8. EXIT"<<endl;
    cout<<"******************************"<<endl;
    while(choice!=8){
        cout<<"Enter your choice ? "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                enQueueFront();
                break;
            case 2:
                enQueueRear();
                break;
            case 3:
                deQueueFront();
                break;
            case 4:
                deQueueRear();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getRear();
                break;
            case 7:
                display();
                break;
            case 8:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!!"<<endl;
        }
    }
    return 0;
}

bool isEmpty(){
    if(f==-1&&r==-1){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if((f==0 && r==MAXSIZE-1) || f==r+1){
        return true;
    } else {
        return false;
    }
}

void enQueueFront(){
    if(isFull()){
        cout<<"DE Queue Overflow"<<endl;
    } else if((f==-1) && (r==-1)) {
        f = r = 0;
        int data;
        cout<<"Enter data to be inserted: "<<endl;
        cin>>data;
        deQueue[f]=data;
        cout<<data<<" inserted at front."<<endl;
    } else if(f==0) {
        f = MAXSIZE-1;
        int data;
        cout<<"Enter data to be inserted: "<<endl;
        cin>>data;
        deQueue[f]=data;
        cout<<data<<" inserted at front."<<endl;
    } else {
        f = f - 1;
        int data;
        cout<<"Enter data to be inserted: "<<endl;
        cin>>data;
        deQueue[f]=data;
        cout<<data<<" inserted at front."<<endl;
    }
} 

void enQueueRear(){
    if(isFull()){
        cout<<"DE Queue Overflow"<<endl;
        return;
    } else if (r==-1){
        f = 0;
        r = 0;
        int data;
        cout<<"Enter data to be inserted: "<<endl;
        cin>>data;
        deQueue[r]=data;
        cout<<data<<" inserted at rear."<<endl;
    } else if(r==MAXSIZE-1){
        r = 0;
        int data;
        cout<<"Enter data to be inserted: "<<endl;
        cin>>data;
        deQueue[r]=data;
        cout<<data<<" inserted at rear."<<endl;
    } else {
        r = r + 1;
        int data;
        cout<<"Enter data to be inserted: "<<endl;
        cin>>data;
        deQueue[r]=data;
        cout<<data<<" inserted at rear."<<endl;
    }
}

void deQueueFront(){
    if(isEmpty()){
        cout<<"DE Queue Underflow"<<endl;
        return;
    } else if(f==r){
        cout<<"Deleted element is: "<<deQueue[f]<<endl;
        f = -1;
        r = -1;
    } else if(f==MAXSIZE-1){
        cout<<"Deleted element is: "<<deQueue[f]<<endl;
        f = 0;
    } else {
        cout<<"Deleted element is: "<<deQueue[f]<<endl;
        f = f + 1;
    }
}

void deQueueRear(){
    if(isEmpty()){
        cout<<"DE Queue Underflow"<<endl;
        return;
    } else if(f==r){
        cout<<"Deleted element is: "<<deQueue[r]<<endl;
        f -= 1;
        r -= 1;
    } else if(r==0){
        cout<<"Deleted element is: "<<deQueue[r]<<endl;
        r = MAXSIZE - 1;
    } else {
        cout<<"Deleted element is: "<<deQueue[r]<<endl;
        r = r - 1;
    }
}

void getFront(){
    if(isEmpty()){
        cout<<"DE Queue Underflow"<<endl;
    } else {
        cout<<"Element at front position is: "<<deQueue[f]<<endl;
    }
}

void getRear(){
    if(isEmpty()){
        cout<<"DE Queue Underflow"<<endl;
    } else {
        cout<<"Element at rear position is: "<<deQueue[r]<<endl;
    }
}

void display(){
    if(isEmpty()){
        cout<<"DE Queue Underflow"<<endl;
        return;
    } 
    cout<<"<--Elements of DE Queue are-->"<<endl;
    if(f<=r){
        while(f<=r){
            cout<<deQueue[f]<<endl;
            f++;
        }
    } else {
        while(f<=MAXSIZE-1){
            cout<<deQueue[f]<<endl;
            f++;
        }
        f=0;
        while(f<=r){
            cout<<deQueue[f]<<endl;
            f++;
        }
    }
}
