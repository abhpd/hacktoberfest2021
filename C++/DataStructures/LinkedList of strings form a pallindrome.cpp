#include <bits/stdc++.h> 
using namespace std; 
struct Node 
{ 
    string data; 
    Node* next; 
}; 
bool isPalindromeUtil(string str) 
{ 
    int length = str.length(); 
    for (int i=0; i<length/2; i++) 
        if (str[i] != str[length-i-1]) 
            return false; 

    return true; 
} 
bool isPalindrome(Node *node) 
{string str = ""; 
    while (node != NULL) 
    { 
        str.append(node->data); 
        node = node->next; 
    } 
     return isPalindromeUtil(str); 
} 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << " -> "; 
        node = node->next; 
    } 
    printf("NULL\n"); 
} 
  Node *newNode(const char *str) 
{ 
    Node *new_node = new Node; 
    new_node->data = str; 
    new_node->next = NULL; 
    return new_node; 
} 
int main() 
{ 
    Node *head = newNode("a"); 
    head->next = newNode("bc"); 
    head->next->next = newNode("d"); 
    head->next->next->next = newNode("dcb"); 
    head->next->next->next->next = newNode("a"); 

    isPalindrome(head)? printf("true\n"): 
                        printf("false\n"); 

    return 0; 
} 

//Input Format:
//Enter the values of the nodes of the linked list.

//Output Format:
//Whether the string in linked list is pallindrome or not.

//Sample Input Format:
//a -> bc -> d -> dcb -> a -> NULL

//Sample Output Format:
//True
//String "abcddcba" is palindrome.
