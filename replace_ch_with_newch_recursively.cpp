/*
    a string is given
    replace all occurences of some character ch to new_ch in the string

    I/N : 
        abacd
        a x   ( ch = a, new_ch = x)
    O/P :
        xbxcd
*/
// RECURSION

#include <bits/stdc++.h>
using namespace std;

void func(string str, char ch, char new_ch, int size) {
  
    // when you have traversed the whole string and replaces the ch to new_ch
    // print the string and return
    if (size == 0) {
        cout << str << "\n";
        return;
    }
    // if str[size - 1] == ch replace it with new_ch
    if (str[size - 1] == ch) {
        str[size - 1] = new_ch;
        func(str, ch, new_ch, size - 1);
    } else
        func(str, ch, new_ch, size - 1); // str[size - 1] != ch call the function for the next index
}

int main() {

    // string input
    string str;
    cin >> str;

    // size of the string
    int len = str.size();
    // ch ( character to find ) , new_ch ( character to replace with )
    char ch, new_ch;
    cin >> ch >> new_ch;

    // function to perform the operation
    func(str, ch, new_ch, len);

    return 0;
}
