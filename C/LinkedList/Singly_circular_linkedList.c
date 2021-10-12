#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * tail = NULL;

void create(){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data \n");
    scanf("%d",&newNode->data);
    newNode->next = 0;

    if(tail == NULL){
        tail = newNode;
        tail->next = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = tail->next;
    }

}

void insert_beginning(){
    struct node * newNode;
    printf("Enter the data \n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;

    if(tail == NULL){
        tail = newNode;
        tail->next = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insert_end(){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data \n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;

    if(tail == NULL){
        tail = newNode;
        tail->next = newNode;
    }
    else{
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void delete_end(){
    struct node *prev,*temp;
    temp = tail->next;
    if(tail == NULL){
        printf("The list is empty \n");
        exit(0);
    }
    else if(tail->next == tail){
        tail == NULL;
        free(temp);
    }
    else{
        while(temp->next != tail->next){
            prev = temp;
            temp = temp->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(temp);
    }
}

void delete_beginning(){
    if(tail == NULL){
        printf("The list is empty \n");
    }
    else if(tail->next == tail){
        tail = NULL;
    }
    else{
        struct node *ptr,*temp;
        ptr = tail->next;
        temp = ptr;
        ptr = ptr->next;
        tail->next = ptr;
        free(temp);
    }
}

void display(){
    struct node * temp;
    temp = tail->next;
    while(temp != tail){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}

int main(){
    int choice;
    while(1){
        printf("Enter the choice : 1.Create  2.Insert Beginning  3.Insert End  4.Delete End  5. Delete Beginning  6. Display  -1. Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                create();
                break;
            case 2:
                insert_beginning();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                delete_end();
                break;
            case 5:
                delete_beginning();
                break;
            case 6:
                display();
                break;
            case -1:
                exit(0);
                break;
            default:
                printf("Invalid input \n");
        }
    }
    return 0;
}
