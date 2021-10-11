#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int n1,n2,n3;
class Stack {
	public:
    		int a[MAX]; // Maximum size of Stack
    		int top;
    		Stack() { top = -1; }
    		bool push(int x);
    		int pop();
    		int peek();
    		bool isEmpty();
};
 
bool Stack::push(int x) //this function returns a boolean value to confirm whether the stack still has space for new elements
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        a[++top] = x;
        
        return true;
    }
}
 
int Stack::pop()	//used to remove the top element of the stack
{
    if (top < 0) {
        cout << "Stack Underflow";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()	//displays the elemnet at the top of stack
{
    if (top < 0) {
        cout << "Stack is Empty";
        return 0;
    }
    else {
        int x = a[top];
        return x;
    }
}
 
bool Stack::isEmpty()		//used to check whether Stack contains any value or is empty
{
    return (top < 0);
}
 
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    class Stack s1,s2,s3;    //here we have declared 3 instances of class stack defined above 
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    for(int i = h1.size()-1;i>=0;i--)
    {
        t1+=h1[i];
        s1.push(t1);
    }
    
    for(int i = h2.size()-1;i>=0;i--)
    {
        t2+=h2[i];
        s2.push(t2);
    }
    
    for(int i = h3.size()-1;i>=0;i--) {
        t3+=h3[i];
        s3.push(t3);
    }
    cout<<"Stored the cumulative sum of heights in the stacks\n";
    while(1){
    if(s1.isEmpty() || s2.isEmpty() || s3.isEmpty())
    return 0;
    t1 =s1.peek();		//Storing the topmost element of stack for Comparing
    t2 =s2.peek();
    s3 =s3.peek();
            // If sum of all three stack are equal.
            if (t1 == t2 && t2 == t3)
            {
              cout<<"Stacks are equal when the height is ";
              return t1;
            }                
            // Finding the stack with maximum sum and
            // removing its top element.
            if (t1 >= t2 && t1 >= t3)
            {
              cout<<"Stack 1 has the greatest element at it's top, pop the element\n\n";
              s1.pop();
            }                
            else if (t2 >= t1 && t2>= t3)
            {
              cout<<"Stack 2 has the greatest element at it's top, pop the element\n\n";
              s2.pop();
            } 
            else if (t3 >= t2 && t3 >= t1)
            {
              cout<<"Stack 3 has the greatest element at it's top, pop the element\n\n";
              s3.pop();
            } 
    }
       
}
 
// Driver program to run & test above func()
int main()
{       
        cout<<"Enter Size of Stack 1\n";
        cin>>n1;
        cout<<"Enter Size of Stack 2\n";
        cin>>n2;
        cout<<"Enter Size of Stack 3\n";
        cin>>n3;
        //taking the size of the three stacks as n1,n2,n3
        vector<int> h1;
        vector<int> h2;
        vector<int> h3;
        int num1,num2,num3;
        cout<<"Enter Elements of Stack 1\n";
        for (int i = 0; i < n1; i++) {
            
            cin>>num1;
            h1.push_back(num1); //push_back is used to insert an element in the vector at the end */
        }
        cout<<"Enter Elements of Stack 2\n";
        for (int i = 0; i < n2; i++) {
            
            cin>>num2;
            h2.push_back(num2);
        }
        cout<<"Enter Elements of Stack 3\n";
        for (int i = 0; i < n3; i++) {
            
            cin>>num3;
            h3.push_back(num3);
        }		//we have successfully added all the elements of the stack one by one from the end
        int result=equalStacks(h1, h2, h3);
        cout<<result;
        return 0;
}
