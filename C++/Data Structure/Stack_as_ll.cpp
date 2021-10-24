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




// STACK USING ARRAY


/*
#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	// Constructor
	twoStacks(int n)
	{
		size = n;
		arr = new int[n];
		top1 = n / 2 + 1;
		top2 = n / 2;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty
		// space for new element
		if (top1 > 0) {
			top1--;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow"
				<< " By element :" << x << endl;
			return;
		}
	}

	// Method to push an element
	// x to stack2
	void push2(int x)
	{

		// There is at least one empty
		// space for new element
		if (top2 < size - 1) {
			top2++;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow"
				<< " By element :" << x << endl;
			return;
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 <= size / 2) {
			int x = arr[top1];
			top1++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element
	// from second stack
	int pop2()
	{
		if (top2 >= size / 2 + 1) {
			int x = arr[top2];
			top2--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};

// Driver program to test twStacks class 
int main()
{
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is "
		<< " : " << ts.pop1()
		<< endl;
	ts.push2(40);
	cout << "\nPopped element from stack2 is "
		<< ": " << ts.pop2()
		<< endl;
	return 0;
}
*/
