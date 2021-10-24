// 1721. Swapping Nodes in a Linked List
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

class Solution {
public:
    
    // function to find kth element from start
    ListNode* kthStart(ListNode* head ,int k)
    {
        ListNode* curr = head;
        while(k-1 > 0)
        {
            k--;
            curr = curr->next;
        }
        
        // cout << curr->val <<endl;
        
        return curr;
    }
    
    // function to find kth element from end;
    ListNode* kthEnd(ListNode* head , int k)
    {
        ListNode* curr = head;
        int size = 1;
        
        // calculating total size of list 
        while(curr->next != NULL)
        {
            size++;
            curr = curr->next;
        }
        
        // cout << size<<endl;

        // position of kth element from start.
        int n = size - k +1;
        
        // getting kth element form start
        return kthStart(head,n);
    }
    
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* first = kthStart(head, k);        
        ListNode* second = kthEnd(head, k);
        
        // swapping both elements
        swap(first->val , second->val);

        return head;
    }
};