#include <stdio.h>

typedef struct sjf
{
    int process;
    int burst;
    int arrival;
    int tat;
    int wt;
}sjf;

void sort(sjf [], int);

int main()
{
    int n, i, j, TCT, count_process = 0, count = 0, minBurst, pos;
    float AvTAT = 0.0, AvWT = 0.0;
    int option;
    printf ("Enter the number of processes: ");
    scanf ("%d", &n);
    sjf arr[n];
    printf("AutoSelect zero for Arrival Time \nYes=>1\nNo =>0\n");
    scanf("%d",&option);

    printf ("Enter the data of processes\n");
    for (i = 0; i < n; i++)
    {
        arr[i].process = i + 1;
        printf("Enter the burst time of process %d:", arr[i].process);
        scanf ("%d", &(arr[i].burst));
       if(option == 0){
        printf ("Enter the arrival time: ");
        scanf ("%d", &(arr[i].arrival));}
        else{
            arr[i].arrival = 0;
        }
    }

    sort (arr, n);
    printf ("PROCESS\tARRIVAL TIME\tBURST TIME\n");
    for (i = 0; i < n; i++)
        printf ("%3d\t%5d\t\t%5d\n", arr[i].process, arr[i].arrival, arr[i].burst);

    TCT = arr[0].tat = arr[0].burst;
    arr[0].wt = arr[0].tat - arr[0].burst;
    arr[0].arrival = -1;
    sort(arr, n);
    count_process = 1;

    while (count_process < n)
    {
        minBurst = 999;
        count = 0;
        i = count_process;

        while (TCT >= arr[i].arrival && i < n)
        {
            count++;
            i++;
        }

        for (j = i - count; count != 0 && j < n; j++, count--)
        {
            if (arr[j].burst < minBurst)
            {
                minBurst = arr[j].burst;
                pos = j;
            }
        }
        TCT = TCT + arr[pos].burst;
        arr[pos].tat = TCT - arr[pos].arrival;
        arr[pos].wt = arr[pos].tat - arr[pos].burst;
        arr[pos].arrival = -1;
        sort (arr, n);
        count_process++;
    }
    printf ("Process\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf ("%2d\t%2d\t%2d\n", arr[i].process, arr[i].tat, arr[i].wt);
    
    for (i = 0; i < n; i++)
    {
        AvTAT = AvTAT + arr[i].tat;
        AvWT = AvWT + arr[i].wt;
    }
    printf ("Average TAT: %.2f\nAverage WT: %.2f\n", AvTAT / n, AvWT / n);
    return 0;
}

void sort(sjf arr[], int n)
{
    int i, j;
    sjf temp;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i].arrival > arr[j].arrival)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}