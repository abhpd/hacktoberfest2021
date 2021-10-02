#include<iostream>
using namespace std;

struct node
{
    int roll;
    char name[20];
    struct node *left;
    struct node *right;
};

struct node *start;
void create_list()
{
    int n;
    struct node *ptr,*temp;
    cout<<"How many elements to enter?"<<endl;
    cin>>n;
    cout<<"Enter student roll_no and name"<<endl;
    cin>>ptr->roll>>ptr->name;
    start=ptr;
    ptr->left=NULL;
    ptr->right=NULL;
    while(n>1)
    {
        temp=new node;
        cin>>temp->roll>>temp->name;
        ptr->right=temp;
        temp->left=ptr;
        temp->right=NULL;
        ptr=temp;
        n=n-1;
    }
}

void display()
{
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        cout<<"    "<<p->roll<<"    "<<p->name;
        p=p->right;
    }
}

void rev_display()
{
    struct node *p;
    p=start;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    while(p!=NULL)
    {
        cout<<"    "<<p->roll<<"    "<<p->name;
        p=p->left;
    }
}

int main()
{
    create_list();
    cout<<"Elements in the linked list"<<endl;
    display();
    cout<<endl;
    cout<<"now elements in the reverse order in doubly linked list"<<endl;
    rev_display();
    return 0;
}
