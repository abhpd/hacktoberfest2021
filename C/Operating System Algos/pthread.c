//Thread is light weight, taking lesser resources than a process. 
//Process switching needs interaction with operating system. 
//Thread switching does not need to interact with operating system. 
//In multiple processing environments, each process executes the same code but has its own memory and file resources.
#include<pthread.h>
#include<sys/types.h>
#include<stdio.h>
int sum=0;
void *runner(void *param);
main()
{
    int pid;
    pthread_t tid;
    pid = fork();
    
    if(pid==0)
    {
        pthread_create(&tid,NULL,runner,10);
        pthread_join(tid,NULL);
        printf("Child Sum = %d ",sum);
    }
    else
    {
        wait(NULL);
        print("Parent Sum = %d",sum);
    }
}
void *runner(void *param)
{
    int i;
    for(i=1;i<=param;i++)
    {
        sum=sum+i;
    }
}