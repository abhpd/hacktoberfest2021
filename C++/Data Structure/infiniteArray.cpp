#include <iostream>
using namespace std;

int binarySearch(int lst[],int target,int start,int end);
int ans(int arr[],int target);

int main(){
   
    int len; //size of array
    cin>>len;

    int arr[len];
    //enter the elements in array
    cout<<"Enter the elements->";
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    cout<<target<<" found at index->"<<ans(arr,target);
    return 0;

}

int ans(int arr[],int target){
    //first find the range
    //start with the box of size 2

    int start=0;
    int end=1;

    //condition to check in range;
    while(target>arr[end]){
        int newStart=end+1;
        //double the box value
        //end=previous end + sizeofbox *2 ; sizeofbox=end-start+1
        
         end=end + (end - start + 1)*2;
         start=newStart;
          
    }
    return binarySearch(arr,target,start,end);
}

int binarySearch(int lst[],int target,int start,int end  ){
    
    while(start<=end){

        int mid=start+(end-start)/2; //might be (low+high) exceeds the int range
        
        // if(target==lst[mid]){
        //     return mid;
        // }
        if(target<lst[mid]){
            end=mid-1;
        }
        else if(target>lst[mid]){
            start=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
