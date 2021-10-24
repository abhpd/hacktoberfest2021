// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/
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

/* -------------------Brute Force -------------------
    use a vector to store all nodes of linked list and check the vector for palindrom
    Time Complexity O(N)
     Space Complexity O(N)
 */


/* ------------------- Optimal Approach -------------------
    Find the mid of list and reverse list after that (use slow and fast pointers)
    Now put two pointers at mid and start for comparison to check for palindrom

    Time Complexity O(n)
    Space Compliexity O(1)
*/

public:
    
    // Func to reverse linked list
    ListNode* reverseList(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        
        ListNode* c = head;
        ListNode* p =NULL ;
        ListNode* n = head->next;
        
        while( c != NULL)
        {
            c->next = p;
            p = c;
            c = n;
            if( n != NULL)
                n = n->next;
        }
        
        return p;
    }
    
    
    bool isPalindrome(ListNode *head)
    {
        if(head == NULL)
            return false;
        if(head->next == NULL)
            return true;
        
        ListNode *slow = head;
        ListNode *fast = head;

        // finding the node which is just before mid .
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //reversing and attching it to next of slow (mid-1) node  
        slow->next = reverseList(slow->next);

        // start and mid pointers to comapre fo palindrom
        ListNode *start = head , *mid = slow->next ;

        // check for palindrom    
        while(mid != NULL)
        {   
            // if they differ return false
            if(start->val != mid->val)
                return false;

            // increment the pointers 
            start = start->next;
            mid = mid->next;
        }
        
        // putting the list in original order as it was before reversing after the mid part
        slow->next = reverseList(slow->next);

        // if program control reached this far , it means that mid pointer reached null and list is plaindrom.
        return true;
        
    }
};