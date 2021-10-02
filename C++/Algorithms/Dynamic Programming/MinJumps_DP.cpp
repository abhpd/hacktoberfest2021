#include <bits/stdc++.h> 
using namespace std; 
  
int minJumps(vector<int>&a, int n) 
{ 
    // jumps[n-1] will hold the result 
    vector<int>jumps(n);
	int i, j; 
  	
    if (n == 0 || a[0] == 0) 
        return INT_MAX; 
  
    jumps[0] = 0; 
  
    // Find the minimum number of jumps to reach arr[i] 
    // from arr[0], and assign this value to jumps[i] 
    for (i = 1; i < n; i++) { 
        jumps[i] = INT_MAX; 
        for (j = 0; j < i; j++) { 
            if (i <= j + a[j] && jumps[j] != INT_MAX) { 
                jumps[i] = min(jumps[i], jumps[j] + 1); 
                break; 
            } 
        } 
    } 
    return jumps[n - 1]; 
} 
int main() 
{ 
	int n;
	cout<<"Enter the no of elements"<<'\n';
	cin>>n;
	cout<<"Enter the array of max steps for each element\n";
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
    
    cout << "Min no of jumps to reach the end is " << minJumps(a, n); 
    return 0; 
} 
