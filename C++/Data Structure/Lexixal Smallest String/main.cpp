#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    string findLexSmallestString(string s, int a, int b)
    {
        queue<string> q;
        q.push(s);
        unordered_set<string> st;
        st.insert(s);
        string ans = s;
        while (!q.empty())
        {
            string str = q.front();
            q.pop();
            ans = min(ans, str);
            string str1 = add(str, a);
            string str2 = rotate(str, b);
            if (st.find(str1) == st.end())
            {
                q.push(str1);
                st.insert(str1);
            }
            if (st.find(str2) == st.end())
            {
                q.push(str2);
                st.insert(str2);
            }
        }
        return ans;
    }

    string rotate(string s, int b)
    {
        string x = s.substr(0, s.length() - b);
        string y = s.substr(s.length() - b);
        s = y + x;
        cout << s << endl;
        return s;
    }
    string add(string s, int a)
    {
        for (int i = 1; i < s.length(); i = i + 2)
        {
            int num = s[i] - '0';
            num = (num + a) % 10;
            s[i] = '0' + num;
        }
        return s;
    }
};