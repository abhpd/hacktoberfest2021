#include<iostream>
using namespace std;
int RecursionSum(int n){
  if(n==0)
  return 0;
  else{
    return n+RecursionSum(n-1);
  }
}
int main(){
  int n;
  cout<<"Enter value of n to find sum of n numbers:"<<endl;
  cin>>n;
  cout<<"Sum of first n numbers is "<<RecursionSum(n)<<endl;
  return 0;
}
