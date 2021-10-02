
//implementation of tree using Linkedlist and Queue
//give input as -1 from empty node

#include<iostream>
#include<queue>
using namespace std;

// class for creating node of tree
class node
{
    public:
    node *lchild;
    int data;
    node *rchild;

    node(int val)
    {
        lchild=rchild=NULL;
        data=val;
    }
};

node *root=NULL;
void create()
{
    node *temp;
    cout<<"give the value of root node :";
    int x;
    cin>>x;
    root=new node(x);
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        printf("give the value of left node of %d :",temp->data);
        cin>>x;
        if(x!=-1)
        {
            node *t=new node(x);
            temp->lchild=t;
            q.push(t);
        }
        printf("give the value of right node of %d :",temp->data);
        cin>>x;
        if(x!=-1)
        {
            temp=q.front();
            node *t=new node(x);
            temp->rchild=t;
            q.push(t);
        }
    }
   
}

void preorder(node *t)
{
    if(t)
    {
        cout<<t->data<<' ';
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void inorder(node *t)
{
    if(t)
    {
        inorder(t->lchild);
        cout<<t->data<<' ';
        inorder(t->rchild);
    }
}

void postorder(node *t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<' ';
    }
}
int count_leafnode(node *t)
{
    static int c=0;
    if(t==NULL)return 0;
    if(t)
    {
        if(t->lchild==NULL&&t->rchild==NULL)return 1;
    }
       
    return count_leafnode(t->rchild)+count_leafnode(t->lchild);;
    
   
}

int main()
{
    create();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
