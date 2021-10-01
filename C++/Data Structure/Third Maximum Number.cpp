class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long f = LONG_MIN, s = LONG_MIN, t = LONG_MIN;
        for (int n : nums)
        {
            if (n == f || n == s || n == t)
                continue;
            if (n > f)
            {
                t = s;
                s = f;
                f = n;
            }
            else if (n > s)
            {
                t = s;
                s = n;
            }
            else if (n > t)
            {
                t = n;
            }
        }
        if (t != LONG_MIN)
            return t;
        return f;
    }
};