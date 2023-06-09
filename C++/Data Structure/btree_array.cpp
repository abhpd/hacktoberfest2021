/*binary tree*/
#include<iostream>
using namespace std;
    char tree[10];
    int root(char c)
    {
        if(tree[0]==NULL)
            tree[0]=c;
        else
            cout<<"Root already defined."<<endl;
        return 0;
    }

    int lc(char key,int parent)
    {
        if(tree[parent]==NULL)
        cout<<"Can't place key at this position!"<<endl;
        else
        tree[2*parent+1]=key;
        return 0;
    }
    int rc(char key,int parent)
    {
        if(tree[parent]==NULL)
        cout<<"Can't place key at this position!"<<endl;
        else
        tree[2*parent+2]=key;
        return 0;
    }
    void disp()
    {
        for(int i=0;i<10;i++)
            if(tree[i]!=NULL)
            cout<<tree[i];
        else
            cout<<"_";
    }
    int main()
    {
        root('A');
        root('B');
        rc('c',0);
        lc('d',1);
        rc('E',2);
        lc('F',3);
        disp();
    }
