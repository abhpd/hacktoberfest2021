#include<iostream>
using namespace std;
int queue[100], front = -1, rear = -1, MAXSIZE, choice;
bool isFull();
bool isEmpty();
void deQueue();
void enQueue();
void displayQueue();

int main(){
    cout<<"Enter number of elements in queue ? "<<endl;
    cin>>MAXSIZE;
    cout<<"******************************"<<endl;
    cout<<"1. ENQUEUE"<<endl<<"2. DEQUEUE"<<endl<<"3. DISPLAY"<<endl<<"4. EXIT"<<endl;
    cout<<"******************************"<<endl;
    while(choice!=4){
        cout<<"Enter your choice ? "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice!!"<<endl;
        }
    }
    return 0;


}

bool isFull(){
    if(rear == MAXSIZE-1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
    if((front==-1 && rear == -1) || front>rear){
        return true;
    } else {
        return false;
    }
}

void deQueue(){
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    } else {
        cout<<"Element Dequeued"<<endl;
        front = front + 1;
    }
}

void enQueue(){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    } else if (front == -1 && rear == -1){
        int data;
        cout<<"Enter data to enqueue: "<<endl;
        cin>>data;
        rear = rear + 1;
        front = front + 1;
        queue[rear] = data;
        cout<<"Element Enqueued"<<endl;
    } else {
        int data;
        cout<<"Enter data to enqueue: "<<endl;
        cin>>data;
        rear = rear + 1;
        queue[rear] = data;
        cout<<"Element Enqueued"<<endl;
    }
}

void displayQueue(){
    if(isEmpty()){
        cout<<"Nothing to Display, Queue is empty"<<endl;
    } else {
        cout<<"<--Elements of Queue-->"<<endl;
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<endl;
        }
    }
}