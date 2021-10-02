/* Program of reversing a string using stack */
#include<stdio.h>
#define MAX 20
#include<string.h>

int top = -1;
char stack[MAX];
char pop();
push(char);
main()
{
	char str[20];
	int i;
	printf("Enter the string : " );
	gets(str);
	/*Push characters of the string str on the stack */
	for(i=0;i<strlen(str);i++)
		push(str[i]);
	/*Pop characters from the stack and store in string str */
	for(i=0;i<strlen(str);i++)
		str[i]=pop();
	printf("Reversed string is : ");
	puts(str);
}/*End of main()*/

push(char item)
{
	if(top == (MAX-1))
		printf("Stack Overflow\n");
	else
		stack[++top] =item;
}/*End of push()*/

char pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
		return stack[top--];
}/*End of pop()*/

