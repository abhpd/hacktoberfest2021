#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    int height;
    Node *lchild;
    Node *rchild;
}*root=NULL;

int NodeHeight(Node *ptr)
{
    int lh,rh;
    lh = ptr && ptr->lchild ?  ptr->lchild->height : 0;
    rh = ptr && ptr->rchild ? ptr->rchild->height :0;

    return lh>rh?lh+1:rh+1; 
}

int BalanceFactor(Node *ptr)
{
    int lh,rh;
    lh = ptr && ptr->lchild ?  ptr->lchild->height : 0;
    rh = ptr && ptr->rchild ? ptr->rchild->height :0;

    return lh-rh;    
}

Node *LLRotation(Node *p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;
    //cout<<p->data<<" "<<pl->data<<" "<<plr->data<<endl;
     if(plr==NULL)
     {
         cout<<"NULL"<<endl;
     }

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(p==root)
    {
        root=pl;
    }

    return pl;
}

Node *RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild=p;
    p->rchild=prl;

    pr->height=NodeHeight(pr);
    p->height=NodeHeight(p);

    if(p==root)
    {
        root=pr;
    }
    
    return pr;
}

Node *LRRotation(Node *p)
{
    Node *pl=p->lchild;
    Node *plr=pl->rchild;

    Node *plrR=plr->rchild;
    Node *plrL=plr->lchild;

    plr->lchild=pl;
    plr->rchild=p;

    p->lchild=plrR;
    pl->rchild=plrL;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(p==root)
    {
        root=plr;
    }

    return plr;
}

Node *RLRotation(Node *p)
{
  Node *pr=p->rchild;
  Node *prl=pr->lchild;
  
  Node *prlR=prl->rchild;
  Node *prlL=prl->lchild;

  prl->lchild=p;
  prl->rchild=pr;
  
  pr->lchild=prlR;
  p->rchild=prlL;

  pr->height=NodeHeight(pr);
  p->height=NodeHeight(p);
  prl->height=NodeHeight(prl);

  if(p==root)
  {
      root=prl;
  }

  return prl;
}

Node *recInsert(Node *ptr,int key)
{
    Node *temp=NULL;

    if(ptr==NULL)
    {
        temp= new Node;
        temp->data=key;
        temp->height=1;
        temp->lchild=temp->rchild=NULL;
        return temp;
    }

    else if(key<ptr->data)
    {
        ptr->lchild=recInsert(ptr->lchild,key);
    }
    else if(key>ptr->data)
    {
        ptr->rchild=recInsert(ptr->rchild,key);
    }
    
    ptr->height=NodeHeight(ptr);

    if(BalanceFactor(ptr)==2 && BalanceFactor(ptr->lchild)==1)
    {
        cout<<"LLRoatation "<<key<<endl;
        return LLRotation(ptr);
    }
    else if(BalanceFactor(ptr)==2 && BalanceFactor(ptr->lchild)==-1)
    {
        cout<<"LRRoatation "<<key<<endl;
        return LRRotation(ptr);
    }
    else if(BalanceFactor(ptr)==-2 && BalanceFactor(ptr->rchild)==1)
    {
        cout<<"RLRoatation "<<key<<endl;
        return RLRotation(ptr);
    }
    else if(BalanceFactor(ptr)== -2 && BalanceFactor(ptr->rchild)==-1)
    {
        cout<<"RRRotation "<<key<<endl;
        return RRRotation(ptr);
    }

    return ptr;
}

void InOrder(Node *ptr)
{
    if(ptr!=NULL)
    {
        InOrder(ptr->lchild);
        cout<<ptr->data<<"   ";
        InOrder(ptr->rchild);
    }
    return;
}

int main()
{
   root=recInsert(root,10);
   recInsert(root,20);
   recInsert(root,30);
   recInsert(root,25);
   recInsert(root,28);
   recInsert(root,27);
   recInsert(root,5); //Error

   InOrder(root);

}
