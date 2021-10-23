/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) 
    {
        int i = 1;
        ListNode head = list1;
        while(i<a)
        {
            list1 = list1.next;
            i++;
        }
        ListNode tmp = list1.next;
        list1.next = list2;
        while(i <= b)
        {
            tmp = tmp.next;
            i++;
        }
        ListNode curr = list2;
        while(curr.next != null)
            curr = curr.next;
        curr.next = tmp;
        return head;
    }
}
