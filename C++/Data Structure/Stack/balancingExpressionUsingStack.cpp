#include <iostream>
#define max 50
int main(){
    char stack[100], exp[100];
    int top,i;
    top = -1;
    printf("\n Enter an infix expression ");
    gets(exp);
    for(i=0;exp[i]!='\0';i++){
        if (exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            top++;
            stack[top] = exp[i];
        } else if (exp[i]==')') { 
            if (stack[top]=='('){
                top--;
            } else {
                printf("Unbalanced Expression");
                exit(0);
            }
        } else if (exp[i]==']') { 
            if (stack[top]=='{'){
                top--;
            } else {
                printf("Unbalanced Expression");
                exit(0);
            }
        } else if (exp[i]=='}') { 
            if (stack[top]=='{'){
                top--;
            } else {
                printf("Unbalanced Expression");
                exit(0);
            }
        } 
    }
    if (top==-1)
        printf("Expression is balanced.");
    else
        printf("Expression is not balanced");
    

}