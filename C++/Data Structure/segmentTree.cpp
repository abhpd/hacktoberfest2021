#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//Max size of array elements
ll MAXN=100001;
ll n,t[400004],a[100001];
void build(int v,ll tl,ll tr){
    if(tl==tr)t[v]=a[tl];
    else{
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v]=t[2*v]+t[2*v+1];
    }
}
ll sum(int v,ll tl,ll tr,ll l,ll r){
    if(l>r)return 0;
    if(l==tl && r==tr)return t[v];
    ll tm=(tl+tr)/2;
    return sum(2*v,tl,tm,l,min(r,tm))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}
void update(int v,int tl,int tr,int pos,ll val){
    if(tl==tr)t[v]=val;
    else{
        int tm=(tl+tr)/2;
        if(pos<=tm)update(2*v,tl,tm,pos,val);
        else update(2*v+1,tm+1,tr,pos,val);
        t[v]=t[2*v]+t[2*v+1];
    }
}
int main(){
    int n=7;
    for(int i=0;i<n;i++)a[i]=i+1;
    // Call the build function
    build(1,0,n-1);
    // Calling the sum function
    cout<<sum(1,0,n-1,2,4)<<endl;
    update(1,0,n-1,3,7);
    cout<<sum(1,0,n-1,2,4)<<endl;
    return 0;
}


