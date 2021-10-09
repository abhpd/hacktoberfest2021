

#include <stdio.h>
#include <iostream>

using namespace std;

string RailFenceDecipher(string CipherText1, string key);

int main()
{
    string CipherText1;
    cout << "Enter the message" << endl;
    getline(cin, CipherText1);

    string key;
    cout << "Enter the key " << endl;
    getline(cin, key);

    string PlainText1 = RailFenceDecipher(CipherText1, key);

    for (auto i = 0; i < PlainText1.size(); i++)
    {
        cout << PlainText1[i];
    }
    cout << endl;

    return 0;
}

string RailFenceDecipher(string CipherText1, string key)
{
    string PlainText1;

    int new_key = stoi(key);

    int row = new_key;

    int column = CipherText1.length();

    char RailFence[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            RailFence[i][j] = '_'; //filling blank space to the rail fence matrix
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

        RailFence[i][j] = '*';

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

    int k = 0;
    while (k < CipherText1.length())
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (RailFence[i][j] == '*')
                {
                    RailFence[i][j] = CipherText1[k];
                    k++;
                }
            }
        }
    }

    /***********************************************************************************************/
    directionChange = false;
    i = 0, j = 0;
    for (int k = 0; k < column; k++)
    {

        if (i == 0 || i == new_key - 1)
        {
            directionChange = !directionChange;
        }

        PlainText1.push_back(RailFence[i][j]);

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

    return PlainText1;
}