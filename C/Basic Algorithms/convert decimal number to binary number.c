#include <stdio.h>
#include <math.h>
void main()
{
    int i,s,k,b,n,x,y;
    x=y=s=b=0;
    printf("Enter a Decimal no:");
    scanf("%d",&n);
    for(i=n;i>0;i=i/2)
    {
        k=i%2;
        s=s*10+k;
        x++;
    }
    for(i=s;i>0;i=i/10)
    {
        k=i%10;
        b=b*10+k;
        y++;
    }
    b=b*pow(10,x-y);
    printf("Binary no. is %d",b);
}
