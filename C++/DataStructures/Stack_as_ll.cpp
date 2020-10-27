#include <iostream>
using namespace std;

// structure/schema of any node in the stack
struct Node {
   int data; 
   struct Node *next; // 'next' stores the address of node below the current node
};
struct Node* top = NULL; //initializing the top node of the stack as 'NULL'
int size = 0; // size of the stack

// function to create and push a node on the top of the stack
void push(int val) {
   struct Node* newnode = new Node;
   newnode->data = val;
   newnode->next = top;
   top = newnode;
   size++;
}

//function to pop the top node from the stack
void pop() {
   if(top==NULL) // if stack is empty
   cout<<"Stack Underflow\n";
   else {
      Node* temp = top;
      cout<<"The popped element is "<< temp->data <<"\n";
      top = top->next;
      delete(temp);
      size--;
   }
}

// function to display the values of all the nodes of the stack
void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack:";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

// function to display the top element of the stack
void peek()
{
    if(top==NULL) // if stack is empty
    {
        cout<<"Underflow\n";
    }
    else
    {
       cout<<top->data<<"\n";
    }
}

// function to display the size of the stack
void get_size()
{
     cout<<size<<"\n";
}

int main() {
   int ch, val;
   cout<<"1) Push\n";
   cout<<"2) Pop\n";
   cout<<"3) Display\n";
   cout<<"4) Peek\n";
   cout<<"5) check_empty\n";
   cout<<"6) size\n";
   cout<<"7) Exit\n";

   do {
      cout<<"Enter choice:\n";
      cin>>ch;
      switch(ch){
         case 1: {
            cout<<"Enter value to be pushed:\n";
            cin>>val;
            push(val);
            break;
         }
         case 2: {
            pop();
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4:{
            peek();
            break;
         }
         case 5:{
            if(top==NULL)
                cout<<"Stack is empty\n";
            else
                cout<<"Stack not is empty\n";
            break;
         }
         case 6:{
             get_size();
             break;
         }
         case 7: {
            cout<<"Exit\n";
            break;
         }
         default: {
            cout<<"Invalid\n";
         }
      }
   }while(ch!=7);
   return 0;
}
