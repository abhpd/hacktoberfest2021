#include <iostream>
using namespace std;

int binarySearchHelper(int input[],int l,int h,int element){
    if(h<l)
        return -1;
    int m=(l+h)/2;
    if(input[m]==element)
        return m;
    else if(input[m]>element)
        return binarySearchHelper(input,l,m-1,element);
    else if(input[m]<element)
        return binarySearchHelper(input,m+1,h,element);
    else
        return -1;
}
int binarySearch(int input[], int size, int element) {
	if(size==0)
        return -1;
    int l=0;
    int h=size-1;
    return binarySearchHelper(input,l,h,element);
}
int main() {
    int input[100000],length,element, ans;
    cout<<"Enter the length"<<endl;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }
    cout<<"Enter the element"<<endl;
    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}