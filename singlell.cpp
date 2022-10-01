#include<iostream>
#include<stdlib.h>

using namespace std; 

struct node* create_node(int value);
void insert_node(node** head,int k,int data);
void delete_node(node** head,int k);
void insert_at_end(node** head,int data);
void delete_at_end(node** head);
void print_node(node* head,int k);
void print_list(node* head);

struct node{
	int data;
	node* link; };

int main(void){

	struct node* head = create_node(10);
	cout << "Creating a linked list with initial element 10\n";

    insert_at_end(&head,20);
    insert_at_end(&head,30);
    insert_at_end(&head,40);
    
    print_list(head);
    
    cout << "\n";

	cout<<"Inserting new element = 15 at 3rd position" << endl;
	insert_node(&head,3,15);
    cout << "\n";
    insert_node(&head,1,0);
    
    print_list(head);

    cout << "Deleting head element";
    delete_node(&head,1);
    cout << "\n";
    print_list(head);

    cout << "Deleting tail element";
    delete_at_end(&head);
    cout << "\n";
    print_list(head);

    
	

}

struct node* create_node(int value)
{
    
    struct node* Node = (struct node*)malloc(sizeof(struct node));
    Node->data = value;
    Node->link = NULL;
 
    return Node;
}

void insert_at_end(struct node** head,int data)
{
	
	struct node* newnode= create_node(data);
	
	struct node* temp = *head ; 
	while( temp->link != NULL )
	{
		temp = temp->link; }
		
	temp->link = newnode;

}

void delete_at_end(node** head)
{

	struct node* temp = *head ; 
	while( temp->link->link != NULL )
	{
		temp = temp->link; }
		
	temp->link = NULL ;

}

void delete_node(node** head,int k)
{	
	struct node* temp = *head ;
	
	if (k == 1) {
        
        temp = temp->link;
        *head = temp;
         }
        
    else {
        for (int i = 1; i < k - 1; i++) {
            temp = temp->link;
        }
        
        struct node* del = temp->link; 
        temp->link = temp->link->link;
        *head = temp;
        
        del->link = NULL;
        free(del); 
    }
    
}

void insert_node(node** head,int k,int data)
{
	struct node* newnode= create_node(data);
	struct node* temp = *head ;
	
	if (k == 1) {
        
        newnode->link = temp ;
        temp = newnode;
        *head = temp;
         }
        
    else {
        for (int i = 1; i < k - 1; i++) {
            temp = temp->link;
        }
        
     	newnode->link = temp->link ;
        temp = newnode;
        *head = temp;}
}

void print_node(node* head,int k)
{
	for (int i =1 ; i < k ; i++){
		head=head->link;
		}
		
	cout << head->data <<endl;
	
}

void print_list(node* head)
{
	while(head->link != NULL)
	{	cout<< head->data << " " ; 
		head = head->link; }
	
	cout<< head->data <<endl; 
}


		
	

		
	
