#include <iostream>
using namespace std;
int mergeNinversions(int a[],int s,int e){
    int temp[e+1];
    int mid=(s+e)/2;
    int cnt=0;
    int i=s,j=mid+1,k=s;
    while(i<=mid && j<=e){
        if(a[i]>=a[j]){
                cnt+=(mid-i)+1;
            temp[k++]=a[j++];
        }else{
            temp[k++]=a[i++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=e){
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++){
        a[i]=temp[i];
    }
    return cnt;

}
int merge_sort(int a[],int s,int e){
    //base case
    if(s>=e){
        return 0;
    }
    //rec case
    int mid=(s+e)/2;
    int x=merge_sort(a,s,mid);
    int y=merge_sort(a,mid+1,e);
    int z= mergeNinversions(a,s,e);
    return x+y+z;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<merge_sort(a,0,n-1)<<endl;
     for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}

