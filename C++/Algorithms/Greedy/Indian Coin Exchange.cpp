/*Given a value V, if we want to make a change for V Rs, and we have an infinite supply of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to make the change?
Examples:

Input: V = 70
Output: 2
We need a 50 Rs note and a 20 Rs note.

Input: V = 121
Output: 3
We need a 100 Rs note, a 20 Rs note and a 1 Rs coin.

Approach : 
1. Sort the array of coins in decreasing order.
2. Find the largest denomination that is smaller than current amount.
3. Increment the number of coins needed. Subtract value of found denomination from amount.
4. If amount becomes 0, then print result.
5. Else repeat steps 2,3 and 4 for new value of V.

*/


#include <iostream>
#include<algorithm>
using namespace std;

int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};

int coinsChange(int money)
{
    int num_of_coins = 0;
    
    // keep looping until we have money
    while(money > 0)
    {
        // find the index of number which is in near denomination
        int index = upper_bound(coins,coins + 9,money) - 1 - coins;
        money = money - coins[index];
        num_of_coins++;
    }
    return num_of_coins;
}

int main()
{
    // money = amount whose change we need
    int money;
    cin>>money;
    cout<<coinsChange(money);
    return 0;
}
