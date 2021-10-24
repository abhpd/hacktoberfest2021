// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:

    // Time O(N) Space O(1)
    // iterative Solution
    ListNode *deleteDuplicates(ListNode *head)

    {
        ListNode *curr = head;

        while (curr->next != nullptr)
        {
            if (curr->val == curr->next->val)
                curr->next = curr->next->next;

            else
                curr = curr->next;
        }

        return head;
    }

    // Time O(N) Space O(N) 
    // Recursive Solution.
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp = deleteDuplicates(head->next);

        if (head->val == temp->val)
            return temp;
        else
        {
            head->next = temp;
            return head;
        }
    }
};