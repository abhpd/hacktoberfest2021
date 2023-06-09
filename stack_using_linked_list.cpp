#include<bits/stdc++.h>
using namespace std;
template<typename T>    // for choice of data type
class Node{
    public:
    T data;
    Node* next;

    Node(T data){
        this->data=data;
        next=NULL;
    }
};

template<typename T>
class StackUsingLL{
    Node<T>* head;
    int count;

    public:
    StackUsingLL(){
        head=NULL;
        count=0;
    }
    int getSize(){
        return count;
    }
    bool isEmpty(){
        return count==0;
    }
    void push(T element){
        Node<T>*newNode=new Node<T>(element);
        newNode->next=head;
        head=newNode;
        count++;
    }
    T pop(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return 0;
        }
        T returnValue=head->data;
        Node<T>*temp=head;
        head=head->next;
        delete temp;
        count--;
        return returnValue;
    }
    T top(){
        if(isEmpty()){
            cout<<"stack empty"<<endl;
            return 0;
        }
        return head->data;
    }
};

int main(){
    StackUsingLL<int>s;
    int arr[]={1,2,3,4};
    for(int i=0;i<4;i++){
        s.push(arr[i]);
    }
    for(int i=0;i<4;i++){
        cout<<s.pop()<<endl;
    }
}