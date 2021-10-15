#include<iostream>
#include<math.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
void radix_counting_sort(int arr[],int n,int d)
{
    int b[n];
  
    for(int pass=1;pass<=d;pass++)
    {
        int cnt[10]={0};
        // cout<<"Pass"<<pass<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            int y=pow(10,pass);
            int z=pow(10,pass-1);
            int x=(arr[i]%y)/z;
            cnt[x]++;
        }
        // for(int i=0;i<mx;i++)
        //     cout<<cnt[i]<<" ";
        // cout<<endl;
        for(int i=1;i<10;i++)
            cnt[i]=cnt[i]+cnt[i-1];
        //  for(int i=0;i<mx;i++)
        //     cout<<cnt[i]<<" ";
        // cout<<endl;
        for(int i=n-1;i>=0;i--)
        {
            int y=pow(10,pass);
            int z=pow(10,pass-1);
            cnt[(arr[i]%y)/z]=cnt[(arr[i]%y)/z]-1;
            b[cnt[(arr[i]%y)/z]]=arr[i];
        }
        for(int i=0;i<n;i++)
            arr[i]=b[i];
    }
    cout<<endl<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
        cout<<endl<<endl;

}
void radix_bucket_sort(int arr[100],int n,int d)
{

    for(int pass=1;pass<=d;pass++)
    {node* bucket[10]={NULL};
        for(int i=0;i<n;i++)
        {
            //cout<<arr[i]<<" ";
            node* new_node = new node();
            new_node->data=arr[i];
            new_node->next=NULL;
            int y=pow(10,pass);
            int z=pow(10,pass-1);
            int x=(arr[i]%y)/z;
            //cout<<x<<" ";
            if(bucket[x]==NULL)
                bucket[x]=new_node;
            else
                {node* head = bucket[x];
                 while(head->next!=NULL)
                 {
                     head=head->next;
                 }
                 head->next=new_node;
                 }
        }

        int ct=0;
        for(int i=0;i<n;i++)
        {
            while(bucket[i]!=NULL)
            {
                arr[ct]=bucket[i]->data;
                ct++;
                bucket[i]=bucket[i]->next;
            }

        }
        cout<<"Pass"<<pass<<": ";
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
    cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    radix_counting_sort(arr,n,3);
    return 0;
}
