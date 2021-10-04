#include <iostream>
using namespace std;

void check(char ch)
{

    if ((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
    {
        cout << ch << " is an Alphabet";
    }
    else
    {
        cout << ch << " is not an Alphabet";
    }
}

int main()
{

    char ch;
    cout << "Enter the element " << endl;
    cin >> ch;

    check(ch);

        return 0;
}
