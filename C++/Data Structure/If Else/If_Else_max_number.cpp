#include<iostream>
using namespace std;

void max(int n1, int n2,int n3){
    if (n1>n2 && n1>n3)
    {
        cout<<"The max number is "<<n1<<endl;
    }
    else if (n2>n3 && n2>n1)
    {
        cout<<"The max number is "<<n2<<endl;
    }
    else{
        cout<<"The max number is "<<n3<<endl;
    }

    
}


void min(int n1, int n2,int n3){
    if (n1<n2 && n1<n3)
    {
        cout<<"The min number is "<<n1<<endl;
    }
    else if (n2<n3 && n2<n1)
    {
        cout<<"The min number is "<<n2<<endl;
    }
    else{
        cout<<"The min number is "<<n3<<endl;
    }

    
}


int main(){

    int n1,n2,n3;
    cout<<"Enter the values "<<endl;
    cin>>n1>>n2>>n3;

    max(n1,n2,n3);
    min(n1,n2,n3);

}
