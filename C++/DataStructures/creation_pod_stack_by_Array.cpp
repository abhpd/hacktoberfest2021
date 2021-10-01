#include<iostream>
using namespace std;

class stack
{
    public:
    int top;
    int size;
    int *A;
};

int isEmpty(stack temp)
{
  if(temp.top==-1)
  {
      return 1;
  }
  return 0;
}

int isFull(stack temp)
{
   if(temp.top==temp.size-1)
   {
       return 1;
   }
   return 0;
}

int peek(stack temp,int i)
{
   int pos=temp.top+i-1;
   
   if(pos<0)
   {
       cout<<"Invalid Position"<<endl;
       return -1;
   }
   else
   {
       return temp.A[pos];
   }
}

void push(stack *temp,int data)
{
   if(temp->top==temp->size-1)
   {
      cout<<"Stack OverFlow"<<endl;
      return;
   }
   else
   {
       temp->top++;
       temp->A[temp->top]=data;
       return;
   }
}

int pop(stack *temp)
{
    if(temp->top==-1)
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else
    {
      int x=-1;
      x=temp->A[temp->top];
      temp->top--;
      return x;
    }
}

int main()
{
   stack st;
   cout<<"Enter the Lenght Of your Stack : ";
   cin>>st.size;
   st.top=-1;
   st.A =new int[st.size];
   
   cout<<"Choice Your Operatations : ";
   while(true)
   {
    cout<<"1. Insert \n"<<"2. Deletion \n"<<"3. Empty ?\n"<<"4. Full ?\n"<<"5. Give the Index to know about element.\n"<<endl;
    int choice=0;
    cin>>choice;
    switch (choice)
    {
    case 1:
        int data;
        cin>>data;
        push(&st,data);
        break;

    case 2:
        cout<<pop(&st)<<" is Deleted"<<endl;
        break;    
    
    case 3:
        cout<<isEmpty(st)<<endl;
        break;

    case 4:
        cout<<isFull(st)<<endl;
        break;

    case 5:
        int index;
        cin>>index;
        cout<<peek(st,index)<<endl;
        break;

    default:
        cout<<"Invalid Choice";
        break;
    }
   }
}
