#include <bits/stdc++.h>
#include <string>
using namespace std;

void permute(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string left = s.substr(0, i);
        string right = s.substr(i + 1);
        string after = left + right;
        permute(after, ans + ch);
    }
}

int main()
{
    string s;
    string answer = "";

    cin >> s;

    cout << "\nAll possible strings are : ";
    permute(s, answer);
    return 0;
}