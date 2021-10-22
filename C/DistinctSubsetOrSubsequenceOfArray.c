#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n,a[20],sum,b[20],c=1,z,k;
	unsigned int size;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	//n=sizeof(a)/sizeof(a[0]);
	size=pow(2,n);
	b[0]=0;
	printf("\n");
	for(i=1;i<size;i++)
	{
		sum=0;
		for(j=0;j<n;j++)
		{
			if(i & (1<<j))
			{
				printf("%d ",a[j]);
				sum=sum+a[j];
			}
		}
		printf("\n");
		b[c++]=sum;
	}
	printf("\n");
	for(i=0;i<c;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
	for(i=0;i<c;i++)
	{
		for(j=i+1;j<c;j++)
		{
		  if(b[i]==b[j])
		  {
			for(k=j+1;k<c;k++)
			{
				b[k-1]=b[k];
			}
				j--;
				c--;
			
		  }
	    } 
    }
	for(i=0;i<c;i++)
	{
		printf("%d ",b[i]);
	}
	
}
