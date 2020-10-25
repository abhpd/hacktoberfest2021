/*Implementation of Bucket sort (for double in range: 0 <= A[i] < 1) via queue in C*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUCKETS 10
typedef double TYPE;
typedef struct node_st { 
	TYPE inf;
	struct node_st *pnext;
} NODE;
typedef struct queue_st {
	NODE *pbegin, *pend;
} QUEUE;

void init_queue(QUEUE *);
NODE *make_node(TYPE);
void inqueue(QUEUE *, TYPE );
TYPE dequeue(QUEUE *);
int is_empty(QUEUE);

void bucket_sort(TYPE [], int);
void insertion_sort(TYPE a[], int length);
void print_array(TYPE [], int);

int main(){
	puts("-----Bucket Sort-----");
	TYPE a[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
	int length = sizeof(a) / sizeof(TYPE);
	
	printf("Unsorted: ");
	print_array(a, length);
	bucket_sort(a, length);
	
	printf("Sorted: ");
	print_array(a, length);
	
	return EXIT_SUCCESS;
}

void bucket_sort(TYPE a[], int length){
	int i, j;
	QUEUE buckets[MAX_BUCKETS];
	
	for(i = 0; i < MAX_BUCKETS; i++)
		init_queue(&buckets[i]);
	
	for(i = 0; i < length; i++) {
		inqueue(&buckets[(int)(a[i] * 10)], a[i]);
	}
	
	TYPE temp[length];
	int n, k;
	for(i = 0, j = 0; i < MAX_BUCKETS; i++) {
		n = 0;
		while(!is_empty(buckets[i])){
			temp[n++] = dequeue(&buckets[i]);
		}
		insertion_sort(temp, n);
		for(k = 0; k < n && j < length; k++) {
			a[j++] = temp[k];
		}
	}
	
}
void insertion_sort(TYPE a[], int length) {
	int i, j;
	TYPE temp;
	for(i = 1; i < length; i++) {
		temp = a[i];
		j = i;
		while(j > 0 && a[j-1] > temp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}
void init_queue(QUEUE *pque){
	pque->pbegin = pque->pend = NULL;
} 
NODE *make_node(TYPE inf){
	NODE *pnew = malloc(sizeof(NODE));
	if(pnew == NULL){
		puts("ERROR: Out of RAM!");
		exit(4);
	}
	pnew->inf = inf;
	pnew->pnext = NULL;
	return pnew;
}
void inqueue(QUEUE *pque, TYPE inf){
	NODE *pnew = make_node(inf);
	
	/*This would mean that my queue is empty*/
	if(pque->pbegin == NULL) {
		pque->pbegin = pque->pend = pnew;
	}
	else {
		pque->pend->pnext = pnew;
		pque->pend = pnew;
	}
}
TYPE dequeue(QUEUE *pque) {
	NODE *ptemp = pque->pbegin;	
	if(ptemp == NULL) {
		puts("ERROR: You tried to dequeue an empty queue.");
		exit(5);
	}
	TYPE x;
	
	/*If below means that they are on last element (ex. pbegin--- 36 
																								/
																							pend    )*/
	if(pque->pbegin == pque->pend) pque->pend = pque->pbegin = NULL;
	else pque->pbegin = ptemp->pnext;
	x = ptemp->inf;
	
	free(ptemp);
	return x;
	
}
/*returns 1 if it is and 0 if it isn't*/
int is_empty(QUEUE pque) {
	if(pque.pbegin == NULL) return 1;
	else return 0;
}
void print_array(TYPE a[], int length){
	int i = 0;
	putchar('[');
	do {
		if(i > 0) printf(", ");
		printf("%.2lf", a[i]);
	} while(++i < length);
	puts("]");
}
