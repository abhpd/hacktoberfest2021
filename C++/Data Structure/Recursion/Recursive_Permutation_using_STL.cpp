#include <bits/stdc++.h>
using namespace std;

void permute(string str)
{
    // Sort the string in lexicographically
    // ascending order
    sort(str.begin(), str.end());

    // Keep printing next permutation while there
    // is next permutation
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

// Driver code
int main()
{
    string str = "CBA";
    permute(str);
    return 0;
}