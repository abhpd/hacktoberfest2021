//pop function of stack


void pop()
{
    if(top==-1)
    {
        printf("\nUnderflow");
    }
    else{
    printf("\nThe deleted element in the stack is :%d",stack[top]);
    top--;
    }
}
