#include <bits/stdc++.h>
using namespace std;
int c=0;
class node
{
public:
    int data;
    node *lchild;
    node *rchild;
    node(int key)
    {
        data = key;
        lchild = rchild = NULL;
    }
};
class tree
{
public:
    node *root=NULL;

    void insert(int key);
    void inorder(node *p);
    int count(node *p);
};

void tree::insert(int key)
{node *t=NULL,*p=NULL; int root1;

    if(root==NULL)
    {
        cout<<"please create root first\n";
        cout<<"Enter the root\n";
       
        cin>>root1;
        root=new node(root1);
        root->lchild=root->rchild=NULL;

    }

    t=root;
    
        while(t)
        {p=t;
        if(t->data==key) {cout<<"repeated value\n";return ;}
        else if(t->data<key)
        {
            t=t->rchild;

        }
        else{
            t=t->lchild;
        }


        }
          node *k=new node(key);
        if(p->data<key)
        {
            p->rchild=k;

        }
        else{
            p->rchild=k;
        }

    
    return ;
}

int tree::count(node *p)
{if(p==NULL) return 0;
  return count(p->lchild)+count(p->rchild)+1;
}



void tree::inorder(node *p)
{
    if(p==NULL) return ;
    cout<<p->data<<" ";
    


    inorder(p->lchild);
    inorder(p->rchild);
}
int main()
{
    tree my_tree;

   my_tree.root=new node(10);
    my_tree.insert(20);
    my_tree.insert(30);
    my_tree.insert(50);
    my_tree.insert(70);
    
    my_tree.inorder(my_tree.root);
    cout<<endl;
    cout<<(my_tree.count(my_tree.root))-1<<endl;
    
    }