#include<iostream>
using namespace std;

int queue[100], front = -1, rear = -1, MAXSIZE, choice;

bool isEmpty();
bool isFull();
void enQueue();
void deQueue();
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

bool isEmpty(){
    if(rear==-1){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if(front==(rear+1)%MAXSIZE){
        return true;
    } else {
        return false;
    }
}

void enQueue(){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    } else if(front==-1&&rear==-1){
        int data;
        front = front + 1;
        rear = rear + 1;
        cout<<"Enter data to enqueue: "<<endl;
        cin>>data;
        queue[rear] = data;
    } else {
        int data;
        rear = (rear+1)%MAXSIZE;
        cout<<"Enter data to enqueue: "<<endl;
        cin>>data;
        queue[rear] = data;

    }
}

void deQueue(){
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    } else if(front==rear){
        front = -1;
        rear = -1;
    } else {
        front = (front+1)%MAXSIZE;
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