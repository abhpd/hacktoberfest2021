#include<iostream>

using namespace std;
int stack[100], top = -1, MAXSIZE, choice;

bool isEmpty();
bool isFull();
void pop();
void push();
void displayStack();

int main(){
    cout<<"Enter number of elements in stack ? "<<endl;
    cin>>MAXSIZE;
    cout<<"******************************"<<endl;
    cout<<"1. PUSH"<<endl<<"2. POP"<<endl<<"3. DISPLAY"<<endl<<"4. EXIT"<<endl;
    cout<<"******************************"<<endl;
    while(choice!=4){
        cout<<"Enter your choice ? "<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                displayStack();
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
    if(top==-1){
        return true;
    } else {
        return false;
    }
}

bool isFull(){
    if(top==MAXSIZE-1){
        return true;
    } else {
        return false;
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
    } else {
        top = top-1;
    }
}

void push(){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
    } else {
        int data;
        cout<<"Enter data to be pushed: "<<endl;
        cin>>data;
        top = top+1;
        stack[top]=data;
    }
}

void displayStack(){
    if(isEmpty()){
        cout<<"Nothing to Display, Stack is empty"<<endl;
    } else {
        cout<<"Elements of Stack->"<<endl;
        for(int i=top;i>=0;i--){
            cout<<stack[i]<<endl;
        }
    }
}