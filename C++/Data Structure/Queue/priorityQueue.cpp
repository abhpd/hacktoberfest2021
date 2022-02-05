#include<iostream>
using namespace std;

void enQueue();
void deQueue();
void display();
bool isEmpty();
bool isFull();

int queue[100],f=-1, r=-1, MAXSIZE, data, choice, i, j;
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
                display();
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
    if(r==-1 && f==-1 || f>r){
        return true;
    } else {
        return false;
    }
}
bool isFull(){
    if(r==MAXSIZE-1){
        return true;
    } else {
        return false;
    }
}
void enQueue(){
    if(isFull()){
        cout<<"Queue Overflow"<<endl;
    } else if (f==-1){
        f++;
        r++;
        cout<<"Enter data to be inserted ? "<<endl;
        cin>>data;
        queue[r] = data;
        cout<<"Data inserted successfully."<<endl;
    } else {
        cout<<"Enter data to be inserted ?"<<endl;
        cin>>data;
        for(i=0;i<=r;i++){
            if(queue[i]<data){ //5
                continue;
            } else {
                for(j = r + 1;j>i;j--){// 1(f) 2 3 4 7 8 (r) _
                    queue[j] = queue[j-1];// 1 2 3 4 _ 7 8
                }
                r+=1;
                queue[i] = data;
                cout<<"Data inserted successfully."<<endl;
                return;
            }
        }
        r+=1;
        queue[i] = data;
        cout<<"Data inserted successfully."<<endl;
    }
}
void deQueue(){
    if(isEmpty()){
        cout<<"Queue Underflow"<<endl;
    } else {
        f = f+1;
    }
}
void display(){
    if(isEmpty()){
        cout<<"Nothing to Display, Queue is empty"<<endl;
    } else {
        cout<<"<--Elements of Queue-->"<<endl;
        for(int i=f;i<=r;i++){
            cout<<"\t"<<queue[i]<<endl;
        }
    }
}