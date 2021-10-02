//fcfs Algorithm

#include<stdio.h>
#include<limits.h>
//soritng burst time and arrival time
int sort(int *B,int *A,int n,int *C,int *D,int *P,int in)
{
    int i;
    int max=INT_MAX;int cha;
    for(i=0;i<n;i++)
    {
        if(A[i]<max)
        {
            cha=i;
            max=A[i];
        }
    }
    C[in]=max;
    A[cha]=INT_MAX;
    D[in]=B[cha];
    P[in]=cha+1;
    return 0;
}

void main()
{
    int i;
    printf("Enter the number of process :");
    int n;
    // taking total number of process from user
    scanf("%d",&n);
    int A[10],B[10],C[10],D[10],P[10];
    //taking burst time and arrival time of each process from user
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of %d process :",i+1);
        scanf("%d",&B[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time of %d process :",i+1);
        scanf("%d",&A[i]);
    }
    //sorting burst time and arival time
    for(i=0;i<n;i++)
    {
        sort(B,A,n,C,D,P,i);
    }
    int GT[10];int sum=0; 
    for(i=0;i<=n;i++)
    {
        GT[i]=sum;
        sum+=D[i];
    }
    //calculating waiting time and turn arround time of each process
    int j;
    int in=0;int W[10];int TT[10];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(P[j]==i+1)
            {
                TT[in]=GT[j+1]-C[j];
                W[in]=GT[j]-C[j];
                in++;
                break;
            }
        }        
    } 
    int Waitingtime_avg=0;
    int turnaroundtime_avg=0;
    printf("\n");
    //calculating average waiting time and turn aroung time
    for(i=0;i<n;i++)
    {
        printf("Waiting time for Process%d is: %d\n",i+1,W[i]);
        Waitingtime_avg+=W[i];
    }
    printf("\n");
    printf("Average waiting is: %2f \n",(float)Waitingtime_avg/n);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("Turnaround time for Process%d is: %d\n",i+1,TT[i]);
        turnaroundtime_avg+=TT[i];
    }
   // printf("\nAverage waiting is: %2f ",(float)Waitingtime_avg/n);
    printf("\nAverage turn around time is: %2f ",(float)turnaroundtime_avg/n);
    
}