#include<iostream>
#include<string>
using namespace std;

class stack
{
    public:
    int top;
    int size;
    char *A;
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

char topElement(stack st)
{
    return st.A[st.top];
}

void push(stack *temp,char d)
{
   if(temp->top==temp->size-1)
   {
      cout<<"Stack OverFlow"<<endl;
      return;
   }
   else
   {
       temp->top++;
       temp->A[temp->top]=d;
       return;
   }
}

char pop(stack *temp)
{
    if(temp->top==-1)
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
      char x;
      x=temp->A[temp->top];
      temp->top--;
      return x;
    }
}

int precendence(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
    else
        return 0;        
}

string postfix(stack stk,string st)
{
  string post="";
  for(int i=0;i<st.length();i++)
  {
     if(precendence(st[i])==0)
     {
        post+=st[i];
     }
     else
     {
         if(isEmpty(stk)==1 || precendence(st[i]) > precendence(topElement(stk)))
         {
            push(&stk,st[i]);
         }
         else
         {
             while(isEmpty(stk)==0)
             {
                 post+=pop(&stk);
             }
             push(&stk,st[i]);
         } 
     }
  }

  while(!isEmpty(stk))
  {
      post+=pop(&stk);
  }
    return post;
}

int main()
{
    string st;
    cin>>st;
    stack stk;
    stk.top=-1;
    stk.size=st.length();
    stk.A = new char(stk.size);
    
    cout<<postfix(stk,st);
}
