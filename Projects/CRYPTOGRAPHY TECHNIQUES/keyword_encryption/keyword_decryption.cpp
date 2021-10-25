/*
   KEYWORD ( MONOALPHABETIC ENCRYPTION )
*/

// user inputted key must be alphabetic not alphanumeric

#include "iostream"
#include "stdio.h"
#include <ctype.h>
#include <vector>

using namespace std;

string decrypt(string);
int keyword_decrypt(string, string);

int main(void)
{
    cout << "Enter the message to decrypt(note :: it must be in small letters ) " << endl;
    string cipher_text;

    getline(cin, cipher_text);

    string key;
    cout << "Enter the key (note :: key must not be repeating)" << endl;
    getline(cin, key);

    keyword_decrypt(cipher_text, key);

    return 0;
}

string decrypt(string key)
{
    bool array[26] = {false};

    int j ;

    char decrypt[26];
    int size = key.length(); // used to get the length of the string :: key

    for (int i = 0; i < size; i++)
    {
        if (array[i] == false)
        {
            decrypt[i] = key[i];
            array[i] = true;
        }
    }

     isupper(decrypt[0]) ? j = 65 : j= 97;

    for (int i = size; i < 26; i++)
    {
        if (array[i] == false)
        {
            decrypt[i] = char(j);

            for (int k = 0; k < size; k++)
            {
                if (decrypt[i] == key[k])
                {
                    ++j;

                    decrypt[i] = char(j);
                    k = -1;
                }
            }

            array[i] = true;

            ++j;
        }
    }

    return decrypt;
}

int keyword_decrypt(string text, string key)
{
    string use_decrypt = decrypt(key);

    vector<char> decoded_text;

    int size = text.size();

    for (int i = 0; i < size; i++)
    {
        if (isupper(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == use_decrypt[j])
                {
                    decoded_text.push_back(char(j + 65));
                    break;
                }
            }
        }

        else if (islower(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (text[i] == use_decrypt[j])
                {
                    decoded_text.push_back(char(j + 97));
                    break;
                }
            }
        }

        else
        {
            decoded_text.push_back((text[i]));
        }
    }

    cout <<"DECRYPTED KEY :: MESSAGE"<<endl;

    for (int i = 0; i < size; i++)
    {
        cout << decoded_text[i];
    }
    return 0;
}
