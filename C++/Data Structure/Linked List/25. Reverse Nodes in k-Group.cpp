// 25. Reverse Nodes in k-Group
// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    //----------------- Time Complexity O(N) and Space Complexity O(N/k)--------------------

    // This function will reverse the list from start to end and after reversing the lsit , the Pointer P will be new head and it will be at end point
    // so end becomes newhead and start becomes end of list  (both are swapped)
    void reverse(ListNode *start, ListNode *end)
    {
        ListNode *P = nullptr;     //Previous pointer
        ListNode *C = start;       //Current pointer
        ListNode *N = start->next; //Next pointer

        while (P != end)
        {
            // put next curr to prev (i.e reverse the link)
            C->next = P;

            // move prev forward to curr position
            P = C;

            // move curr forward to next position
            C = N;

            // if our next pointer dosen't points to null then only move next to one postion forward
            if (N != nullptr)
                N = N->next;
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // if head is null or there's only one node or k is equal to 1 we have to do nothing in that case.
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;

        // initialize start to head , starting node of group of K nodes
        ListNode *S = head;

        // For now initialize end to head, on next step we will make it point to last node of group of K nodes
        ListNode *E = head;

        //In order to make E point to last node of first group of K nodes. We have to increment it k-1 times
        int inc = k - 1;

        while (inc--)
        {
            E = E->next;
            // if length of list is not equal to K (is less than k) or further groups of K nodes cannot be made , then do nothing just return head (according to quetsion).
            if (E == nullptr)
                return head;
        }

        // getting the newhead returned by recursive call made to list after extracting first group of K nodes
        ListNode *nextHead = reverseKGroup(E->next, k);

        // reversing list from S to E.
        // this will reverse out first group of K nodes .
        reverse(S, E);

        // After reversing list feom S to E , our S and E are swapped now , so E becomes head(start) and S becomes end. therefore attach the remaining list(newHead returned by recursive call) to S .
        S->next = nextHead;

        // return E as its our head .
        return E;
    }

    // to eliminate the extra space (N/k) in recursive method we will do it by iteration method
    //----------------- Time Complexity O(N) and Space Complexity O(1)

    ListNode *iterativeReverseKGroup(ListNode *head, int k)
    {

        if (head == nullptr || head->next == nullptr || k == 1)
            return head;

        // This is a dummy node which connects to head.
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        // While we will swap K nodes from start to end we need a pointer which points to the node which was before start because in reversing the links would be broken  , that's why beforeStart equals dummynode(before start).
        ListNode *beforeStart = dummyNode;
        ListNode *end = head;
        int i = 0;

        while (end != nullptr)
        {
            i++;

            // if we are able to make a group of k nodes then
            if (i % k == 0)
            {
                ListNode *start = beforeStart->next;
                // Temp will store the address of next node after End
                ListNode *temp = end->next;

                // reversing nodes from start to end.
                reverse(start, end);
                // after revrsing of k nodes , start and end are swapped in themselves.
                // end becomes new head for k group of nodes and start becoms end
                // connect beforeStart to start of this nodgroup of K nodes
                beforeStart->next = end;

                // connect end this nodgroup of K nodes to next node in list.
                start->next = temp;

                // move before start to position which would be the prev to next starting position
                beforeStart = start;

                // move end to temp(start->next);
                end = temp;
            }

            // if not made a group of k nodes , just move end forward.
            else
            {
                end = end->next;
            }
        }

        // return dummyNode's next becuse it's next was pointing to head.
        return dummyNode->next;
    }
};