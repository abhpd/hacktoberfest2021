/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 Sample Test Case
 Input: l1 = [1,2,4], l2 = [1,3,4]
 Output: [1,1,2,3,4,4]
 */

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        //if first linkedlist is empty then simply return head of second linkedist
        if(l1==null)
            return l2;
        //if second linkedlist is empty then simply return head of first linkedist
        if(l2==null)
            return l1;
        
        //l3 denotes head of the resultant linkedlist
        ListNode l3;
        //t3 denotes tail of the resultant linkedlist
        ListNode t3;
        
        //if first value of ll1 is smaller then ll2 we will initialise l3 and t3 with l1 move the l1 ptr to next posn
        if(l1.val<=l2.val)
        {
            l3=l1;
            t3=l1;
            l1=l1.next;
        }
        //if first value of ll2 is smaller then ll1 we will initialise l3 and t3 with l2 and move the l2 ptr to next posn
        else
        {
            l3=l2;
            t3=l2;
            l2=l2.next;
        }
        
        while(l1!=null && l2!=null)
        {
            //adding smaller value to the t3 and moving the respective ptr to next
            if(l1.val<=l2.val)
            {
                t3.next=l1;
                l1=l1.next;
            }
            else
            {
                t3.next=l2;
                l2=l2.next;
            }
            t3=t3.next;
        }
        
        if(l1!=null)
            t3.next=l1;
        
        else
            t3.next=l2;
        
        return l3;
    }
}
