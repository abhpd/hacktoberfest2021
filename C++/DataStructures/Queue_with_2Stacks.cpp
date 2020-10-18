#include<bits/stdc++.h>
using namespace std;

// function to transfer/push all the elements of stack 'a' into stack 'b'
void transfer(stack<int>& a,stack<int>& b)
{
    while(!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
}

// implementation of queue using 2 stacks
class Queue
{
    public:
    stack<int> main,temp; // 2 stacks -> main and temporary stacks
    
    // considering the top of main stack as front of queue and bottommost element of main stack
    Queue()
    {
        while(!main.empty())
            main.pop();
            
        while(!temp.empty())
            temp.pop();
    }
    
    // enqueue operation
    void push(int x)
    {
        transfer(main,temp); 
        main.push(x);
        transfer(temp,main);
    }
    
    // dequeue operation 
    void pop()
    {
        if(main.empty())
        {
            cout<<"Underflow\n";
            return ;
        }
        
        while(!temp.empty())
        {
            cout<<temp.top()<<" ";
            temp.pop();
        }
        
        int poppedElement = main.top();
        main.pop();
        cout<<"Element popped is: "<<poppedElement<<"\n";
    }
    
    void displayQueue()
    {
        temp = main;
        while(!temp.empty())
        {
            cout<<temp.top()<<" ";
            temp.pop();
        }
        cout<<"\n";
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(5);
    q.push(2);
    q.push(6);
    q.push(3);
    q.displayQueue();

    q.pop();
    q.displayQueue();

    q.pop();
    q.push(9);
    q.displayQueue();
    return 0;
}