#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[1000],n;
    int i,start,end;
    //enter the size of an array
    scanf("%d",&n);
    //enter the elements of array
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
