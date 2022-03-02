#include<iostream>
#include<string>
using namespace std;

class stack
{
    public:
    int top;
    int size;
    char *Arr;
};

void push(stack *ptr,char data)
{
   if(ptr->top==ptr->size-1)
   {
       cout<<"Stack Overflow"<<endl;
   }
   else
   {
       ptr->top++;
       ptr->Arr[ptr->top]=data;
   }
}

char pop(stack *ptr)
{
    char x;
    if(ptr->top==-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
      x=ptr->Arr[ptr->top];
      ptr->top--;
    }
    return x;
}

int isEmpty(stack ptr)
{
    if(ptr.top==-1)
    {
        return 1;
    }
    return 0;
}

int isBalanced(stack st,string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            push(&st,str[i]);
        }
        else if(str[i]==')')
        {
           if(isEmpty(st))
           {
               return 0;
           }
           pop(&st);
        }
    }
    if(isEmpty(st)==0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    string str;
    cin>>str;
    
    stack st;
    st.size=str.length();
    st.Arr=new char[st.size];
    st.top=-1;

    cout<<"Lets Check "<<isBalanced(st,str);

}
