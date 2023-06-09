//Sorting using two stacks
#include<bits/stdc++.h>
#define max 20
using namespace std;
int stack1[max],stack2[5];
int top1=-1,top2=-1;
void sort_using_stack(int *b,int n);
int pope(int *top,int *stk);
void pushe(int *top,int *stk,int d);


void pushe(int *top,int *stk,int d)
{
	*top=*top+1;
	if(*top>max)
	{
		cout<<"overflow condition"<<endl;
		return;
	}
	stk[*top]=d;
	cout<<"pushed element:"<<stk[*top]<<endl;
}

int pope(int *top,int *stk)
{
	int x;
	if(*top<0)
	{
		cout<<"underflow condition";
		return -1;
	}
	x=stk[*top];
	*top=*top-1;
	return x;
	
}

void sort_using_stack(int *b,int n)
{
	int i,x,y;
	for(i=0;i<n;i++)
	{
		if(top1<0)
		{
			pushe(&top1,stack1,b[i]);
			cout<<"if"<<endl;
		}
		else
		{
			if(stack1[top1]>b[i])
			{
			x=pope(&top1,stack1);
			cout<<x<<endl;
			pushe(&top2,stack2,x);
			pushe(&top1,stack1,b[i]);
			y=pope(&top2,stack2);
			cout<<y<<endl;
			pushe(&top1,stack1,y);
			}
			else
			pushe(&top1,stack1,b[i]);
			cout<<"else"<<endl;
		}
	}
	
    for(i=0;i<=top1;i++)
    {
    	cout<<stack1[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n,count=0,a[max],i;
	cout<<"Enter the number of element in a array:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		count++;
	}
	sort_using_stack(a,count);
}