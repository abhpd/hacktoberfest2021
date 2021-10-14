#include<stdio.h>
#include<string.h>
#define MAX 10
struct process
{
	char pname[10];
	int at,bt,wt,tt,status,priority;
}p[10],t;


int main() {
	int i,j,n,time_elapsed = 0.0;
	float sumWT = 0.0,sumTT = 0.0;
	//getting inputs
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the process name : ");
		__fpurge(stdin);
		fgets(p[i].pname,MAX,stdin);
		
		//removing the trailing new line
		p[i].pname[strcspn(p[i].pname, "\n")] = 0;
	
		printf("\nEnter the arrival time : ");
		scanf("%d",&p[i].at);
		printf("\nEnter the burst time : ");
		scanf("%d",&p[i].bt);
		printf("\nEnter the prority : ");
		scanf("%d",&p[i].priority);
		p[i].status = 0;
		p[i].wt = 0;
		p[i].tt = 0;
	}
	//sorting the process according to the arrival time
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].at > p[j].at)
			{
				t=p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	//executing process
	i=0;
	while(i<n)
	{
	
		if(time_elapsed >= p[i].at)
		{
			
			j = 0;
			
			while(j<n)
			{
				if(time_elapsed >= p[j].at)
				{
						
					if(p[j].status == 0 && p[j].priority < p[i].priority)
					{
						
						t=p[i];
						p[i] = p[j];
						p[j] = t; 
					}
						
				}
				else
					break;
				j++;
			}
		
			time_elapsed += p[i].bt;
			p[i].tt = time_elapsed - p[i].at;
			p[i].wt = p[i].tt - p[i].bt;
			sumWT += p[i].wt;
			sumTT += p[i].tt;
			p[i].status = 1;
			
			i++;
			}
			else
				time_elapsed += p[i].at - time_elapsed;
	
		
	}
	
	
	printf("| pname\t| arrival time\t| burst time\t| priority\t| status\t| wait\t| turn");
	
	for(i=0;i<n;i++)
	{
		printf("\n\n| %s\t| %d\t\t| %d\t\t| %d\t\t| %d\t\t| %d\t| %d",p[i].pname,p[i].at,p[i].bt,p[i].priority,p[i].status,p[i].wt,p[i].tt);
	}
	//Gantt chart
	
	printf("\n\nGantt Chart");
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
	i =0;
	time_elapsed = 0;
	while(i<n)
	{
		if(time_elapsed >= p[i].at)
		{
			printf("|%s\t",p[i].pname);
			time_elapsed += p[i].bt;
			i++;
		}
		else
		{
			printf("|ideal\t");
			time_elapsed += p[i].at - time_elapsed;
		}
	}
	printf("|\t");
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------------\n");
	time_elapsed = 0;
	i=0;
	while(i<n)
	{
		if(time_elapsed >= p[i].at)
		{
			printf("|%d\t",time_elapsed);
			time_elapsed += p[i].bt;
			i++;
		}
		else
		{
			printf("|%d\t",time_elapsed);
			time_elapsed += p[i].at - time_elapsed;
		}
	}
	printf("|%d\t",time_elapsed);
	printf("\n\nAverage Turn Around Time : %f",sumTT/n);
	printf("\n\nAverage Waiting Time : %f",sumWT/n);
	return 0;
}
