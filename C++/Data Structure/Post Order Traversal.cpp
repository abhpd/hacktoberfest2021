#include<iostream>
#include<cstdlib>
/*--------------POSTORDER TRAVERSAL OF BINARY TREE---------------------*/
using namespace std;
class BinT
{ 
        
	public:
	int data;
		BinT *l;//Left subtree
		BinT *r;//Right subtree
	  BinT(int n)
	  {
	  	this->data=n;
	  	this->l=NULL;
	  	this->r=NULL;
	  }
	  void postorder(BinT* root)//Sending the root address for traversal
	  {
	  	if(root==NULL)
	  	return;
	  	postorder(root->l);
	  	postorder(root->r);
	  	cout<<root->data<<" ";
	  }
		
};
int main()
{
	//The value 5 can be generalised
    BinT *nr=(BinT*)(calloc(5,sizeof(BinT)));
	nr=new BinT(1);
	nr->l=new BinT(2);
	nr->r=new BinT(3);
	nr->l->l=new BinT(4);
	nr->l->r=new BinT(5);
	nr->postorder(nr);
	return 0;	
}
