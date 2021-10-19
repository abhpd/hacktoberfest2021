#include <stdio.h>
#include <string.h>
#define MAX 126
int t[MAX];
int max (int a, int b)
{
return (a > b)? a: b;
}
void shifttable (char p[])
{
int i,j,m;
m = strlen(p);
for (i=0;i<MAX;i++)
t[i] = m;
for (j=0;j<m-1;j++)
t[p[j]] = m-1-j;
}
int boyermoore (char src[],char p[])
{
int i,k,m,n;
n = strlen(src);
m = strlen(p);
printf ("Length of Text = %d\n",n);
printf ("Length of Pattern = %d\n",m);
i = m-1;
while (i<n)
{
k = 0;
while ((k<m) && (p[m-1-k] == src[i-k]))
k++;
if (k == m)
return (i-m+1);
else
i = i + max(t[src[i]]-k,1);
}
return -1;
}

int main ()
{
char src[100],p[100];
int pos;
printf ("Enter the Text in which Pattern is to be Searched\n");
gets (src);
printf ("Enter the Pattern to be Searched\n");
gets (p);
shifttable (p);
pos = boyermoore (src,p);
if (pos >= 0)
printf ("Pattern was found starting from position %d\n",pos+1);
else
printf ("Pattern was not found\n");
return 0;
}