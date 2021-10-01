#include<iostream>
using namespace std;

class treeNode
{
    public:

    int data;
    treeNode *lchild;
    treeNode *rchild;
}*root=NULL;

void CreateTree(int key)
{
    treeNode *temp,*ptr=root,*tail=NULL;
    
    //Creation Of Node
    temp=new treeNode;
    temp->data=key;
    temp->lchild=temp->rchild=NULL;

    if(root==NULL)
    {
        root=temp;
        return;
    }

    while(ptr!=NULL)
    {
        tail=ptr;
        if(ptr->data>key)
        {
            ptr=ptr->lchild;
        }
        else if(ptr->data<key)
        {
            ptr=ptr->rchild;
        }
        else
        {
            return;
        }
    }

    if(tail->data>key)
    {
        tail->lchild=temp;
    }
    else
    {
        tail->rchild=temp;
    }
    
    return;
}

void Inorder(treeNode *temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
    {
        Inorder(temp->lchild);
        cout<<temp->data<<" ";
        Inorder(temp->rchild);
    }
}

int main()
{
   cout<<"Lets Create BST "<<endl;

   cout<<"Enter the Size of the Array to Insert data in BST : ";
   int n;
   cin>>n;

   int Arr[n]={0};

   cout<<"Give the Datas :";
   for(int i=0;i<n;i++)
   {
       cin>>Arr[i];
   }

   cout<<"Lets Insert the Datas to BST  from Array :"<<endl;

   for(int i=0;i<n;i++)
   {
      cout<<"Inserting to BST => "<<Arr[i];
      CreateTree(Arr[i]);
      cout<<endl;    
   }
   
   cout<< "Inorder of BST => ";
   Inorder(root);

}
