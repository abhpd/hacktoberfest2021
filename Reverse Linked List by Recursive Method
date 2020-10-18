#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
}

void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;

	*head = newNode;
}

void recursiveReverse(struct Node* head, struct Node** headRef)
{
	struct Node* first;
	struct Node* rest;

		if (head == NULL)
	   return;

	first = head;		  
	rest = first->next;	

		if (rest == NULL)
	{
			*headRef = first;
		 return;
	}

		recursiveReverse(rest, headRef);

		rest->next = first;
	first->next = NULL;
}

void reverse(struct Node** head)
{
	recursiveReverse(*head, head);
}

int main(void)
{
		int keys[] = { 1, 2, 3, 4, 5, 6 };
	int n = sizeof(keys)/sizeof(keys[0]);

	struct Node *head = NULL;
	for (int i = n - 1; i >=0; i--)
		push(&head, keys[i]);

	reverse(&head);

	printList(head);

	return 0;
}

// Input Format:
//Enter the values to the nodes of the linked list.

//Output Format:
//Reverse of the linked list.

//Sample Input Format:
//1->2->3->4->NULL

//Sample Output Format:
//4->3->2->1->NULL
