 #include<iostream>
using namespace std;
class node
{
    public:
 int data;
 node* next; // to store address of next node
 node*prev; // to store addresss of previous node

 node(int val)
 {
     data=val;
     prev=NULL;
     next=NULL;
 }
};

bool search(node* head,int target)
{
    node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==target)
        {
            cout<<target<<" found! \n";
            return true;
        }
      temp=temp->next;
    }
    cout<<target<<" not found! \n";
    return false;
}

void insertattail(node* &head,int val)
{
    node*temp=head;
    node* N= new node(val);
    if(head==NULL)
    {
        head=N;
        return;
    }
    else
  {
    while(temp->next!=NULL)      //We traverse to find the last node
    {
        temp=temp->next;
    }
    temp->next=N;
    N->prev=temp;
  }
}

void insertathead(node* &head,int val)
{
  node*n=new node(val);
  n->next=head;
  // prev of n is already pointing to NULL due to the constructor 
  if(head!=NULL)
   head->prev=n;  //if head is null then head->prev can't be accessed 
  head=n;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

void deletion(node* &head,int pos)
{
    if(pos==1)
    {
        node* todelete=head;
        head=head->next;
        head->prev=NULL;
        delete todelete;
        return;
    }
   int count=1;
   node*temp=head;
         while(temp!=NULL && count!=pos)
         {
           temp=temp->next;
           count++;
         }
         if(temp==NULL)
         {
             cout<<"No such node exists in this Linked List \n";
         }
         else
         {
             if(temp->next!=NULL)
                 temp->next->prev=temp->prev;   // 1->2->3 to delete 2(temp) , 1->3
           temp->prev->next=temp->next;
           cout<<temp->data<<" deleted ! \n";
           delete temp;
         }
}

int main()
{
    node* head=NULL;
    cout<<"Insertion at tail: \n";
    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4); 
    insertattail(head,5);
    display(head);
    cout<<"Insertion at head: \n";
    insertathead(head,10);
    insertathead(head,9);
    insertathead(head,8);
    display(head);
    deletion(head,4);
    search(head,4);
    display(head);

    return 0;
}
