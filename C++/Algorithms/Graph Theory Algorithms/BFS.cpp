#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
int queue[MAX_SIZE];
int rear = -1;
int front = 0;
void enqueue(int y)
{
    rear++;
    queue[rear] = y;
}
int dequeue()
{
    int item;
    if (front == rear)
    {
        item = queue[front];
        front = -1;
        rear = -1;
    }
    else
    {
        item = queue[front];
        front++;
    }
    return item;
}
void push(int x)
{
    top++;
    stack[top] = x;
}
int pop()
{
    int item;
    item = stack[top];
    top--;
    return item;
}
int isempty1()
{
    if (top == -1)
        return 0;
    else
        return 1;
}
int isempty2()
{
    if (rear == -1 && front == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void BFS(int G[MAX_SIZE][MAX_SIZE], int n)
{
    int s = 1;
    int visited[MAX_SIZE], i, j;
    int v;
    enqueue(s);
    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
    while (isempty2())
    {
        v = dequeue();
        if (!visited[v])
        {
            visited[v] = 1;
            printf("%d -> ", v);
            for (j = 1; j <= n; j++)
            {
                if (G[v][j] != 0 && !visited[j])
                {
                    enqueue(j);
                }
            }
        }
    }
}
int main()
{
    int G[MAX_SIZE][MAX_SIZE], i, j, n;
    printf("Enter no of Nodes\n");
    scanf("%d", &n);
    printf("Enter Adjecency Matrix  : \n");
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d", &G[i][j]);
        }
    }
   
   
    printf("\n BFS : \n  ");
    BFS(G, n);
    getch();
    return 0;
}
