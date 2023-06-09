//Find Intersection Point of Two Linked-Lists
#include <bits/stdc++.h>


struct Node{
  int data;
  Node* next;
};

Node* newNode(int key)
{
  Node* temp=new Node;
  temp->data=key;
  temp->next=NULL;
  return temp;
}

int point(Node* head1,Node* head2)
{
  Node* ptr1=head1;
  Node* ptr2=head2;
  int c1=0,c2=0;
  while(ptr1!=NULL)
  {
    c1++;
    ptr1=ptr1->next;
  }
  while(ptr2!=NULL)
  {
    c2++;
    ptr2=ptr2->next;
  }
  //length finfing done
  int diff=abs(c1-c2);
  ptr1=head1;
  ptr2=head2;
  //same level to save time
  if(c1>c2)
  {
      for(int i=0;i<diff;i++)
      {
          ptr1=ptr1->next;
      }
  }
  else if(c2>c1)
  {
     for(int i=0;i<diff;i++)
      {
          ptr2=ptr2->next;
      }
  }
  while(ptr1!=ptr2)
  {
    ptr1=ptr1->next;
    ptr2=ptr2->next;

  }
  if(ptr1!=NULL)
    return ptr1->data;
  else
    return -1;
}

void printList(Node* head)
{
  while(head!=NULL)
  {
    std::cout<<head->data<<"->";
    head=head->next;
  }
  std::cout<<std::endl;
}







int main() {

 Node* newNode;
  
    // Addition of new nodes
    Node* head1 = new Node();
    head1->data = 1;
  
    Node* head2 = new Node();
    head2->data = 2;
  
    newNode = new Node();
    newNode->data = 3;
    head2->next = newNode;
  
    newNode = new Node();
    newNode->data = 4;
    head2->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 2;
    head1->next = newNode;
    head2->next->next->next = newNode;
  
    newNode = new Node();
    newNode->data = 3;
    head1->next->next = newNode;
  
    head1->next->next->next = NULL;
    int d = point(head1,head2);
    std::cout<<"INTERSECTION POINT  =  "<<d;
    
}