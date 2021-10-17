#include<bits/stdc++.h>
using namespace std;

bool ispalind(string ss,int l, int r)
{
    int flag = 1;

    while(l<=r && flag)
    {
        if(ss[l++] != ss[r--])
        flag = 0;
    }

    if(flag)
    return true;
    else
    return false;
}

int pp(string s , int l , int r)
{

if(ispalind(s,l,r)==true)
return 0;

int temp = INT_MAX;

for(int k = l ; k<r ; k++)
{
temp = min(temp , 1 + pp(s,l,k) + pp(s,k+1,r) );
}

return temp;

}

int main()
{

string s = "nitinknitink";

cout<<pp(s,0,s.size()-1);



    return 0;
}