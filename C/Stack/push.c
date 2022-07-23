//push function of stack

void push()
{
    if(top>=n-1)
    {
        printf("Overflow\n");
    }
    else{
    printf("Enter the value to be pushed in a stack = ");
    scanf("%d",&val);
    top++;
    stack[top]=val;
    }
}
