#include<iostream>
#include<cstdlib>
/*--------------INORDER TRAVERSAL OF BINARY TREE---------------------*/
using namespace std;
class BinT
{ 
        
	public:
	int data;
		BinT *l;
		BinT *r;
	  BinT(int n)
	  {
	  	this->data=n;
	  	this->l=NULL;
	  	this->r=NULL;
	  }
	  void postorder(BinT* root)
	  {
	  	if(root==NULL)
	  	return;
	  	postorder(root->l);
	  	cout<<root->data<<" ";
	  	postorder(root->r);
	  	
	  }
		
};
int main()
{
    BinT *nr=(BinT*)(calloc(5,sizeof(BinT)));
	nr=new BinT(1);
	nr->l=new BinT(2);
	nr->r=new BinT(3);
	nr->l->l=new BinT(4);
	nr->l->r=new BinT(5);
	nr->postorder(nr);
	return 0;	
}
