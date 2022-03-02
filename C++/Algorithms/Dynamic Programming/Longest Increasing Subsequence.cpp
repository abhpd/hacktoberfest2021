#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> &arr, int n){
    
    int lis[n];
 
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }
 
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,lis[i]);
    }
    return ans;
}
 
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<LIS(v,n)<<endl;
    
    return 0;
}

/*
A more exiting and easy and faster code taken from CODEFORCES blog: 

int LIS(vector<int> &arr,int n){
	multiset < int > s;
	
	for(int i=0,i<n;i++)
	{
	    s.insert(arr[i]);
	    
	    auto it = s.upper_bound(arr[i]);
	    
	    if(it != s.end())
	        s.erase(it);
	}
	
	return (int)s.size();
}

*/
