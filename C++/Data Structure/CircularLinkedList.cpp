#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void printList(Node *head){
	Node *n=head;
	Node *temp=head;
	while (n->next!= NULL){
		n = n->next;
	}
	n->next=head;
	
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=head);
	cout<<endl;
}

int main(){
	cout<<"Enter the no of nodes : ";
	
	int n;
	cin>>n;
	
	Node *head=NULL;
	Node *end=NULL;
	
	for (int i=0;i<n;i++){
		Node *newNode=new Node();
		
		cout<<"Enter the data : ";
		int temp;
		cin>>temp;
		
		newNode->data=temp;
		
		if (head==NULL){
			head=newNode;
			end=newNode;
		}
		else{
			end->next=newNode; 
			end=newNode;
		}
    }
	printList(head);
}