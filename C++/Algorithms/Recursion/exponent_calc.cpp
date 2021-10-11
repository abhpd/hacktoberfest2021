#include<bits/stdc++.h>
using namespace std;

long long exponent_calc(long long a, long long b){
    if(b==0){
        return (long long)(1);
    }
    if(b==1){
        return a;
    }
    long long val = exponent_calc(a, b/2);
    if(b%2){
        return a*val*val;
    }
    return val*val;
}

int main(){
    long long a, b; //To calculate a^b; b>=0
    cout<<"Enter a: ";
    cin>>a;
    cout<<"Enter b: ";
    cin>>b;
    cout<<a<<" to the power "<<b<<" is: "<<exponent_calc(a, b)<<endl;
}
