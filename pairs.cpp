#include<bits/stdc++.h>

using namespace std;

int main()
{
    pair <int, string> p1;  // This is how we declare a pair. We can make pair of every single data types, there is no restriction.

    // p1=make_pair(1,"Roll 1");  // This is one way of creating a pair, the other way is

    p1={1,"Roll 1"};

    // Acessing elements of a pair: -
    cout<<p1.first<<" "<<p1.second<<endl;

    // Updating elements of a pair: -
    p1.first=2;
    p1.second="Roll 2";

    cout<<p1.first<<" "<<p1.second<<endl;

    // creaitng an array of pairs: 

    // pair <int, int> squares[10];

    // for(int i=0; i<10; i++)
    // {
    //     squares[i].first=i;
    //     squares[i].second=i*i;
    // }

    // for (int i=0; i<10; i++)
    // {
    //     cout<<squares[i].first<<" "<<squares[i].second<<endl;
    // }

    // Generally pairs are used with vectors, because we need to create an array of dynamic size

    vector <pair<int,int>> squares;

    for(int i=0; i<10; i++)
    {
        squares.push_back({i,i*i});  // Remember we use curly braces to denote pair, {value1, value2}.
    }

    for (int i=0; i<10; i++)
    {
        cout<<squares[i].first<<" "<<squares[i].second<<endl;
    }
}