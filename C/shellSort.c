/* Program of sorting using shell sort */
#include <stdio.h>
#define MAX 20

main()
{
	int arr[MAX], i,j,k,n,incr;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Unsorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\nEnter maximum increment (odd value) : ");
	scanf("%d",&incr);
	/*Shell sort*/
	while(incr>=1)
	{
		for(j=incr;j<n;j++)
		{
			k=arr[j];
			for(i = j-incr; i >= 0 && k < arr[i]; i = i-incr)
				arr[i+incr]=arr[i];
			arr[i+incr]=k;
		}
		printf("Increment=%d \n",incr);
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
		incr=incr-2; /*Decrease the increment*/
	}/*End of while*/
	printf("Sorted list is :\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}/*End of main()*/

