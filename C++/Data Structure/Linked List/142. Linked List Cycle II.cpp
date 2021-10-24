// 142. Linked List Cycle II
// https://leetcode.com/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        ListNode *slowptr = head;
        ListNode *fastptr = head;

        while (fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            // if anytime fastptr becomes equal to slowptr that means , linkedlist has cycle thats why they are meeting at a point break out of loop 
            if (fastptr == slowptr)
                break;
        }

        // check if fastptr has become null that means we don't have any cycle in list 
        if (fastptr == nullptr || fastptr->next == nullptr)
            return nullptr;

        // if there is cycle present
        // putting fastptr to starting position
        fastptr = head;

        // keep moving both pointers forward until they meet once again
        while (slowptr != fastptr)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }

        // return either slow or fast bcoz both are at same position
        return fastptr;
    }
};