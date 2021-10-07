#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char A, char B,char C)
{
    if (n>1){
    towerOfHanoi(n - 1, A,C,B);
    cout << "Move disk " << n << " from rod " << A <<
                                " to rod " << C << endl;
    towerOfHanoi(n - 1,B,A,C);
    }
}

int main()
{
    int n;
    cout<<"Enter the value of disks\n";
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
