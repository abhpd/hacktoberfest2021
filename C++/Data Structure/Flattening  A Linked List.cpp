#include <iostream>
#include <bits/stdc++.h>

struct Node{
  int data;
  Node* next;
  Node* bottom;
};


Node* merge(Node* a, Node* b)
{
  if(a==NULL) 
    return  b;
  if(b==NULL)
     return a;

  Node* result;
  if(a->data<b->data)
  {
    result=a;
    result->bottom=merge(a->bottom,b);
  }

  else{
    result=b;
    result->bottom=merge(a,b->bottom);
  }
  result->next=NULL;
  return  result;
}






Node *flatten(Node* root)
{
  if(root==NULL || root->next==NULL)
    return  root;
  return merge(root,flatten(root->next));
  
}

void printList(Node *head)
{
  while(head!=NULL)
  {
    std::cout<<head->data<<"->";
    head=head->next;
  }
  std::cout<<std::endl;
}


Node* newNode(int key)
{
  Node*temp;
  temp->data=key;
  temp->next=NULL;
  return  temp;
}




int main() {



}
