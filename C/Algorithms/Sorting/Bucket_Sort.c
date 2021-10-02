#include<stdio.h>
void Bucket_Sort(int array[], int n) 
{
	int i, j;
	int count[n];
	for (i=0; i < n; i++)
   {
		count[i] = 0;
	}
	for (i=0; i < n; i++) 
  {
		(count[array[i]])++;
	}
	for (i=0,j=0; i < n; i++) 
  {
		for (; count[i]>0;(count[i])--)
     {
			array[j++] = i;
		}
	}
}
int main()
 {
	int array[100];
	int num;
	int i;
	printf("Enter How many Numbers : ");
	scanf("%d",&num);
	printf("Enter the %d elements to be sorted:\n",num);
	for (i = 0; i < num; i++ )
   {
		scanf("%d",&array[i]);
	}
	printf("\nThe array of elements before sorting : \n");
	for (i = 0;i < num;i++)
   {
		printf("%d ", array[i]);
	}
	printf("\nThe array of elements after sorting : \n");
	Bucket_Sort(array, num);
	for (i = 0;i < n;i++) 
  {
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}