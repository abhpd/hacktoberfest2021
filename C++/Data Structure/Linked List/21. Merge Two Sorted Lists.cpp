// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/

// The Naive Approach would be to create a new list and keep adding nodes to it by iterating over the list and comparing the nodes simultaneuously .Time Complexity O(N+M) . Space Complexity O(N+M)

// More clean and intutive approach would be to use recursion to merge the sorted links linked inplace.
// Time Complexity O(N+M) , Space Complexity O(N+M) - Only the Stack Space
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // base conditions
    if (l1 == NULL)
        return l2;

    if (l2 == NULl)
        return l1;

    // if l1's node is amller than l2's node
    if (l1->val < l2->val)
    {
        // use l1 as head and attach it next to the list returned by the recursive call to l1's next node and l2
        l1->next = mergeTwoLists(l1->next, l2);

        // return the list formed.
        return l1;
    }

    else
    {
        // use l2 as head and attach it next to the list returned by the recursive call to l2's next node and l1
        l2->next = mergeTwoLists(l1, l2->next);

        // return the list formed
        return l2;
    }
}

// The Best Approach would be to use iterative method to avoid the stack space and merge in O(N+M) Time and O(1) Space
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // base conditions
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    // ans is the head of our mergedList
    ListNode *ans, *tail;
    // Comapring and adding the first node.
    if (l1->val < l2->val)
    {
        // if l1 is smaller point ans to l1
        // point tail to l1 and move l1 forward by one position
        ans = l1;
        tail = l1;
        l1 = l1->next;
    }
    else
    {
        // else l2 is smaller point ans to l2
        // point tail to l2 and move l2 forward by one position
        ans = l2;
        tail = l2;
        l2 = l2->next;
    }

    // while l1 or l2 are not null , keep comparing and adding the nodes to end of tail
    while (l1 != NULL && l2 != NULL)
    {

        // if l1 is smaller attach the node to tail , move tail to that node and move l1 forward by one position
        if (l1->val < l2->val)
        {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        // if l2 is smaller attach the node to tail , move tail to that node and move l2 forward by one position
        else
        {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }

    // if l1 is exhausted , attach remaining nodes of l2 to tail
    if (l1 == NULL)
        tail->next = l2;
    // else l2 is exhausted , attach remaining nodes of l2 to tail
    else
        tail->next = l1;

    // return our ans (which points to head).
    return ans;
}
