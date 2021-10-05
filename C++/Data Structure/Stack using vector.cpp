#include<bits/stdc++.h>
using namespace std;
class Stack{
    int top;
    vector<int>v;
    public:
    Stack(){
        top=-1;
    }
    void push(int data){
        v.push_back(data);
        top++;
    }
     bool empty(){
        if(v.size()==0){
            return true;
        }
        return false;

    }
    void pop(){
        if(!empty())
       { v.pop_back();
       top--;
       }
    }
    int Peek(){
        return v[top];
    }
   
};
int main(){
    Stack s;
    s.push(1);
 s.push(2);
 s.push(3);
 s.push(4);
 s.push(5);
 s.push(6);
 cout<<"value at top:"<<s.Peek()<<endl;
 cout<<"Stack: ";
 while(!s.empty()){
     cout<<s.Peek()<<" ";
     s.pop();
 } 
}
