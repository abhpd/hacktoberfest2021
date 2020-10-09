#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct fcfs
{
    int processno;   //Process Number
    int processID;  //Randomly generated Process ID
    int burst;      //Burst Time
    int arrival;    //Arrival Time
    int tat;        //Turn Around Time
    int wt;         //Waiting Time
}fcfs;

int sort(fcfs [], int);

int main()
{
    int n, i, temp = 0, AvTat = 0, AvWt = 0;
    int option;
    printf ("Enter the number of processes: ");
    scanf ("%d", &n);
    fcfs arr[n];    //Array of type fcfs
    int tct[n];
    printf("AutoSelect zero for Arrival Time \nYes=>1\nNo =>0\n");
    scanf("%d",&option);
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        arr[i].processno = i;
        arr[i].processID = rand();
        printf ("Enter the process %d data\n", arr[i].processno);
        printf ("Enter CPU Burst: ");
        scanf ("%d", &(arr[i].burst));
        if(option == 0){
        printf ("Enter the arrival time: ");
        scanf ("%d", &(arr[i].arrival));}
        else{
            arr[i].arrival = 0;
        }
    }
    
    //Sorting the processes according to their arrival time
    sort(arr, n);

    printf ("Process\t\tProcessID\t\tBurst Time\tArrival Time\tTurn Around Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        tct[i] = temp + arr[i].burst;
        temp = tct[i];
        arr[i].tat = tct[i] - arr[i].arrival;
        arr[i].wt = arr[i].tat - arr[i].burst;
        AvTat = AvTat + arr[i].tat;
        AvWt = AvWt + arr[i].wt;
        printf ("%5d\t\t%5d\t%15d\t\t%9d\t%12d\t%12d\n", arr[i].processno,arr[i].processID,arr[i].burst, arr[i].arrival, arr[i].tat, arr[i].wt);
    }

    printf ("Average Turn Around Time: %d\nAverage Waiting Time: %d\n", AvTat / n, AvWt / n);
    
    return 0;
}

//Bubble Sort
int sort(fcfs arr[], int n)
{
    int i, j;
    fcfs k;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            //Sorting the processes according to their arrival time
            if (arr[i].arrival > arr[j].arrival)
            {
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;
            }
        }
    }
    return 0;
}