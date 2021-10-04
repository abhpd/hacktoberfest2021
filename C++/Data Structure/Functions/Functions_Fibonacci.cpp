#include<iostream>
using namespace std;

void fib(int n){

    int t1=0;
    int t2=0;
    int nextTerm;

    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        t1=t2;
        t2=nextTerm;
    }

    return;
}

int main(){

    int n;
    cin>>n;

    fib(n);

    return 0;
}