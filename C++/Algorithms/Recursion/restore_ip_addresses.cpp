#include <iostream>
#include <vector>
using namespace std;
bool isOkay(string gen)
{
    if (gen.length() > 3)
    {
        return false;
    }
    if (gen.length() >= 2 && gen[0] == '0')
    {
        return false;
    }
    if (gen.length() == 3 && gen[0] == '0' && (gen[2] != '0' || gen[1] != '0'))
    {
        return false;
    }
    int val = stoi(gen);
    if (val > 255)
    {
        return false;
    }
    return true;
}

void solve(vector<string> &ans, string orig, string gen, string s, int index, int dots)
{
    if (dots > 3)
    {
        return;
    }
    if (index == s.length() && dots < 3)
    {
        return;
    }
    if (index == s.length())
    {
        if (isOkay(gen))
        {
            orig += gen;
        }
        else
        {
            return;
        }
        ans.push_back(orig);
        return;
    }

    if (gen.length() == 0)
    {
        solve(ans, orig, gen + s[index], s, index + 1, dots);
    }
    else
    {
        if (gen.length() < 3)
        {
            solve(ans, orig, gen + s[index], s, index + 1, dots);
        }
        if (isOkay(gen))
        {
            solve(ans, orig + gen + '.', "", s, index, dots + 1);
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    if (s.length() > 12)
    {
        return ans;
    }
    string gen, orig;
    solve(ans, orig, gen, s, 0, 0);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> res = restoreIpAddresses(s);
    for (auto it : res)
    {
        cout << "[ " << it << " ]"
             << " ";
    }
}
