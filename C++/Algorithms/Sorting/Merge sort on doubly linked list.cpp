#include <bits/stdc++.h> 
using namespace std; 
class Node  
{  
    public: 
    int data;  
    Node *next, *prev;  
};  

Node *split(Node *head);  
Node *merge(Node *first, Node *second)  
{  

    if (!first)  
        return second;  

       if (!second)  
        return first;  


    if (first->data < second->data)  
    {  
        first->next = merge(first->next,second);  
        first->next->prev = first;  
        first->prev = NULL;  
        return first;  
    }  
    else
    {  
        second->next = merge(first,second->next);  
        second->next->prev = second;  
        second->prev = NULL;  
        return second;  
    }  
}
Node *mergeSort(Node *head)  
{  
    if (!head || !head->next)  
        return head;  
    Node *second = split(head);  

     head = mergeSort(head);  
    second = mergeSort(second);  

    return merge(head,second);  
}  
void insert(Node **head, int data)  
{  
    Node *temp = new Node(); 
    temp->data = data;  
    temp->next = temp->prev = NULL;  
    if (!(*head))  
        (*head) = temp;  
    else
    {  
        temp->next = *head;  
        (*head)->prev = temp;  
        (*head) = temp;  
    }  
}  
void print(Node *head)  
{  
    Node *temp = head;  
    cout<<"Forward Traversal using next poitner\n";  
    while (head)  
    {  
        cout << head->data << " ";  
        temp = head;  
        head = head->next;  
    }  
    cout  << "\nBackward Traversal using prev pointer\n";  
    while (temp)  
    {  
        cout << temp->data << " ";  
        temp = temp->prev;  
    }  
}  
void swap(int *A, int *B)  
{  
    int temp = *A;  
    *A = *B;  
    *B = temp;  
} 
Node *split(Node *head)  
{  
    Node *fast = head,*slow = head;  
    while (fast->next && fast->next->next)  
    {  
        fast = fast->next->next;  
        slow = slow->next;  
    }  
    Node *temp = slow->next;  
    slow->next = NULL;  
    return temp;  
}  
int main(void)  
{  
    Node *head = NULL;  
    insert(&head, 7);  
    insert(&head, 40);  
    insert(&head, 2);  
    insert(&head, 1);  
    insert(&head, 20);  
    insert(&head, 10);  
    head = mergeSort(head);  
    cout << "Linked List after sorting\n";  
    print(head);  
    return 0;  
} 

//Input format:
//Enter the values for the nodes of the doubly linked list.

//Output format:
//Merge sort on the doubly linked list.

//Sample Input Format:
//7,40,2,1,20,10

//Sample Output Format:
//Linked List after sorting
//Forward Traversal using next pointer
//1 2 7 10 20 40
//Backward Traversal using prev pointer
//40 20 10 7 2 1
