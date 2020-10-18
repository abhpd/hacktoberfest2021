/*You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

Example 1 : Consider the following 3 activities sorted by
by finish time.
     start[]  =  {10, 12, 20};
     finish[] =  {20, 25, 30};
A person can perform at most two activities. The 
maximum set of activities that can be executed 
is {0, 2} [ These are indexes in start[] and 
finish[] ]

Example 2 : Consider the following 6 activities 
sorted by by finish time.
     start[]  =  {1, 3, 0, 5, 8, 5};
     finish[] =  {2, 4, 6, 7, 9, 9};
A person can perform at most four activities. The 
maximum set of activities that can be executed 
is {0, 1, 3, 4} [ These are indexes in start[] and 
finish[] ]

1) Sort the activities according to their finishing time
2) Select the first activity from the sorted array and print it.
3) Do following for remaining activities in the sorted array.
…….a) If the start time of this activity is greater than or equal to the finish time of previously selected activity then select this activity and print it.
*/

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;


bool comp(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2)
{
    return p1.second.second < p2.second.second;
}

void activitySelection(vector<pair<int,pair<int,int>>> v,int n)
{
    // sort the activities on the basis of their finish time (ascending order)
    sort(v.begin(),v.end(),comp);
    
    // first activity will always be selected
    cout<<v[0].first<<" ";
    
    int j=0;
    
    for(int i=1 ; i<n ; i++)
    {
        // if the finish time of previous activity is <= start time of next activity, then that activity is selected
        if(v[j].second.second <= v[i].second.first)
        {
            cout<<v[i].first<<" ";
            j = i;
        }
    }
    
}

int main()
{
    // t = number of test cases
    int t;
    cin>>t;
    
    while(t--)
    {
        // n = number of activities
        int n;
        cin>>n;
        
        // container v that will store the index, start time and the finish time of each activity in same order as written
        vector<pair<int,pair<int,int>>> v(n);
        
        // input start time of all activities
        for(int i=0 ; i<n ; i++)
        {
            v[i].first = i+1;
            cin>>v[i].second.first;
        }
        
        // input finish time of all activities
        for(int i=0 ; i<n ; i++)
        {
            cin>>v[i].second.second;
        }
        
        activitySelection(v,n);
        cout<<endl;
    }
    return 0;
}
