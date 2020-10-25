/*Implementation of Radix sort via queue in C. 
	This implementation works with integers*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_BUCKETS 10
typedef int TYPE;
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

int find_max_significant(TYPE [], int);
void radix_sort(TYPE [], int);
void print_array(TYPE [], int);

int main(){
	puts("-----Radix Sort-----");
	TYPE a[] = {9, 179, 139, 38, 10, 5, 36};
	int length = sizeof(a) / sizeof(TYPE);
	
	printf("Unsorted: ");
	print_array(a, length);
	radix_sort(a, length);
	
	printf("Sorted: ");
	print_array(a, length);
	
	return EXIT_SUCCESS;
}

void radix_sort(TYPE a[], int length){
	QUEUE buckets[MAX_BUCKETS]; // buckets for 0, 1, 2, ... 9 significant digits
	int i, j;
	for(i = 0; i < MAX_BUCKETS; i++)
		init_queue(&buckets[i]);
	
	int k = find_max_significant(a, length);
	int m = 10, n = 1, p;
	
	for(i = 0; i < k; i++){
		for(j = 0; j < length; j++){
			inqueue(&buckets[((int)a[j]%m)/n], a[j]);
		}
		for(p = 0, j = 0; j < MAX_BUCKETS; j++){
			while(!is_empty(buckets[j])) {
				a[p++] = dequeue(&buckets[j]); 
				//first a[p] = ... is done and then p++ afterwards.
			}
		}
		n*=10;
		m*=10;
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
int find_max_significant(TYPE a[], int length){
	int i = 0; 
	TYPE max = a[0];
	
	while(++i < length) {
		if(a[i] > max) max = a[i];
	}
	int nb_digits = 0;
	while(max != 0) {
		++nb_digits;
		max = (int)max / 10;
	}
	return nb_digits;
}

void print_array(TYPE a[], int length){
	int i = 0;
	putchar('[');
	do {
		if(i > 0) printf(", ");
		printf("%d", a[i]); 
	} while(++i < length);
	puts("]");
}
