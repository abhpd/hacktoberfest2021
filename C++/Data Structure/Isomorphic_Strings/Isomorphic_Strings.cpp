class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int i, j;
        map<char, char> m;
        for (i = 0; i < s.length(); i++)
        {
            if (m.find(s[i]) == m.end())
            {
                m.insert(pair<char, char>(s[i], t[i]));
            }
            else
            {
                if (m[s[i]] != t[i])
                    return false;
            }
        }
        //for every char in t there should be same char in s also
        //for example "badc","eaea"
        //here for d in s there should be another char other than e because e is already assigned for char b,similarly for a
        map<char, char> m1;
        for (i = 0; i < t.length(); i++)
        {
            if (m1.find(t[i]) == m1.end())
            {
                m1.insert(pair<char, char>(t[i], s[i]));
            }
            else
            {
                if (m1[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
