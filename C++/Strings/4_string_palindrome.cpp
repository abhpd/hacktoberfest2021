#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string str;
    cout<<"Enter string:"<<endl;
    getline(cin, str);

    char* ch_arr;
    ch_arr = &str[0];

    int len = strlen(ch_arr) - 1;
    int start =0;

    while(len > start)
    {
        if(ch_arr[start++] != ch_arr[len--])
        {
            cout<<"String not palindrome"<<endl;
            return 0;
        }
    }
    cout<<"String is palindrome";
return 0;   
}