// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/

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
    /* --------Iterative Approach----------------
    Time O(N) , SpaceO(1)
    */
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == nullptr)
            return head;

        ListNode *dummyNode = new ListNode(-1);

        dummyNode->next = head;

        ListNode *tail = dummyNode;

        while (tail != NULL && tail->next != NULL)
        {
            if (tail->next->val == val)
            {
                ListNode *temp = tail->next;
                tail->next = temp->next;
                delete temp;
            }
            else
            {
                tail = tail->next;
            }
        }

        return dummyNode->next;
    }

    /* -----------Recursive Approach------------
    Time O(N) Space O(N) auxillary stack space
    */
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return head;

        head->next = removeElements(head->next, val);
        if (head->val == val)
        {
            ListNode *ans = head->next;
            delete head;
            return ans;
        }
        else
        {
            return head;
        }
    }
};