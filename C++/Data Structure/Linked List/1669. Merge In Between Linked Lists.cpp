// 1669. Merge In Between Linked Lists
// https://leetcode.com/problems/merge-in-between-linked-lists/

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        //Gets the pointer pointing to a
        int moves1 = 1;
        ListNode *temp1 = list1;
        while (moves1 < a)
        {
            temp1 = temp1->next;
            moves1++;
        }

        //Gets the pointer pointing to b
        int moves2 = 1;
        ListNode *temp2 = list1;
        while (moves2 <= b)
        {
            temp2 = temp2->next;
            moves2++;
        }

        //Gets the pointer pointing to the tail of list2
        ListNode *temp3 = list2;
        while (temp3->next != NULL)
        {
            temp3 = temp3->next;
        }

        //set the next pointer of a to the head of list2
        temp1->next = list2;

        //set next of tail of list2 to the pointer to b
        temp3->next = temp2->next;

        return list1;
    }
};