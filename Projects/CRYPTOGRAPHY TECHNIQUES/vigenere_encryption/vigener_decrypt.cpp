#include <iostream>
#include <stdio.h>

using namespace std;

void vigenere_decrypt(string, string); // function prototyping
string generate_key(string, string);  // function prototyping

int main(void)
{
    cout << "enter the message without including space in between them " << endl;
    string ciphertext;
    getline(cin, ciphertext);

    cout << "enter the key " << endl;
    string key;
    getline(cin, key);

    vigenere_decrypt(ciphertext, key);

    return 0;
}

void vigenere_decrypt(string ciphertext, string key)
{
    string new_key = generate_key(ciphertext, key);
    string decrypt_text ="";

    for (int i = 0; i < ciphertext.size() ; i++)
    {
        decrypt_text.push_back(char (int ((ciphertext[i] -97) - (new_key[i] - 97)  ) % 26) + 97 ); // 97 is done to converrt into small letters 
    }
 

    cout <<"the decrypted text is "<<endl;

    for ( int i = 0 ; i < decrypt_text.size() ; i++)
    {
        cout <<decrypt_text[i];
    }

    
}

/*

this will generate the key of same length of cipher text  

*/

string generate_key(string ciphertext, string key)
{
    int size_of_ciphertext = ciphertext.size() - key.size();
    int j = 0;


    for (int i = 0; i < size_of_ciphertext; i++)
    {
        
        if (key.size() == ciphertext.size())
        {
            break; // key length and ciphertext(message) length is same
        }
        /*
        
        this is used to make the keylength equal to ciphertext length 
        by repeating itself again and again upto cipher text length  
        
        */
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