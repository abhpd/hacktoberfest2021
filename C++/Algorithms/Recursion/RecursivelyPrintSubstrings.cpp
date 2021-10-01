#include<bits/stdc++.h>
using namespace std;
//Function to print all substrings of a string using recursion
void substrings(string s, string ans)
{
    //Base case for each division
    if(s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    string ros = s.substr(1);//rest of string

    //Recursive functions branching from original string
    substrings(ros,ans);
    substrings(ros,ans+ch);
}

int main()
{
    string s;
    cout<<"Input a string ";
    getline(cin,s);
    string ans = "";
    substrings(s,ans);
    return 0;
}
