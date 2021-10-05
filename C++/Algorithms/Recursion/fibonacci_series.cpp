#include <bits/stdc++.h>
using namespace std;


void fibo(int n){
    static int n1=0,n2=1,sum;
    if (n>1){
    sum=n1+n2;
    n1=n2;
    n2=sum;
    cout<<sum<<" ";
    fibo(n-1);
    }
}

int main(){
    
    int n;
    cin>>n;
    cout<<0<<" "<<1<<" ";
    fibo(n-1);
    return 0;
}
