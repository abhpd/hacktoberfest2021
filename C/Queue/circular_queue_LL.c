#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *next;
};
struct queue{
  struct node *front;
  struct node *rear;
};

  void enqueue(struct queue *q){
  struct node *n=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter data for node\n");
  scanf("%d",&n->data);
  if(q->front==NULL){
    q->front=n;
  }
  else{
    q->rear->next=n;
  }
  q->rear=n;
  q->rear->next=q->front;
}
void dequeue(struct queue *q){
  if(q->front==NULL){
    printf("\nQueue is empty\n");
  }
  else if(q->front==q->rear){
    printf("\nDeleted element=%d\n",q->front->data);
    q->front=NULL;
    q->rear=NULL;
  }
  else{
    printf("\nDeleted element=%d\n",q->front->data);
    struct node *temp=q->front;
    q->front=q->front->next;
    q->rear->next=q->front;
    free(temp);
  }
}
void display(struct queue *q){
  printf("\n");
  struct node *temp=q->front;
  while(temp->next!=q->front){
    printf("%d ",temp->data);
    temp=temp->next;
  }
  printf("%d ",temp->data);
}
int main(){
  struct queue *p=(struct queue*)malloc(sizeof(struct queue));
  p->front=NULL;
  p->rear=NULL;
  printf("\nEnter i->insertion, d->deletion, p->print and q->quit\n");
  char ch;
  ch=getche();
  while (ch!='q') {
    switch(ch){
      case 'i': ;
      enqueue(p);
      break;
      case 'd': ;
      dequeue(p);
      break;
      case 'p': ;
      display(p);
      break;
      case 'q': ;
      break;
      default:
      printf("\n Wrong input\n");
      break;
    }
    /* code */
    printf("\n Enter i->insertion, d->deletion, p->print and q->quit\n");
    ch=getche();
  }
return 0;
}
