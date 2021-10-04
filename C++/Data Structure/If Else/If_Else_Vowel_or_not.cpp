#include <iostream>
using namespace std;

int main()
{

    char c;
    int isLowercaseVowel, isUppercaseVowel;

    cout << "Enter an Alphabet " << endl;
    cin >> c;

    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (isLowercaseVowel || isUppercaseVowel)
    {
        cout << c << " is a Vowel" << endl;
    }
    else
    {
        cout << c << " is not a Vowel " << endl;
    }

    return 0;
}