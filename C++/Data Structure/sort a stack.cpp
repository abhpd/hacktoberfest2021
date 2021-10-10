//@soumyaagr427

#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}


//function to insert the elements in sorted order
void sortedinsert(stack<int>& s,int val)
{
    if(s.size()==0 || s.top()<val)
    {
        s.push(val);
        //if empty stack or top element is less then value-> insert into stack
    }
    else{ 
        
        int temp=s.top();
        s.pop();
        sortedinsert(s,val);
        s.push(temp);
    }
}

void SortedStack::sort()
{
    if(!s.empty())   
    
    {   int x=s.top();
       s.pop();
       sort();
       sortedinsert(s,x);
    }
  
}
