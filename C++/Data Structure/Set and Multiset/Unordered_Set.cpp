#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{

    unordered_set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(5);

    for (auto i : s)
        cout << i << " ";
    cout << endl;

    s.erase(2);
    s.erase(s.begin());

    for (auto i : s)
        cout << i << " ";
    cout << endl;
}