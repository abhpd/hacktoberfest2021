/*
        The Little Elephant loves Ukraine very much. Most of all he loves town Rozdol (ukr. "Rozdil").

        However, Rozdil is dangerous to settle, so the Little Elephant wants to go to some other town. 
        The Little Elephant doesn't like to spend much time on travelling, so for his journey he will 
        choose a town that needs minimum time to travel to. If there are multiple such cities, then the 
        Little Elephant won't go anywhere.

        For each town except for Rozdil you know the time needed to travel to this town. Find the town the 
        Little Elephant will go to or print "Still Rozdil", if he stays in Rozdil.

     Input:
        The first line contains a single integer n (1 ≤ n ≤ 105) — the number of cities. The next line 
        contains n integers, separated by single spaces: the i-th integer represents the time needed to 
        go from town Rozdil to the i-th town. The time values are positive integers, not exceeding 109.

        You can consider the cities numbered from 1 to n, inclusive. Rozdil is not among the numbered cities.

     Output:
        Print the answer on a single line — the number of the town the Little Elephant will go to. If there are 
        multiple cities with minimum travel time, print "Still Rozdil" (without the quotes).
*/
#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<cmath>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<cstdlib>
using namespace std;

int main(){
    int n, a;
    cin >> n;
    vector <long> arr;
    vector <long> arr1;

    for(int i = 1; i<=n; i++){
        cin >> a;
        arr.push_back(a);
        arr1.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for(size_t i=0;i < arr.size(); i++){
       if(arr[0] == arr[1]){
           cout << "Still Rozdil";
           return 0;
       }
       else if(arr[0] == arr1[i]){
           cout << i+1;
       }
    }
}