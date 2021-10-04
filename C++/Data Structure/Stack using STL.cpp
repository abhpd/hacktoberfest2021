//Demonstrating C++ Standard Library class template stack
#include<iostream> 
#include<stack>
using namespace std;

// Display all elements of stack
void display(stack<int> );

int main()
{
    stack<int> st;                  //Initialisation of a stack
    st.push(1);                     //Pushing 1 into the stack
    st.push(2);                     //Pushing 2 into the stack
    st.push(3);                     //Pushing 3 into the stack
    st.push(4);                     //Pushing 4 into the stack
    st.push(5);                     //Pushing 5 into the stack

  cout<<"SIZE OF STACK IS : "<<st.size()<<endl;

  display(st);                     

  cout<<"POPPED "<<st.top()<<endl;

  st.pop();                       //Pop function remove top element of the stack

  display(st);

  cout<<"PEEK ELEMENT OF STACK IS : " << st.top()<<endl;

  cout<<"POPPED "<<st.top()<<endl;

  st.pop();

  display(st);

  cout<<"POPPED "<<st.top()<<endl;

  st.pop();

  cout<<"POPPED "<<st.top()<<endl;

  st.pop();

  cout<<"POPPED "<<st.top()<<endl;

  st.pop();

  if(st.empty())                  //empty function returs 1 if stack is empty
        cout<<"STACK IS EMPTY\n";
    else
        cout<<"STACK IS NOT EMPTY\n";
    return 0;
}
