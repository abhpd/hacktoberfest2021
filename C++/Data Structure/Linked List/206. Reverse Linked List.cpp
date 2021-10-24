// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list/
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
    // iterative solution
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode *P = nullptr;    //Prev pointer
        ListNode *C = head;       //Current pointer
        ListNode *N = head->next; //Next pointer

        while (C != nullptr)
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

        return P;
    }

    // Recursive solution
    ListNode *recursiveReverseList(ListNode *head)
    {
        // if list is empty return null;
        if (head == nullptr)
            return head;

        // if its a single element return . 
        if (head->next == nullptr)
            return head;

        // This is our newHead in second to last elements in list after reversing  
        ListNode *newHead = recursiveReverseList(head->next);

        //This temp points to second element in LinkedList
        ListNode *temp = head->next; 

        // attaching link of second to first .
        temp->next = head;

        // In reverse of linked list , first's next should point to null .  
        head->next = nullptr;

        return newHead;
    }
};