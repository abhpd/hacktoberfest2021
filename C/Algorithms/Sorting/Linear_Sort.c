#include<stdio.h>
int main()
{
int numberArray[10];
int e,f,y,g;
y=0;
while(y<=9)
{
printf("Enter the number:");
scanf("%d",&numberArray[y]);
fflush(stdin);
y++;
}
e=0;
while(e<=8)
{
f=e+1;
while(f<=9)
{
if(numberArray[f]<numberArray[e])
{
g=numberArray[e];
numberArray[e]=numberArray[f];
numberArray[f]=g;
}
f++;
}
e++;
}
y=0;
while(y<=9)
{
printf("%d\n",numberArray[y]);
y++;
}
return 0;
}