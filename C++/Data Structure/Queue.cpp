#include<iostream>
using namespace std;

#define n 20

class Queue{
    int* arr;
    int front;
    int back;

    public:
        Queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void push(int x){
            if (back==n-1){
                cout<<"Queue OverFlow"<<endl;
                return;
                }
            back++;
            arr[back] = x;
            if (front==-1){
                front++;
            }
        }

        void pop(){
            if (front==-1 || front>back){
                cout<<"Their are no elements in the queue";
                return;
            }
            front++;
        }

        int peek(){
            if (front==-1 || front>back){
                cout<<"Their are no elements in the queue";
                return -1;
            }
            return arr[front];
        }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    
    return 0;
}
