#include<iostream>
using namespace std;

treeNode *SearchingLoop(treeNode *ptr,int key)
{
    while(ptr!=NULL)
    {
       
        if(ptr->data==key)
        {
            return ptr;
        }
        else if(ptr->data > key)
        {
            ptr=ptr->lchild;
        }
        else
        {
            ptr=ptr->rchild;
        }
    }
    return ptr;
}

int main()
{

}
