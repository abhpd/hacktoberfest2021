//Producer consumer in OS is a synchronization problem. 
//There is a fixed size buffer and the producer produces items and enters them into the buffer. 
//The consumer removes the items from the buffer and consumes them.
#include<stdio.h>
#include<stdlib.h>
int mutex=1, full=0, empty=3, x=0;
void producer();
void consumer();
int wait(int);
int signal(int);
int main()
{
int n;
while(n!=0)
{
printf("\n1. Producer\n2. Consumer\n3. Exit\n");
printf("Enter Your Choice");
scanf("%d",&n);
switch(n)
{
case 1: if((mutex==1)&&(empty!=0))
		{
		producer();
		}
		else
		{
		printf("Buffer is Full\n");
		}
		break;
case 2: if((mutex==1)&&(full!=0))
		{
		consumer();
		}
		else
		{
		printf("Buffer is Empty\n");
		}
		break;
case 3: exit(0);
		break;
		}
}
}

int wait(int s)
{
return(--s);
}

int signal(int s)
{
signal(s++);
}

void producer()
{
mutex=wait(mutex);
full=signal(full);
empty=wait(empty);
x++;
printf("\nProducer produce item : %d",x);
mutex=singnal(mutex);
}

void consumer()
{
mutex=wait(mutex);
full=wait(full);
empty=signal(empty);
printf("\nConsumer consume item : %d",x);
mutex=signal(mutex);
}