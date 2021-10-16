#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct node *start,*p;
void insert_beginning(int item)
{
	p=new node;
	if(p==NULL)
	cout<<"Overflow";
	else
	{
		p->data=item;
		if(start==NULL)
		{
		    p->next=NULL;
		}
		else
		{
			p->next=start;
		}
		start=p;
	}
}
void display()
{
	p=start;
	while(p!=NULL)
	{
		cout<<p->data<<"-->";
		p=p->next;
		
	}
}

int main()
{
	insert_beginning(10);
	insert_beginning(20);
	insert_beginning(30);
	display();

}
