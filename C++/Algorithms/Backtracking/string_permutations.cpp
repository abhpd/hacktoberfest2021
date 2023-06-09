/*
To find all possible permutation of letters in a given string
fro e.g. abc
abc
acb
bac
bca
cab
cba
TIME COMPLEXITY : O (n! * n)
*/

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void perm(string s, int visited[], string &l, int &count)
{
    if (s.size() == l.size()) //Base case if generated string has same length as original string print it
    {
        count++; //add to count (total possible strings)
        cout << l << endl;
        return;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (visited[i] == 0) //if the character of string is not visited
            {
                visited[i] = 1;             //mark it as visited
                l = l + s[i];               //append it to the generated string
                perm(s, visited, l, count); //call perm function again
                l.pop_back();               //pop the last element
                visited[i] = 0;             //mark as unvisited
            }
        }
    }
}

int main()
{
    string s, l = "";
    cout << "\nEnter String :"; //take string from user
    cin >> s;
    int visited[s.size()] = {0}; //set all values of visited to 0
    int count = 0;               //total possible strings
    perm(s, visited, l, count);
    cout << "\nTotal possible :" << count << endl;
    return 0;
}
