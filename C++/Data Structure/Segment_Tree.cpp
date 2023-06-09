/*
Segment tree comes very handy in solving problems,
which requires updation and query solving.

Segement_tree questions can be expected in interview/coding rounds of tough software companies

Here is the simple implementation of the same
*/



#include<bits/stdc++.h>
using namespace std;

//creation
int create(int s[],int i,int a[],int l,int r)
{
    if(l==r)
    {
        s[i]=a[l];
        return s[i];
    }
    else{
        int mid=(l+r)/2;
        s[i]=create(s,2*i+1,a,l,mid)+create(s,2*i+2,a,mid+1,r);
        return s[i];
    }
}

//to calculate sum from [l..r]
int sum(int s[],int i,int ql,int qr,int l,int r)
{
    if(l>=ql && qr>=r)
    {
        return s[i];
    }
    else if(r<ql || l>qr)
    {
        return 0;
    }
    else
    {
        int mid=(l+r)/2;
        return sum(s,2*i+1,ql,qr,l,mid)+sum(s,2*i+2,ql,qr,mid+1,r);
    }
}

//updation
void update(int s[],int pos,int diff,int i,int l,int r)
{
    if(pos>=l && pos<=r)
    {
        s[i]=s[i]+diff;
        if(l!=r)
        {
            int mid=(l+r)/2;
            update(s,pos,diff,2*i+1,l,mid);
            update(s,pos,diff,2*i+2,mid+1,r);
        }
    }
    return ;
}

//printing the created tree
void print(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    //input size and array
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // to calculate size of segment tree
    int x=int(ceil(log2(n)));
    int size=2*(int)pow(2, x) - 1;
    
    //initializing segment tree
    int S[size]={0};

    // creation and printing
    create(S,0,arr,0,n-1);
    print(S,size);

    // solving a sum query 
    cout<<sum(S,0,2,4,0,n-1)<<endl;

    // trying a updation query
    int pos,k;
    cin>>pos>>k;

    int diff=k-arr[pos];
    arr[pos]=k;
    update(S,pos,diff,0,0,n-1);

    print(S,size);
    
   
}
