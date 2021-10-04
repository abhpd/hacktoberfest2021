#include<iostream>
using namespace std;

void age(int n){
    if (n>18)
    {
        cout<<"You are eligible to vote "<<endl;
    }
    else
    {
        cout<<"You are not eligible to vote "<<endl;
    }
    
}

int main(){

    int n;
    cout<<"Enter the age "<<endl;
    cin>>n;

    age(n);

    return 0;
}