#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node * next;  //self refrencing structure
    
};

//func to traverse or display linked list
void display(struct node* head){
    struct node* ptr = head;
    do{
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }while(ptr!= head);
    
}

struct node * insertAtHead(struct node * head , int data){
    struct node * ptr = (struct node * ) malloc (sizeof(struct node));
    struct node * p = head;
    do{
        p = p->next;
    }while(p->next!= head);
    p->next = ptr;
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

void insertAtEnd(struct node * head , int data){
    struct node * ptr = (struct node * ) malloc (sizeof(struct node));
    struct node * p = head;
    do{
        p = p->next;
    }while(p->next!= head);
    p->next = ptr;
    ptr->data = data;
    ptr->next = head; 
}

void insertPrev(struct node * head ,struct node* prevNode,  int data){
    struct node * ptr = (struct node * ) malloc (sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next ;
    prevNode->next = ptr;

}
struct node * insertIndex(struct node * head, int index , int data){
    struct node * ptr = (struct node * ) malloc (sizeof(struct node));
    int i = 0;
    struct node * p = head;
    if (index == 0){
        // ptr->next = head;
        // ptr->data = data;
        // return ptr;
        return insertAtHead(head , data);
    }
    else {
        while (i!=index - 1){
            i++;
            p = p->next;

        }
        ptr->next = p->next;
        p->next= ptr;
        ptr->data = data;
        return head;
    }
}

void main(){
    struct node * head;
    struct node * second;    
    struct node * third;
    struct node * fourth;

    //now allocating memory for nodes in heap
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    //link head and second node
    head->data = 7;
    head->next = second;

    //link second node to third node
    second->data = 10;
    second->next = third;

    //ending the node by pointing third node to null
    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = head;
    display(head);
    printf("After insertion \n");
    // head = insertAtHead(head, 100);
    // insertAtEnd(head , 70);
    insertIndex(head, 2 , 80);

    display(head);
}