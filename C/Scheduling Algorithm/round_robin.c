//round robin

#include <stdio.h>

int main() {

int i,n,qt,count=0,sq=0,bt[20],wt[20],tat[20],rem_bt[20],temp;

float awt,atat;

printf("enter the number of process\n");

scanf("%d",&n);

printf("enter the burst time\n");

for(i=0;i<n;i++){

scanf("%d",&bt[i]);

rem_bt[i]=bt[i];

 }

 printf("Enter the quantum time\n");

 scanf("%d",&qt);

 while(1) 

 {

   for(i=0;i<n;i++) {

     if(rem_bt[i]==0){

     count++;

     continue;

 }

 if (rem_bt[i]>qt)

   rem_bt[i]=rem_bt[i]-qt;

   else 

   if(rem_bt[i]>=0)

   {

temp=rem_bt[i];

rem_bt[i]=0;

   }

   sq=sq+temp;

   tat[i]=sq;

   }

   if(n==count)

   break;

 }

 printf("\n process\t\tburst time\t\t wt\t\t tat\t\t");

 for(i=0;i<n;i++){

 wt[i]=tat[i]-bt[i];

 awt=awt+wt[i];

 atat=atat+tat[i];

 printf("\n %d\t\t%d\t\t%d\t\t%d\t\t",i+1,bt[i],wt[i],tat[i]);

 }

 awt=awt/n;

 atat=atat/n;

 printf("awt=%f\n",awt);

  printf("atat=%f",atat);

}
