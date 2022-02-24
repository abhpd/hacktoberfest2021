#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
class Pair{
    public:
    Node* head;
    Node* tail;
};
Pair reverseLL_2(Node* head){
    if(head==NULL || head->next==NULL){
        
        Pair an;
        an.head=head;
        an.tail=head; 
        return an;
    }
    Pair  ans=reverseLL_2(head->next);
    ans.tail->next=head;
    head->next=NULL;
    Pair an;
    an.head=ans.head;
    an.tail=head;
    return an;
   
}
Node* reverseLL_Better(Node*head){
    return reverseLL_2(head).head;
    }
Node* enterElement(Node* head){
    
    int data;
    cin>>data;
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        return head;
    }
    Node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
    

}
Node* insertNode(Node* head){
    cout<<"Enter the lenght of linked list you want to reverse"<<endl;
    int lenght;
    cin>>lenght;
    cout<<"Enter data"<<endl;
    for (int i = 0; i < lenght; i++)
    {
        head=enterElement(head);
    }
    return head;
    
}
void print(Node *head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head -> next;
    }
    cout<<endl;
}
Node* reverseList(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* ans=reverseList(head->next);
    Node* temp=ans;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return ans;
    
}
Node* reverseList_3(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* ans=reverseList(head->next);
    Node* tail=head->next;
    tail->next=head;
    head->next=NULL;
    return ans;
    
}
Node* reverseLL_4(Node* head){
    Node* cur=head;
    Node* pre=NULL;
    Node* next=cur;
    if(head==NULL || head->next==NULL){
        return head;
    }
    while (cur!=NULL)
    {
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;

    }
    head=pre;
    return head;
    
}
int main()
{
    Node* head=NULL;
    head=insertNode(head);
    cout<<"The entered linked list is "<<endl;
    print(head);
    back:
    int input;
    cout<<"Enter the method you want to use for reverse linkedlist"<<endl;
    cout<<"Enter 1 for using recursion with time complixity of n^2"<<endl;
    cout<<"Enter 2 for using recursion with time complixity of n and pair of return type using class"<<endl;
    cout<<"Enter 3 for using recursion with time complixity of n using tail concept"<<endl;
    cout<<"Enter 4 for using Iterative "<<endl;
    cin>>input;
    switch (input)
    {
    case 1:
        {

            head=reverseList(head);
            cout<<"The reverse linked list is "<<endl;
            print(head);
            goto back;
            break;
        }
    case 2:
        {

            head=reverseLL_Better(head);
            cout<<"The reverse linked list is "<<endl;
            print(head);
            goto back;
            break;
        }   
    case 3:
        {

            head=reverseList_3(head);
            cout<<"The reverse linked list is "<<endl;
            print(head);
            goto back;
            break;
        } 
    case 4:
        {

            head=reverseLL_4(head);
            cout<<"The reverse linked list is "<<endl;
            print(head);
            goto back;
            break;
        } 
    default:
        break;
    }
    
    
   
    
 
    
    
    
   
  
    return 0;
}