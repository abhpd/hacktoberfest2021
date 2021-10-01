#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *lchild;
    Node *rchild;
}*root=NULL;

void CreationOfTree(int key)
{
 //Creation OF noDE     
    Node *temp=NULL;
    temp=new Node;
    temp->data=key;
    temp->lchild=temp->rchild=NULL;

    if(root==NULL)
    {
      root=temp;
      return;
    }
     
    Node *ptr=root, *tail=NULL; 
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

int Height(Node *ptr)
{
    int left,right;

    if(ptr==NULL)
    {
        return 0;
    }
    else
    {
       left=Height(ptr->lchild);
       right=Height(ptr->rchild);

       if(left<=right)
       {
           return right+1;
       }    
       else
       {
           return left+1;
       }
    }
}



Node *Search(int key)
{
    Node *temp=root;
    if(temp==NULL)
    {
        return NULL;
    }

    else
    {
        while(temp!=NULL)
        {
           if(temp->data>key)
           {
               temp=temp->lchild;
           }
           else if(temp->data<key)
           {
               temp=temp->rchild;
           }
           else
           {
               return temp;
           }
        }
    }
}

Node *InPred(Node *ptr)
{
    while(ptr!=NULL && ptr->rchild!=NULL)
    {
        ptr=ptr->rchild;
    }
    return ptr;
}

Node *InSucc(Node *ptr)
{
    while(ptr!=NULL && ptr->lchild!=NULL)
    {
        ptr=ptr->lchild;
    }
    return ptr;
}

Node *Delete(Node *ptr,int key)
{
   
   if(ptr==NULL)  //When Given Pointer is NULL
   {
       return NULL;
   }
   
   else if(ptr->lchild==NULL && ptr->rchild==NULL) //When we get to the leaf Node
   {
     if(ptr==root) // Assuring that Node is ROot or NOT
     {
        root=NULL;
     }
     delete(ptr);
     return NULL;
   }

   else if(key>ptr->data)
   {
     ptr->rchild=Delete(ptr->rchild,key);
   }

   else if(key<ptr->data)
   {
       ptr->lchild=Delete(ptr->lchild,key);
   }

   else
   {

//We are choosing the Height Which greater becoz might be the some can become 0 so we unable find the 
// suitable data for the root that subtree.

// Greatest Side is Left --> Left
// Greatest Side is Right --> Right

       if(Height(ptr->lchild) > Height(ptr->rchild))  
       {
           Node *var=InPred(ptr->lchild);
           ptr->data=var->data;
           ptr->lchild=Delete(ptr->lchild,var->data);
       }
       else
       {
           Node *var=InSucc(ptr->rchild);
           ptr->data=var->data;
           ptr->rchild=Delete(ptr->rchild,var->data);
       }

       return ptr;
   }

}

void Inorder(Node *ptr)
{
    if(ptr==NULL)
    {
        return;
    }
    else
    {
        Inorder(ptr->lchild);
        cout<<ptr->data<<" ";
        Inorder(ptr->rchild);
    }
    return;
}

int main()
{
   int A[]={30,20,10,15,25,40,50,45};
   for(int i=0; i < sizeof(A)/sizeof(A[0]); i++)
   {
       CreationOfTree(A[i]);
   }
   cout<< " Height " << Height(root)<<endl;
   Node *ptr=Search(50);
   cout << "Search =>  Address->" << ptr << "  Value->" <<ptr->data<<endl;
   cout<< "Inorder => ";
   Inorder(root);
   cout<<endl;
   
   cout<< "Deletion of 50 => " << Delete(root,50) << endl;
   cout<<"Inorder => ";
   Inorder(root);
   cout<<endl;


   cout<<" Printing the 40 Kaa InPred :-> ";
   Node *adOf40=Search(40);
   Node *temp=InSucc(adOf40);
   cout<< " InPred of 40 => "<< temp->data <<endl;
} 
