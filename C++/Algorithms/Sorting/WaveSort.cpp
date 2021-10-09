//C++ IMPLEMENTATION FOR WAVE SORT
#include<iostream>
using namespace std;

int main(){
    //number of elements
    int n;
    cin>>n;
    int a[100];
    //enter the elements 
    for(int i=0 ; i < n ; i++){
        cin>>a[i];
    }
    //sorting the array in wave form 
    for(int i=0 ; i < n ; i+=2){
        //prev element
        if(i!=0 and a[i] < a[i-1]){
            swap(a[i],a[i-1]);
        }
        //next element
        if(i !=(n-1) and a[i]<a[i+1]){
            swap(a[i],a[i+1]);
        }
    }
    cout<<"the sorted elements are : ";
    for(int i=0 ; i < n ; i++){
       cout<<a[i]<<" ";
    }
}

//OUTPUT
/*
6
1 3 4 2 7 8
the sorted elements are : 3 1 4 2 8 7
*/