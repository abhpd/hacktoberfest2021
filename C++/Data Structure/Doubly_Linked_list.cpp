//Doubly linked list various operation
#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
	int data;
	Node*prev;
	Node*next;
};
Node* Create_Doubly_Linked_List(Node*head)
{
	int data;
	cout<<"Enter the data of Node:\t";
	cin>>data;
	Node*p=(Node*)malloc(sizeof(Node));
	p->prev=NULL;
	p->data=data;
	p->next=NULL;
	Node*ptr;
	if(head==NULL)
	{
		head=p;
		ptr=head;
		return head;
	}
	else
	{
		ptr->next=p;
		p->prev=ptr;
		ptr=p;
		return head;
	}
}
void Print_Doubly_Linked_List(Node*head)
{
	Node*p=head;
	while(p!=NULL)
	{
		cout<<"Element is:\t"<<p->data<<"\n";
		p=p->next;
	}
}
Node*Insertion_At_Beginning(Node*head,int data)
{
	Node*p=(Node*)malloc(sizeof(Node));
	p->prev=NULL;
	p->data=data;
	p->next=head;
	head->prev=p;
	head=p;
	return head;
}
Node*Insertion_At_Index(Node*head,int data,int index)
{
	Node*p=(Node*)malloc(sizeof(Node));
	p->prev=NULL;
	p->data=data;
	p->next=NULL;
	Node*ptr=head;
	int i=0;
	if(index==0)
	{
		head=Insertion_At_Beginning(head,data);
		return head;
	}
	else
	{
		while(i!=index-1)
		{
			ptr=ptr->next;
			i++;
		}
		p->next=ptr->next;
		ptr->next->prev=p;
		ptr->next=p;
		p->prev=ptr;
		return head;
	}	
}
Node*Insertion_At_Last(Node*head,int data)
{
	Node*p=(Node*)malloc(sizeof(Node));
	p->prev=NULL;
	p->data=data;
	p->next=NULL;
	Node*ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=p;
	p->prev=ptr;
	return head;
}
Node*Insertion_At_Node(Node*head,int data, int node)
{
	Node*p=(Node*)malloc(sizeof(Node));
	p->data=data;
	Node*ptr=head;
	int i=1;
	if(node==i)
	{
		head=Insertion_At_Beginning(head,data);
		return head;
	}
	else
	{
		while(i!=node-1)
		{
			ptr=ptr->next;
			i++;
		}
		p->next=ptr->next;
		ptr->next->prev=p;
		ptr->next=p;
		p->prev=ptr;
		return head;
	}
}
Node*Deletion_At_Beginning(Node*head)
{
	Node*p=head;
	head->next->prev=head->prev;
	head=head->next;
	free(p);
	return head;
}
Node*Deletion_At_Index(Node*head,int index)
{
	Node*p=head;
	int i=0;
	if(index==i)
	{
		head=Deletion_At_Beginning(head);
		return head;
	}
	else
	{
		while(i!=index-1)
		{
			p=p->next;
			i++;
		}
		Node*ptr=p->next;
		p->next=ptr->next;
		ptr->next->prev=p;
		free(ptr);
		return head;
	}
}
Node*Deletion_At_Last(Node*head)
{
	Node*p=head;
	Node*ptr=head->next;
	while(ptr->next!=NULL)
	{
		p=p->next;
		ptr=ptr->next;
	}
	p->next=ptr->next;
	free(ptr);
	return head;
}
Node*Deletion_At_Node(Node*head,int node)
{
	Node*p=head;
	int i=1;
	if(node==i)
	{
		head=Deletion_At_Beginning(head);
		return head;
	}
	else
	{
		while(i!=node-1)
		{
			p=p->next;
			i++;
		}
		Node*ptr=p->next;
		p->next=ptr->next;
		ptr->next->prev=p;
		free(ptr);
		return head;
	}
}
void Insertion_In_Doubly_Linked_List(Node*head,int data)
{
	cout<<"Press 1 for Insertion at beginning.\n";
	cout<<"Press 2 for Insertion at Index.\n";
	cout<<"Press 3 for Insertion at Last.\n";
	cout<<"Press 4 for Insertion at Node.\n";
	int ch;
	cout<<"Enter your choice:\t";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Doubly Linked List after insertion:\n";
			head=Insertion_At_Beginning(head,data);
			Print_Doubly_Linked_List(head);
		break;
		case 2:
			int index;
			cout<<"Enter the index you want to insert:\t";
			cin>>index;
			cout<<"Doubly Linked List after insertion:\n";
			head=Insertion_At_Index(head,data,index);
			Print_Doubly_Linked_List(head);
		break;
		case 3:
			cout<<"Doubly Linked List after insertion:\n";
			head=Insertion_At_Last(head,data);
			Print_Doubly_Linked_List(head);
		break;
		case 4:
			int N;
			cout<<"Enter the Node you want to insert:\t";
			cin>>N;
			cout<<"Doubly Linked List after insertion:\n";
			head=Insertion_At_Node(head,data,N);
			Print_Doubly_Linked_List(head);
		break;
		default:
			cout<<"You have entered wrong choice.\n";
		break;
	}
}
void Deletion_In_Doubly_Linked_List(Node*head)
{
	cout<<"Press 1 for Deletion at Beginning.\n";
	cout<<"Press 2 for Deletion at Index.\n";
	cout<<"Press 3 for Deletion at Last.\n";
	cout<<"Press 4 for Deletion at Node.\n";
	int ch;
	cout<<"Enter your choice:\t";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Doubly Linked List after deletion:\n";
			head=Deletion_At_Beginning(head);
			Print_Doubly_Linked_List(head);
		break;
		case 2:
			int index;
			cout<<"Enter the index you want to delete:\t";
			cin>>index;
			cout<<"Doubly Linked List after deletion:\n";
			head=Deletion_At_Index(head,index);
			Print_Doubly_Linked_List(head);
		break;
		case 3:
			cout<<"Doubly Linked List after deletion:\n";
			head=Deletion_At_Last(head);
			Print_Doubly_Linked_List(head);
		break;
		case 4:
			int N;
			cout<<"Enter the node you want to delete:\t";
			cin>>N;
			cout<<"Doubly Linked List after deletion:\n";
			head=Deletion_At_Node(head,N);
			Print_Doubly_Linked_List(head);
		break;
		default:
			cout<<"You have entered wrong choice.";
		break;
	}
}
Node*Reverse_Of_Doubly_Linked_list(Node*head)
{
	Node*p=head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	head=p;
	Node*ptr=head;
	while(ptr!=NULL)
	{
		ptr->next=ptr->prev;
		ptr=ptr->next;
	}
	return head;
}
int main()
{
	int n,i;
	cout<<"Enter the number of nodes you want in linked list:\t";
	cin>>n;
	Node*head=NULL;
	for(i=0;i<n;i++)
	{
		head=Create_Doubly_Linked_List(head);
	}
	cout<<"Doubly linked list before any operation:\n";
	Print_Doubly_Linked_List(head);	
	cout<<"Press 1 for Insertion.\n";
	cout<<"Press 2 for Deletion.\n";
	cout<<"Press 3 for Reverse.\n";
	int ch;
	cout<<"Enter your choice:\t";
	cin>>ch;
	switch(ch)
	{
		case 1:
			int data;
			cout<<"Enter the data you want insert:\n";
			cin>>data;
			Insertion_In_Doubly_Linked_List(head,data);
		break;
		case 2:
			Deletion_In_Doubly_Linked_List(head);
		break;
		case 3:
			cout<<"Reverse of doubly linked list:\n";
			head=Reverse_Of_Doubly_Linked_list(head);
			Print_Doubly_Linked_List(head);
		break;
		default:
			cout<<"You have entered wrong choice.";
		break;
	}
	return 0;
}
