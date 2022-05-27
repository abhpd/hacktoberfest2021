#include<stdio.h>
#include<limits.h>
//sorting of burst time and arrival time
int sort(int *FB,int *FA,int n,int *CB,int *DA,int *P,int *FP,int in)
{
    int i;
    int min=INT_MAX;int cha=1;
    for(i=1;i<n;i++)
    {
        if(FB[i]<min)
        {
             
            cha=i;
            min=FB[i];
        }
    }
    CB[in]=min;
    FB[cha]=INT_MAX;
    DA[in]=FA[cha];
    FP[in]=P[cha];
    return 0;
}

void main()
{
    int i;int n;
    printf("Enter no of process : ");
    scanf("%d",&n);
    
    int B[10];int FB[10];int P[10];
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d : ",i+1);
        scanf("%d",&B[i]);
    }
    printf("\n");
    int A[10];int FA[10];
    for(i=0;i<n;i++)
    {
        printf("Enter the Arrival time of process %d : ",i+1);
        scanf("%d",&A[i]);
    }
    printf("\n");
    int min=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
            FB[0]=B[i];
            P[0]=i+1;
        }
        
    }
    int GT[10],CB[10],DA[10];
    GT[0]=min;GT[1]=FB[0]+GT[0];FA[0]=min;
    CB[0]=FB[0];DA[0]=FA[0];int FP[10];FP[0]=P[0];
    int k=0;
    for(i=0;i<n;i++)
    {
       if(A[i]==GT[0])
       {
              
          continue;
          
       } 
       else{
              FA[k+1]=A[i];
              FB[k+1]=B[i]; 
              P[k+1]=i+1;
              k++;
              
       }    
    }
    
    
    for(i=1;i<=n;i++)
    {
        sort(FB,FA,n,CB,DA,P,FP,i);
    }
    
    int sum=GT[1];
    for(i=1;i<=n;i++)
    {
        
       sum+=CB[i];
       GT[i+1]=sum;
        
    }
    int j;int in=0;
    int CT[10];int TT[10];int W[10];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(FP[j]==i+1)
            {
                CT[in]=GT[j+1];
                TT[in]=CT[in]-DA[j];
                W[in]=TT[in]-CB[j];
                in++;
                break;
            }
        }
        
    }
    int Waitingtime_avg=0;
    int turnaroundtime_avg=0;
    for(i=0;i<n;i++)
    {
        printf("Waiting time for Process%d is: %d\n",i+1,W[i]);
        Waitingtime_avg+=W[i];
    }
    printf("\n");
    printf("\nAverage waiting time is: %2f \n",(float)Waitingtime_avg/n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Turnaround time for Process%d is: %d\n",i+1,TT[i]);
        turnaroundtime_avg+=TT[i];
    }
    printf("\nAverage turn around time is: %2f ",(float)turnaroundtime_avg/n);
}