#include<stdio.h>
int main()
{
int numberArray[10];
int e,f,m,y,g;
y=0;
while(y<=9)
{
printf("Enter the number:");
scanf("%d",&numberArray[y]);
fflush(stdin);
y++;
}
m=9;
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
if(numberArray[e]<numberArray[f])
{
g=numberArray[e];
numberArray[e]=numberArray[f];
numberArray[f]=g;
}
e++;
f++;
}
m--;
}
y=0;
while(y<=9)
{
printf("%d\n",numberArray[y]);
y++;
}
return 0;
}