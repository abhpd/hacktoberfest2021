


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

int main ()
{
    int n;
    int a [1005];
    int num5, num0, flag;
    while (cin >> n)
    {
        num5 = 0;
        num0 = 0;
        for (int i = 0; i <n; i ++)
        {
            cin >> a [i];
            if (a [i] == 5)
                num5 ++;
            else if (a [i] == 0)
                num0 ++;
        }
        flag = num5/9;//5 the number must be a multiple of 9
        if (! num0)//It must contain 0, because it is 0
            cout << "-1" << endl;
        else
        {
            if (flag)
            {
                for (int i = 0; i <flag * 9; i ++)
                    cout << "5";
                for (int i = 0; i <num0; i ++)
                    cout << "0";
            }
            else
                cout << "0";//The last digit must be 0
            cout << endl;
        }
    }
    return 0;
}