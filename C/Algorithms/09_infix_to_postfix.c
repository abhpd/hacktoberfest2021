#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int is_empty(struct Stack *my_stack)
{
    if (my_stack->top == -1)
        return 1;
    return 0;
}

int is_full(struct Stack *my_stack)
{
    if (my_stack->top == my_stack->size - 1)
        return 1;
    return 0;
}

char peek(struct Stack *my_stack)
{
    return my_stack->arr[my_stack->top];
}

void push(struct Stack *my_stack, char data)
{
    if (is_full(my_stack))
        printf("STACK OVERFLOW!!\n");
    else
    {
        // my_stack->arr[++my_stack->top] = data;
        my_stack->top++;
        my_stack->arr[my_stack->top] = data;
    }
}

char pop(struct Stack *my_stack)
{
    if (is_empty(my_stack))
    {
        printf("STACK UNDERFLOW!!\n");
        return -1;
    }
    else
    {
        char value = my_stack->arr[my_stack->top];
        my_stack->top--;
        return value;
    }
}


int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}


int is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return 0;
}

char *infix_to_postfix(char *infix)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!is_operator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(peek(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!is_empty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    // char * infix = "a-b+t/c";
    char *infix = "a-b+t/6";
    printf("Postfix equivalent is: %s", infix_to_postfix(infix));

    return 0;
}
