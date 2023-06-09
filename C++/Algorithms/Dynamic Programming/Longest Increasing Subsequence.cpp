#include <bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int N = nums.size();
    if(N == 0) return 0;
    int ans = 1;
    vector<int> DP(N,1);
    for(int i=1; i<=N-1; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) {
                int count = 1 + DP[j];
                DP[i] = max(count,DP[i]);
                ans = max(ans,DP[i]);
            }
        }
    }
    return ans;
}
int main()
{
    // vector<int> vec = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    vector<int> vec;
    int n,a;
    cout<<"Enter the number of elements in the array:";
    cin>>n;
    cout<<"Enter elements in the array:";
    // int n = vec.size();
    for(int i=0;i<n;i++)
    {
        cin>>a;
        vec.push_back(a);
    }
    cout << "The length of the LIS is " << lengthOfLIS(vec);
 
    return 0;
}