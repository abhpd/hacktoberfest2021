/*
Implementation of Singly LinkedList and the following functionalities:-
Insert at position
Insert at head
Insert at tail
Display entire list
Delete from position
Delete from head
Delete from tail
Display in reverse
*/

#include<iostream>
using namespace std;

struct node
{
	char name[20];
	long int PRN;
	node* next;
};

class SLL
{
public:
	node *head;
	SLL()
	{ head=NULL; }
	void insertNode();
	void insertfirst();
	void insertlast();
	void display();
	void deletefirst();
	void deletelast();
	void deleteNode();
	void reverseDisplay(node* head);
};

void SLL::insertNode()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter name and PRN number\n";
	cin>>ptr->name>>ptr->PRN;
	cout<<"Enter the position to add\t";
	int p,count=0;
	cin>>p;
	ptr->next=NULL;
	if(head==NULL)
	{ head=ptr; }
	else
	{
		node *t=head;
		while(count<(p-1) && t)
		{
			t=t->next;
			count++;
		}
		ptr->next=t->next;
		t->next=ptr;
	}
}

void SLL::insertfirst()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter name and PRN number\n";
	cin>>ptr->name>>ptr->PRN;
	if(head==NULL)
	{ head=ptr; }
	else
	{
		ptr->next=head;
		head=ptr;
	}
}

void SLL::insertlast()
{
	node *ptr;
	ptr=new node;
	cout<<"Enter name and PRN number\n";
	cin>>ptr->name>>ptr->PRN;
	if(head==NULL)
	{ head=ptr; }
	else
	{
		node *temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=ptr;
	}
}

void SLL::display()
{
	cout<<endl;
	if(!head)
	{
		cout<<"Empty list\n";
		return;
	}
	else
	{
		int count=0;
		node *p=head;
		while(p!=NULL)
		{
			cout<<p->PRN<<"\t"<<p->name<<endl;
			p=p->next;
			count++;
		}
		cout<<endl<<"Total entries : "<<count;
	}
	cout<<endl;
}

void SLL::deleteNode()
{
	if(head==NULL)
	{ return; }
	else
	{
		int pos,count=1;
		cout<<"Enter position to delete node from\t";
		cin>>pos;
		node *p,*t;
		t=head;
		while(count<pos && t)
		{
			p=t;
			t=t->next;
			count++;
		}
		p->next=t->next;
		delete t;
		t=NULL;
	}
}

void SLL::deletefirst()
{
	if(head==NULL)
	{ return; }
	else
	{
		node *t=head;
		head=head->next;
		t->next=NULL;
		delete t;
	}
}

void SLL::deletelast()
{
	if(head==NULL)
	{ return; }
	else
	{
		node *t=head;
		node *p=NULL;
		while(t->next)
		{
			p=t;
			t=t->next;
		}
		p->next=NULL;
		delete t;
		t=NULL;
	}
}

void SLL::reverseDisplay(node* head)
{
	if(!head)
	{ return; }
	else
	{
		reverseDisplay(head->next);
		cout<<head->PRN<<"\t"<<head->name<<endl;
	}
}

int main()
{
	SLL p1,p2,p3;

	int choice;
	do{
 		cout<<"\n\tChoice of Operations:\n1.Display all data\n2.Insert first\n3.Insert last\n4.Insert node\n5.Display in Reverse\n";
 		cout<<"6.Delete first\n7.Delete last\n8.Delete Node\n9.Exit\t"<<endl;

		cin>>choice;
		switch (choice)
		{
		case 1:
			p1.display();
			break;
		case 2:
			p1.insertfirst();
			break;
		case 3:
			p1.insertlast();
			break;
		case 4:
			p1.insertNode();
			break;
		case 5:
			p1.reverseDisplay(p1.head);
			break;
		case 6:
			p1.deletefirst();
			break;
		case 7:
			p1.deletelast();
			break;
		case 8:
			p1.deleteNode();
			break;
		case 9:
			cout<<"Thank you.\n";
			break;
		default:
			cout<<"Invalid choice, Please try again.\n";
			break;
		}
	}while(choice!=9);

	return 0;
}
