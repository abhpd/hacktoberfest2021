
//Print all prime numbers from 1 to n
#include<bits/stdc++.h>
using namespace std;

void sieveoferatosthenes(int n){
    bool arrayprime[n+1];
    memset(arrayprime, true, sizeof(arrayprime));

    for(int i=2;i<=sqrt(n);i++){
        if(arrayprime[i]==true){
            for(int j=i*i;j<=n;j+=i)
            arrayprime[j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(arrayprime[i]==true)
        cout<<i<<" ";
    }
}

int main(){
    int n;
    cout<<"Enter the value of 'n' to get all prime no smaller than n: ";
    cin>>n;
    cout<<"Prime numbers in the range of 1 to "<<n<<" are: ";
    sieveoferatosthenes(n);
    return 0;
}