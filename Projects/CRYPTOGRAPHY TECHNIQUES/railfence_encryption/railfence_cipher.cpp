#include <stdio.h>
#include <iostream>

using namespace std;

string RailFenceCipher(string plaintext, string key);

int main()
{
    string plaintext;
    cout << "Enter the message" << endl;
    getline(cin, plaintext);

    string key;
    cout << "Enter the key " << endl;
    getline(cin, key);

    string ciphertext = RailFenceCipher(plaintext, key);

    for (auto i = 0; i < ciphertext.size(); i++)
    {
        cout << ciphertext[i];
    }
    cout << endl;

    return 0;
}

string RailFenceCipher(string plaintext, string key)
{
    string ciphertext;

    int new_key = stoi(key); // to convert string to integer

    int row = new_key; // to represent the no. of rows

    int column = plaintext.length(); // to represent the no. of columns and columns equals to length of plaintext 

    char RailFence[row][column]; 

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            RailFence[i][j] = '%'; //filling blank space to the rail fence matrix
        }
    }

    bool directionChange = false; // used to go downward in the RailFence matrix

    int i = 0; //used for the row
    int j = 0; //used for the column

    for (int k = 0; k < column; k++)
    {

        if (i == 0 || i == new_key - 1)
        {
            directionChange = !directionChange;
        }

        RailFence[i][j] = plaintext[k];

        if (directionChange == false)
        {
            --i;
        }
        else
        {
            ++i;
        }
        j++; //always increase the column in the RailFence
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (RailFence[i][j] != '%')
            {
                ciphertext.push_back(RailFence[i][j]);
            }
        }
    }

    return ciphertext;
}