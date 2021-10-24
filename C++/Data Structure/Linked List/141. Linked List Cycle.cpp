// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* --------------------Naive Approach (HashSet) ---------------------
 Iterate over the list and use hashset to keep track of what elements we have previously visited .
 if any time we found that element in our hashset , we have cycle at that position.
 Time O(N) , Space O(N)   
*/

/* ------------- Better Approach (Slow & Fast Pointer) ------------------

*/
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        // if list is empty or has only one node
        if (head == NULL || head->next == NULL)
            return false;

        ListNode *slowptr = head;
        ListNode *fastptr = head;

        while (fastptr != NULL && fastptr->next != NULL)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;

            // if anytime fastptr becomes equal to slowptr that means , linkedlist has cycle thats why they are meeting at a point.
            if (fastptr == slowptr)
                return true;
        }

        // if we came out of while loop that means we encounterd null value so retuen false.
        return false;
    }
};