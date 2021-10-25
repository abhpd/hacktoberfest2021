#include "iostream"
#include "stdio.h"
#include <ctype.h>
#include <vector>

using namespace std;

int ceaser_decrypt(string text, int key);

int main(void)
{
    cout << "Enter the message to decrypt " << endl;
    string cipher_text;

    getline(cin, cipher_text);

    int key;
    cout << "Enter the key ";
    cin >> key;

    ceaser_decrypt(cipher_text, key);

    return 0;
} 

int ceaser_decrypt(string text, int key)
{
    vector<char> decrypted_text;

    int size = text.length(); // it is used to get the length of text inputted

    for (int i = 0; i < size; i++)
    {
        if (isupper(text[i]))
        {
            decrypted_text.push_back(char(int(text[i] - key - 65) % 26 + 65));
        }

        else if (islower(text[i]))
        {
            decrypted_text.push_back(char(int(text[i] - key - 97) % 26 + 97));
        }

        else
        {
            decrypted_text.push_back(char(text[i]));
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%c", decrypted_text[i]);
    }

    return 0;
}