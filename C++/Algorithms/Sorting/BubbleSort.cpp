#include<iostream>
using namespace std;


int main(){

   int n;
   cout<<"Enter size of Array : ";
   cin>>n;
   int arr[n];
   cout<<"Enter the array : ";
   for(int i=0;i<n;i++){
       cin>>arr[i];
   }
   //Bubble Sort Algorithm
   for(int i=0;i<n;i++){
       for(int j=0;j<n-i-1;j++){
           if(arr[j]>arr[j+1]){
               int temp = arr[j];
               arr[j]   = arr[j+1];
               arr[j+1]   = temp;
           }
       }
   }
   for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";
   }

   return 0;
}