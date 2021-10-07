//solution to Tower of Hanoi problem
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void tower_of_hanoi(int x,char s,char a,char d)
{
    if(x>0)
    {
        tower_of_hanoi(x-1,s,d,a);
        cout<<"Move a disc from "<<s<<" to "<<d<<"\n";
        tower_of_hanoi(x-1,a,s,d);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;//number of discs
    tower_of_hanoi(n,'A','B','C');
    return 0;
}
