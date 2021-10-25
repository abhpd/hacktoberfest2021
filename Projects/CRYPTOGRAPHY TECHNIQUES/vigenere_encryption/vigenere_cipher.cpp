#include <iostream>
#include <stdio.h>

using namespace std;

void vigenere_cipher(string, string); // function prototyping
string generate_key(string, string);  // function prototyping

int main(void)
{
    cout << "enter the message without including space in between them and must be in small letters " << endl;
    string plaintext;
    getline(cin, plaintext);

    cout << "enter the key " << endl;
    string key;
    getline(cin, key);

    vigenere_cipher(plaintext, key);

    return 0;
}

void vigenere_cipher(string plaintext, string key)
{
    string new_key = generate_key(plaintext, key);
    string cipher_text = "";

    for (int i = 0; i < plaintext.size(); i++)
    {
        cipher_text.push_back(char(int((plaintext[i] - 97) + (new_key[i] - 97)) % 26) + 97); // 97 is done to converrt into small letters
    }

    cout << "the encrypted text is " << endl;

    for (int i = 0; i < cipher_text.size(); i++)
    {
        cout << cipher_text[i];
    }
}

string generate_key(string plaintext, string key)
{
    int size_of_plaintext = plaintext.size() - key.size();
    int j = 0;

    for (int i = 0; i < size_of_plaintext; i++)
    {

        if (key.size() == plaintext.size())
        {
            break; // key length and plaintext(message) length is same
        }

        else
        {
            key.push_back(key[j]);
            j++;
        }

        if (j == key.size())
        {
            j = 0;
        }
    }

    return key;
}