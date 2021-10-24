// 160. Intersection of Two Linked Lists
// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* ---------Brute Force --------------
For every node in A iterate over B to find the matching node .
so for every node of A we are iterating over B util there's a match.

Time Complexity O(N*M) where N and M are sizes of A and B lists.
Space Comlpexity O(1) .   
*/
class Solution
{
public:
    /* ---------Brute Force --------------
    For every node in A iterate over B to find the matching node .
    so for every node of A we are iterating over B util there's a match.

    Time Complexity O(N*M) where N and M are sizes of A and B lists.
    Space Comlpexity O(1) .   
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // if any of the list is null or empty return false , they can't intersect
        if (headA == NULL || headB == NULL)
            return NULL;

        // Poniter to store head value of A
        ListNode *A = headA;

        // while A dosen't becomes Null,
        while (A != NULL)
        {
            // create a temp to store A's current node.
            ListNode *temp = A;

            // Pointer to store B's head for every node of A
            ListNode *B = headB;

            // while b dose not becomes null iterate over it
            while (B != NULL)
            {
                // if any node matches return that node
                if (temp == B)
                    return temp;
                // else move forward B by one position
                else
                    B = B->next;
            }

            //we haven;t found any match for current Node of A so move A to next node and further repeat the process
            A = A->next;
        }

        // if we came out of both loops return null , we haven't found any match
        return NULL;
    }

    /* ---------Better Approach (Using Set) --------------
    Iterate over A and store it all node in set , further iterate over B and check if that node is present in Set or Not , if found that means there's an intersection point. Simply return that node 
    
    Time Complexity O(N+M)  where N and M are sizes of A and B lists.
    Space Comlpexity O(N) .   
    */

    /* ---------Optimal Approach 1 --------------
    
    find length of both lists A and B .
    if A is smaller move B (B - A) positions ahead.
    else if B is smaller move A (A- B) positions ahaed. 

    After this they would come in sync . 
    then start interating until they reach NULL 
        if any node matches retunr that node.

    Time Complexity O( max(N,M) )  where N and M are sizes of A and B lists.
    Space Comlpexity O(1) .   
    */

    /* ---------Optimal Approach 2 --------------
    
    We woould use a similar kind of approah as above .

    Suppose 
        lenght of A list is m + x
        lenght of B list is n + x
    where x is common part in them.

    to make them equal we can do this
        A = m+x + n+ x
        B = n+x + m+x
    now they are equal

    We would start iterating while node form A and B are not equal
        we check if ( A becomes NULL )
            it means it has covered its length(m+x) and has to cover B's length(n+x) , so put it to B's head.
        else
            move forward one postion.

        similary check and do this for B also and put B at A's head if null.                   
    We are doing this in order to make them in sync after one iteration they will come in sync and we will find the intersection

    Time Complexity O( max(N,M )  where N and M are sizes of A and B lists.
    Space Comlpexity O(1) .   
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *A = headA;
        ListNode *B = headB;

        // iterating until they are equal ( null or a suitable match)
        while (A != B)
        {
            // if A equals null , put A to head of B list.
            if (A == nullptr)
                A = headB;
            //else mmove it forward
            else
                A = A->next;


            // if B equals null , put B to head of A list.
            if (B == nullptr)
                B = headA;
            //else mmove it forward
            else
                B = B->next;
        }

        // return either of them .
        return A;
    }
};
