#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int> &v, int term)
{
    for(int i=0;i<v.size();i++)
        if(v[i]==term)
            return i;
    return -1;
}
int main()
{
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Enter the term to search for: ";
    int term;
    cin>>term;
    int found=linearSearch(v,term);
    if(found==-1)
        cout<<"Element not present";
    else
        cout<<"Element found at index: "<<found;
    return 0;
}