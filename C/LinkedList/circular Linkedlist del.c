#include <stdio.h>
#include <stdlib.h>

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

struct node * delFirst(struct node* head ){
    struct node* ptr = head;
    struct node* p = head;   
    do{
        ptr = ptr->next;
    }while(ptr->next!= head);
    head = head->next;
    ptr->next = head;

    free(p);
    return head;
}

void delIndex(struct node * head, int index){
    struct node * p = head;
    int i = 0;
    while (i != index-1){
        i++;
        p = p->next;
    }
    struct node * q = p->next;
    p->next = q->next;
    free(q);
    // return head;
}
void delData(struct node * head, int value){
    struct node * p = head;
    struct node * q = head->next;
    int i = 0;
    while (q->data != value && q->next != head){
        i++;
        p = p->next;
    }
    if (q->data == value){
        struct node * q = p->next;
        p->next = q->next;
        free(q);
    }
  
    // return head;
}

struct node * delLast(struct node * head){
    struct node * p = head;
    struct node * q = p->next;
    while (q->next !=head){
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
    return head;

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
    printf("After deletion\n");
    // head = delFirst(head);
    // head =  delLast(head);
    // delIndex(head , 2);
    delData(head ,10);
    display(head);
}