
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void insertBefore(struct Node** head_ref,
				struct Node* next_node, int new_data)
{
	if (next_node == NULL) {
		printf("the given next node cannot be NULL");
		return;
	}

	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->prev = next_node->prev;

	next_node->prev = new_node;

	new_node->next = next_node;

	if (new_node->prev != NULL)
		new_node->prev->next = new_node;

	else
		(*head_ref) = new_node;
}

void printList(struct Node* node)
{
	struct Node* last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->prev;
	}
}

int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;
	push(&head, 7);

	push(&head, 1);

	push(&head, 4);

	// Insert 8, before 1. So linked list becomes
	// 4->8->1->7->NULL
	insertBefore(&head, head->next, 8);

	printf("Created DLL is: ");
	printList(head);

	getchar();
	return 0;
}
