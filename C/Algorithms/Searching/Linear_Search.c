#include<stdio.h>
#include<stdlib.h>

int linearSearch(int a[], int n, int length);

void main()
{
    int length, i, find;
    printf("Linear Search\n");
    printf("How long of the array do you want it to be? >> ");
    scanf("%d", &length);
    
    int array[length];

    printf("Now you can enter the integers!\n");
    for ( i = 0; i < length; i++)
    {
    	printf("%d : ", i);
        scanf("%d", &array[i]);
    }
    
    printf("Now which number do you want to find? >> ");
    scanf("%d", &find);
    printf("%d is at %d", find, linearSearch(array, find, length));
}

int linearSearch(int a[], int n, int length)
{
    int i;
    for(i = 0; i<length; i++){
    	if(a[i] == n) return i;
	}
}
