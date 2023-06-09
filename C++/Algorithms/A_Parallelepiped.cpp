/*
        You've got a rectangular parallelepiped with integer edge lengths. You know the areas of its three faces 
        that have a common vertex. Your task is to find the sum of lengths of all 12 edges of this parallelepiped.

     Input:
        The first and the single line contains three space-separated integers — the areas of the parallelepiped's faces.
        The area's values are positive ( > 0) and do not exceed 104. It is guaranteed that there exists at least 
        one parallelepiped that satisfies the problem statement.

     Output:
        Print a single number — the sum of all edges of the parallelepiped.
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
    double s1, s2, s3;
    cin >> s1>>s2>>s3;
    double a = sqrt(s1 * s2 / s3);
    double b = sqrt(s3 * s1 / s2);
    double c = sqrt(s3 * s2 / s1);
    
    double sum = a+b+c;
    cout<<sum * 4;
    return 0;
}