

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* tail = new SinglyLinkedListNode(data);
    if (head == NULL) {
        head= tail;
        return head;
    }
    SinglyLinkedListNode *p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = tail;
    return head;
}

