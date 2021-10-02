#include<iostream>
#include<cstdlib>
/*--------------PREORDER TRAVERSAL OF BINARY TREE---------------------*/
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
	  void preorder(BinT* root)
	  {
	  	if(root== NULL)
	  	return;
	  	cout<<root->data<<" ";
	  	preorder(root->l);
	  	preorder(root->r);
	  	
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
	nr->preorder(nr);
	return 0;	
}
