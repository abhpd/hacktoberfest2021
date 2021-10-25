/*
   KEYWORD ( MONOALPHABETIC ENCRYPTION )
*/

// user inputted key must be alphabetic not alphanumeric

#include "iostream"
#include "stdio.h"
#include <ctype.h>
#include <vector>

using namespace std;

string encrypt(string);
int keyword_encrypt(string, string);

int main(void)
{
    cout << "Enter the message to encrypt " << endl;
    string plain_text;

    getline(cin, plain_text);

    string key;
    cout << "Enter the key " << endl;
    getline(cin, key);

    keyword_encrypt(plain_text, key);

    return 0;
}

string encrypt(string key)
{
    bool array[26] = {false};
     int j ;

    char encrypt[26];
    int size = key.length(); // used to get the length of the string :: key

    for (int i = 0; i < size; i++)
    {
        if (array[i] == false)
        {
            encrypt[i] = key[i];
            array[i] = true;
        }
    }

   isupper(encrypt[0]) ? j = 65 : j = 97;

    for (int i = size; i < 26; i++)
    {
        if (array[i] == false)
        {
            encrypt[i] = char(j);

            for (int k = 0; k < size; k++)
            {
                if (encrypt[i] == key[k])
                {
                    ++j;

                    encrypt[i] = char(j);
                    k = -1;
                }
            }

            array[i] = true;

            ++j;
        }
    }

  

    return encrypt;
}

int keyword_encrypt(string text, string key)
{
    string use_encrypt = encrypt(key);

    vector<char> coded_text;

    int size = text.size();

    for (int i = 0; i < size; i++)
    {
        if (isupper(text[i]))
        {
            coded_text.push_back(use_encrypt[text[i] - 65]);
        }

        else if (islower(text[i]))
        {
            coded_text.push_back(use_encrypt[text[i] - 97]);
        }

        else
        {
            coded_text.push_back(text[i]);
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << coded_text[i];
    }
    return 0;
}