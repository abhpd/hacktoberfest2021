#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    cin.ignore();

    char arr[n + 1];
    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int currLen = 0, maxLen = 0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
            }
            currLen = 0;
        }
        else
            currLen++;

        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << maxLen << endl;

    return 0;
}






/*Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

Try the new cross-platform PowerShell https://aka.ms/pscore6

PS C:\Users\harde\c programming> cd "c:\Users\harde\c programming\My C++ Program\" ; if 
($?) { g++ Largest_Word_In_Sentence.cpp -o Largest_Word_In_Sentence } ; if ($?) { .\Largest_Word_In_Sentence }
10 
do or die 
3
PS C:\Users\harde\c programming\My C++ Program> */