#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &v, int term)
{
    int l=0,r=v.size()-1,mid;    
    while(l<=r)
    {
        mid=(l+r)/2;
        if(v[mid]==term)
            return mid;
        else if(v[mid]>term)
                r=mid-1;
             else
                l=mid+1;
    }
    return -1;
}
int main(void)      //Execution of every program start from main() function.
{
    int n;      //variable declaration.
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Enter the term to search for: ";
    int term;
    cin>>term;
    sort(v.begin(),v.end());
    int found=binarySearch(v,term);
    if(found==-1)
        cout<<"Element not present";
    else
        cout<<"Element present";
    
    return 0;   //It will return 0 to the main() function.
}  
