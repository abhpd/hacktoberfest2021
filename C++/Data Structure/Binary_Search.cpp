#include <iostream>
using namespace std;
int lin(int arr[],int low,int n,int key){
    
    int high=n-1;
    int num;  
    while(low<=high)
    {
    num=(low+high)/2;
        if(key==arr[num]){
        
         return num;}
       else if(key<arr[num]){
            high=num-1;
        }
        //  if(key>num){
        else{
            low=num+1;
        }
    }
    return -1;
}
int main()
{
    int key,n,i;
    int low,high;
    cout<<"enter range ";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cout<<"eneter the "<<i+1<<" number";
        cin>>arr[i];
    }
    //int num
    cout<<"enter the key ";
    cin>>key;
    int data=lin(arr,0,n,key);
    if(data==-1)
    cout<<"the number you entered is out of scope";
    else
    cout<<"the number is placed at "<<data+1 <<"position";
  //cout<<"here the num you wants "<<data;
 return 0;
}
