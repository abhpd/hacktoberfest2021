#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int count = 0;

typedef struct queue{
    int info;
    struct queue* next;
}QUEUE;

typedef struct LL{
    QUEUE* front;
    QUEUE* rear;
}LinkedList;

void initList(LinkedList* L){
    L->front = NULL;
    L->rear = NULL;
}

void push(LinkedList* L, int ele){
    QUEUE* temp = (QUEUE*)malloc(sizeof(QUEUE));

    temp->info = ele;
    temp->next = NULL;

    if(L->front == NULL && L->rear == NULL){
        L->front = temp;
        L->rear = temp;
    }

    else{
        L->rear->next = temp;
        L->rear = temp;
    }
    count++;
}

void pop(LinkedList* L){
    if(count == 0){
        printf("STACKUNDERFLOW \n");
        return;
    }
    if(L->front == NULL && L->rear == NULL){
        printf("QUEUEUNDERFLOW \n");
    }
    else{
        QUEUE* p = L->front;
        L->front = p->next;
        printf("POPED: %d \n", p->info);
        if(L->front == NULL){
            L->rear = NULL;
        }
        free(p);
    }
    count--;
}

void display(LinkedList* L){
    if(L->front == NULL){
        printf("EMPTY LIST. \n");
        return;
    }

    QUEUE* p = L->front;
    while(p!=NULL){
        printf("ELE: %d \n", p->info);
        p = p->next;
    }

}

int main(){
    LinkedList L;
    int choice,ele,pos;

    initList(&L);

    do{
        printf("1.  Push\n2.  Pop\n3.  Display Top\n4.  Display all \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(count == MAX){
                    printf("STACKOVERFLOW \n");
                    break;
                }
                printf("Enter Ele to enter:");
                scanf("%d", &ele);
                push(&L,ele);
                break;
            case 2:
                pop(&L);
                break;
            case 3:
                if(L.front == NULL){
                    printf("EMPTY LIST \n");
                    break;
                }
                printf("ELE: %d \n", L.front->info);
                break;
            case 4:
                display(&L);
                break;
        }
    }while(choice < 5);
    return 0;
}
