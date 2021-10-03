#include<iostream>
using namespace std;

// retuns (num^pow)%mod in log(pow) time
long binExpo(long num,long pow,long mod) {
    long result = 1;
    while(pow > 0) {
        if((pow%2) == 1) {
            result = (result*num)%mod;
        }
        num = (num*num)%mod;
        pow = pow/2;
    }
    return result;
}

int main() {
    long num,power,mod;
    cin>>num>>power>>mod;
    cout<<binExpo(num,power,mod)<<endl;
}