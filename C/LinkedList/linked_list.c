// 5. Practical : Linked List – 1
// Write a menu driven program to implement following operations on the singly linked list. Design a function create to create a link list (which is required to be called only for one time for a link list)
// (a) create [ node * create() ]
// (b) display [ void display(node *start) ]
// (c) length [ int length (node *start) ]
// (d) maximum [int maximum (node *start)]
// (e) merge (to merge two link list in to the third one) [node * merge(node *start1, node *start2)
// (f) sort [void sort(node *start) ]
// (g) reverse [ node * reverse (node *start)]
// (h) Insert a node at the front of the linked list. [ node * insert_front(node *start, int no) ]
// (i) Insert a node at the end of the linked list. [ node * insert_end(node *start, int no) ]
// (j) Insert a node such that linked list is in ascending order.(according to info. Field) [ node * insert_sort(node *start, int no) ]
// (k) Delete a first node of the linked list. [ node * delete_first(node *start) ]
// (l) Delete a node before specified position. [ node * delete_before(node *start, int pos) ]
// (m) Delete a node after specified position. [ node * delete_after(node *, int pos) ]
// (n) No search [ int search (node*, int x) ]

#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *link;
};

struct node *create();
void display(struct node *start);
int length (struct node *start);
int maximum (struct node *start);
struct node * merge(struct node *start1, struct node *start2);
void sort(struct node *start);
struct node * reverse (struct node *start);
struct node * insert_front(struct node *start, int no);
struct node * insert_end(struct node *start, int no);
struct node * insert_sort(struct node *start, int no);
struct node * delete_first(struct node *start);
struct node * delete_before(struct node *start, int pos);
struct node * delete_after(struct node *start, int pos);
int search (struct node *start, int x);

int isNull(struct node *start);
int isEmpty();
void push(int *stack, int *top, int value);
int pop(int *stack, int *top);

int main(){
    int operation, value, ans;
    struct node *head = NULL, *head1;
    printf("\n Ahmed Aghadi 200420107043\n");
    
    do{
        printf("\n****************************\n");
        printf("\nEnter operation value\n");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Length");
        printf("\n4. Maximum");
        printf("\n5. Merge");
        printf("\n6. Sort");
        printf("\n7. Reverse");
        printf("\n8. Insert at front");
        printf("\n9. insert at end");
        printf("\n10. Insert by sort");
        printf("\n11. Delete first");
        printf("\n12. Delete before");
        printf("\n13. Delete after");
        printf("\n14. Search");
        printf("\n15. Exit");
        printf("\n****************************\n");
        printf("Operation = ");
        scanf("%d",&operation);
        printf("\n");
        if(operation>1&&operation<15){
            if(isNull(head)){
                continue;
            }
        }
        switch(operation){
            case 1:
                head = create();
                break;
            case 2:
                display(head);
                break;
            case 3:
                ans = length(head);
                printf("Length = %d", ans);
                break;
            case 4:
                ans = maximum(head);
                printf("Maximum = %d", ans);
                break;
            case 5:
                printf("\nFor Second Linked List : \n");
                head1 = create();
                head = merge(head, head1);
                display(head);
                break;
            case 6:
                sort(head);
                break;
            case 7:
                head = reverse(head);
                display(head);
                break;
            case 8:
                printf("Enter value to be inserted : ");
                scanf("%d",&value);
                head = insert_front(head, value);
                break;
            case 9:
                printf("Enter value to be inserted : ");
                scanf("%d",&value);
                head = insert_end(head, value);
                break;
            case 10:
                printf("Enter value to be inserted : ");
                scanf("%d",&value);
                head = insert_sort(head, value);
                break;
            case 11:
                head = delete_first(head);
                break;
            case 12:
                printf("Enter position : ");
                scanf("%d",&value);
                head = delete_before(head,value);
                break;
            case 13:
                printf("Enter position : ");
                scanf("%d",&value);
                head = delete_after(head,value);
            case 14:
                printf("Enter value to be searched : ");
                scanf("%d",&value);
                ans = search(head, value);
                if(ans==-1){
                    printf("Value not found");
                    break;
                }
                printf("Value is found at position %d",ans);
                break;
            case 15:
                break;
            default:
                printf("\nEnter operation value between 1 and 15\n");
            
        }
    }while(operation!=15);
}

struct node *create(){
    int value;
    struct node *first;

    first = (struct node *)malloc(sizeof(struct node));
    if(first == NULL){
        printf("Memory not allocated");
    }

    printf("Enter value of first node : ");
    scanf("%d",&value);
    first->info = value;
    first->link = NULL;
    return first;
}


void display(struct node *start){
    while(start != NULL){
        printf("\n%d",start->info);
        start = start->link;
    }
}

int length (struct node *start){
    int len = 0;
    while(start!=NULL){
        len++;
        start=start->link;
    }
    return len;
}

int maximum (struct node *start){
    int max = start->info;
    start = start->link;
    while(start!=NULL){
        if(start->info>max){
            max = start->info;
        }
        start = start->link;
    }
    return max;
}

struct node * merge(struct node *start1, struct node *start2){
    struct node *first;

    first = (struct node *)malloc(sizeof(struct node));

    if(length(start1)==0){
        return start2;
    }

    if(length(start2)==0){
        return start1;
    }

    first = start1;
    while(start1->link!=NULL){
        start1 = start1->link;
    }
    start1->link = start2;

    return first;
}

void sort(struct node *start){
    int i,j,temp,len;
    struct node *current, *toCheck;
    len = length(start);
    current = start;
    for(i = 0; i< len-1; i++){
        toCheck = current->link;
        for(j = i+1; j < len; j++){
            if(toCheck->info<current->info){
                temp = toCheck->info;
                toCheck->info = current->info;
                current->info = temp;
            }
            toCheck = toCheck->link;
        }
        current = current->link;
    }
}

struct node * reverse (struct node *start){
    int *stack = (int*)calloc(length(start),sizeof(int)), top = 1, i = 0, j = 0;
    struct node *head = (struct node *)malloc(sizeof(struct node)), *temp;
    
    if(length(start)==1){
        head = start;
        return head;
    }

    while(start!=NULL){
        push(stack,&top,start->info);
        start = start->link;
    }

    // head->info = pop(stack,&top);
    temp = head;
    while(1){
        temp->info=pop(stack,&top);
        if(top>1){
            temp->link = (struct node *)malloc(sizeof(struct node));
            temp = temp->link;
        }
        else{
            temp->link = NULL;
            break;
        }
    }
    
    return head;
}

struct node * insert_front(struct node *start, int no){
    struct node *first;

    first = (struct node *)malloc(sizeof(struct node));
    if(first == NULL){
        printf("Memory not allocated");
    }

    first->info = no;
    first->link=start;
    return first;
}

struct node * insert_end(struct node *start, int no){
    struct node *temp = start, *end;

    end = (struct node *)malloc(sizeof(struct node));
    end->info = no;
    end->link = NULL;
    
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = end;

    return start;
}

struct node * insert_sort(struct node *start, int no){
    struct node *toAdd, *temp = start;
    toAdd = (struct node *)malloc(sizeof(struct node));
    toAdd->info = no;
    if(start->info>no){
        toAdd->link = start;
        return toAdd;
    }
    while(temp->link!=NULL){
        if(temp->link->info>no){
            toAdd->link = temp->link;
            temp->link= toAdd;
            return start;
        }
        temp = temp->link;
    }
    temp->link = toAdd;
    toAdd->link = NULL;
    return start;
}

struct node * delete_first(struct node *start){
    struct node *head = start->link;
    if(length(start)==1){
        printf("\nLength of Linked List is 1 and thus first element can't be deleted.\n");
        return start;
    }
    free(start);
    return head;
}

struct node * delete_before(struct node *start, int pos){
    struct node *temp = start, *toDelete = temp->link;
    if(pos<2||pos>length(start)+1||length(start)==1){
        printf("Invalid Position");
        return start;
    }
    while(pos-->3){
        temp = temp->link;
    }

    toDelete = temp->link;
    temp->link = toDelete->link;
    free(toDelete);
    return start;
}

struct node * delete_after(struct node *start, int pos){
    struct node *temp = start, *toDelete = temp->link;
    if(pos<1||pos>length(start)-1||length(start)==1){
        printf("Invalid Position");
        return start;
    }
    while(pos-->1){
        temp = temp->link;
    }

    toDelete = temp->link;
    temp->link = toDelete->link;
    free(toDelete);
    return start;
}

int search (struct node *start, int x){
    int i = 1;
    while(start!=NULL){
        if(start->info==x){
            return i;
        }
        start = start->link;
        i++;
    }
    return -1;
}

int isNull(struct node *start){
    if(start == NULL){
        printf("\nLinked List not created.\n");
        return 1;
    }
    return 0;
}

int isEmpty(int top){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push(int *stack, int *top, int value){

    (*top)++;
    stack[*top] = value;
}

int pop(int *stack, int *top){
    if(isEmpty(*top)){
        printf("Stack is Empty!");
        exit(0);
    }

    (*top)--;
    return stack[(*top)+1];
}