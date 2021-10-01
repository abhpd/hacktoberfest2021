/*
problem statement:-
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

test case fomrat:-
N    number of array elements
[..] array

test case:- 
Enter n: 12
Enter 12 elements: height: 0 1 0 2 1 0 1 3 2 1 2 1

Max water that can be trapped: 6

*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int nums[n];
    
    cout<<"Enter "<<n<<" elements: ";

    for(int i=0;i<n;i++)
        cin>>nums[i];

    stack<int> stk;
    int ans=0,i=0;
        
    while(i<n)
    {
        while(!stk.empty() && nums[i]>nums[stk.top()])
        {
            int p=stk.top();
            stk.pop();
                
            if(stk.empty()) break;
                
            ans+=(i-stk.top()-1)*(min(nums[i],nums[stk.top()])-nums[p]);
        }
            
        stk.push(i++);
    }

    
    cout<<"\nMax water that can be trapped: "<<ans<<"\n\n";
    return 0;
}

// time complexity:-  O(N)
// space complexity:- O(N)