/*
problem statement:-
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. print the max sliding window.
test case fomrat:-
N  k  number of array elements window size
[..] array
test case:- 
Enter n & k: 8 3
Enter 8 elements: 1 3 -1 -3 5 3 6 7
Output elements of max sliding window are: 3 3 5 5 6 7 
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cout<<"Enter n & k: ";
    cin>>n>>k;
    int nums[n];
    
    cout<<"Enter "<<n<<" elements: ";

    for(int i=0;i<n;i++)
        cin>>nums[i];

    //store the indices of elements in deque.
    deque<int> dq;
    vector<int> ans;


    //usuing deque to to keep track of window    
    for(int i=0;i<n;i++)
    {
        //if window size is greater than equal to k remove the front.
        while(!dq.empty() && i-dq.front()>=k)
            dq.pop_front();
        
        //update the maximum element in the monotonous queue.
        while(!dq.empty() && nums[dq.back()]<nums[i])
            dq.pop_back();
        
        dq.push_back(i);
            
        //for each window of size k record the maximum.
        if(i>=k-1)
            ans.push_back(nums[dq.front()]);
    }

    cout<<"\nOutput elements of max sliding window are: ";
        
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    
    return 0;
}

// time complexity:-  O(N)
// space complexity:- O(N)
