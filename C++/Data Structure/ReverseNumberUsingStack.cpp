#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void ReverseNum(int num)
{
    stack<int> st;
    stack<int> st2;
    int result;
    while(num !=0)
    {
        result=num%10;
        num=num/10;
        st.push(result);

    }
    while(!st.size()==0)
    {
        st2.push(st.top());
        st.pop();
    }

    while(!st2.empty())
    {
       cout<<st2.top();
       st2.pop();
    }

}

int main()
{
    int num=621;
    ReverseNum(num);
}
