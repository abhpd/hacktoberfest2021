// 328. Odd Even Linked List
// https://leetcode.com/problems/odd-even-linked-list/

//   Definition for singly-linked list.
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

    //Time Complexity O(N) , Space Complexity O(1)

    ListNode *oddEvenList(ListNode *head)
    {
         if (head == nullptr || head->next == nullptr)
            return head;

        // Pointer for Odd Numbers
        ListNode *oddPointer = head;

        // Pointer for Even Numbers
        ListNode *evenPointer = head->next;

        // This Pointer will Point to start of even numbers bcoz after traversing through LinkedList above two pointers will point to last correspoinding even and odd elements  
        ListNode *evenInitialStart = head->next;

        // if oddPointer is not null and EvenPointer is not null and next of evenPointer is not null 
        while (oddPointer != nullptr && evenPointer != nullptr && evenPointer->next != nullptr)
        {
            // attaching next odd number
            oddPointer->next = evenPointer->next;
            // moving odd pointer to next odd number
            oddPointer = oddPointer->next;

            // attaching next even number
            evenPointer->next = oddPointer->next;
            // moving even pointer to next even number
            evenPointer = evenPointer->next;
        }

        // attaching oddList to starting of evenList (we saved the starting of evenList in evenIntitialStart pointer)
        oddPointer->next = evenInitialStart;
        
        return head;
    }
};