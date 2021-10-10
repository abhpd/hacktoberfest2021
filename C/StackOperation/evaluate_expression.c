// Usibg dynamic arrays to implement stack and evaluating
//postfix expressions.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct stack
{
	int top;
	unsigned capacity;
	int* arr;
};

struct stack* create(unsigned capacity)
{
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s->top = -1;
	s->capacity = capacity;
	s->arr = (int*)malloc(s->capacity * sizeof(int));
	return s;
}

int isEmpty(struct stack* s)
{
	return s->top == -1;
}

char peek(struct stack* s)
{
	return s->arr[s->top];
}

char pop(struct stack* s)
{
	if(!isEmpty(s))
		return s->arr[s->top--];

	return '$';
}

void push(struct stack* s, char op)
{
	s->arr[++s->top] = op;
}

int Eval(char* exp)
{
	struct stack* s = create(strlen(exp)); //allocating memory dynamically based on the size of the entered expression.
	int i;
	for(i=0; exp[i]; ++i)
	{
		if(isdigit(exp[i]))
			push(s, exp[i] - '0');

		else
		{
			int val1 = pop(s);
			int val2 = pop(s);
			switch(exp[i])
			{
				case '+': push(s, val2+val1);
									break;
				case '-': push(s, val2-val1);
									break;
				case '*': push(s, val2*val1);
									break;
				case '/': push(s, val2/val1);
									break;
				case '^': push(s, pow(val1, val2));
									break;
			}
		}	
	}
	return pop(s);
}

int main() {
  char exp[] = "231*+9-";
	printf("The postfix expression :%s\n", exp);
	printf("Sol :%d", Eval(exp));
  return 0;
}
