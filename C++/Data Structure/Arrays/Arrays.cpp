#include<iostream>
using namespace std;

int main(){

    int n;
    cout<<"Enter the size of the array "<<endl;
    cin>>n;

    int array[n];

    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    for(int i=0;i<n;i++){
        cout<<array[i]<<" "<<endl;
    }
}