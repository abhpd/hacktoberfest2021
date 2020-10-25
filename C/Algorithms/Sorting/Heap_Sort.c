/*Heap sort implementation in C*/
#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
int left(int);
int right(int); 
int parent(int);
void max_heapify(TYPE [], int, int);
void build_max_heap(TYPE [], int);
void heap_sort(TYPE [], int);
void print_array(TYPE [], int);

int main(){
	puts("-----Heap Sort-----");
	TYPE a[] = {4, 10, 3, 5, 1};
	int length = sizeof(a) / sizeof(TYPE);
	
	printf("Unsorted: ");
	print_array(a, length);
	heap_sort(a, length);
	
	printf("Sorted: ");
	print_array(a, length);
	
	return EXIT_SUCCESS;
}
void heap_sort(TYPE a[], int length){
	build_max_heap(a, length);
	int i = length - 1;
	do {
		TYPE temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		
		max_heapify(a, 0, --length);
	} while(--i >= 0);
}
void build_max_heap(TYPE a[], int length){
	int i = length/2;
	do {
		max_heapify(a, i, length);
	}while(--i  >= 0); //first i = i - 1 is doen and then i >= 0 afterwards.
}
void max_heapify(TYPE a[], int i, int length){
	int r = right(i);
	int l = left(i);
	int max = i;
	if(l < length && a[max] < a[l]) max = l;
	if(r < length && a[max] < a[r]) max = r;
	if(max != i) {
		TYPE temp = a[i];
		a[i] = a[max];
		a[max] = temp;
		max_heapify(a, max, length);
	}
}
int left(int i) {
	return 2*i + 1;
}
int right(int i) {
	return 2*i + 2;
}
int parent(int i) {
	return (i - 1)/2;
}
void print_array(TYPE a[], int length){
	int i = 0;
	putchar('[');
	while(i < length);
		if(i > 0) printf(", ");
		printf("%d", a[i++]); 
	} 
	puts("]");
}