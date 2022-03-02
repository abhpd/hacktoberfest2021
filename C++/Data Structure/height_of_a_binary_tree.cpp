//Submission for Hacktober Fest 2021

/*
Question: Height of a Binary Tree
Submitted by:- nehamotwani80
Language Used:- C++
*/

#include<bits/stdc++.h>
using namespace std;
class node
{
	public:
		int data;
		node *left,*right;	
};
node* create()
{
	int x;
	cin>>x;
	node *p;
	p=new node;
	p->data=x;
	p->left=NULL;
//	p->right=NULL;
	if(x==-1)
	{
		return 0;
	}
	p->left=create();
	p->right=create();
	return p;
}
int height(node* head){
        if(head==NULL)
        return 0;
        else
        {
            int left=height(head->left);
            int right=height(head->right);
            return 1+max(left,right);
        }
    }
int main()
{
	node *head;
	head=0;
	head=create();
	int ans=height(head);
	cout<<ans<<endl;
}
