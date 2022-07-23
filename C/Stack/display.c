//display function of stack



void display()
{
    int i;
    printf("\nThe elements present in stack are : ");
    for(i=top;i>=0;--i)
    printf("%d\t\t",stack[i]);
}
