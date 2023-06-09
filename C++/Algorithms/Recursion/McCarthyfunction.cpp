#include <bits/stdc++.h>
using namespace std;
//McCarthy 91 function
int M(int n)
{
    if(n>100)
    return n-10;
    else if (n<=100)
    return M(M(n+11));
}
int main() {
    int n;
    cin>>n;
    cout<< M(n);
	return 0;
}