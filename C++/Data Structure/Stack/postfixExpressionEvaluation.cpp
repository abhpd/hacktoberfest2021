#include<iostream>
using namespace std;

void push(int);
int pop();
bool isDigit(char);
bool isOperator(char);

int stack[100], numberToPush , i , j , top = -1;
string postfixExpression;

int main(){
    cout<<"Enter the POSTFIX expression: "<<endl;
    getline(cin, postfixExpression);
    for(i = 0 ; i<postfixExpression.length();i++){
        if(postfixExpression[i]==' '){
            continue;
        } else if(isDigit(postfixExpression[i])){
            int num = postfixExpression[i] - 48;
            push(num);
        } else if (isOperator(postfixExpression[i])){
            int a = pop();
            int b = pop();
            int ans;
            switch(postfixExpression[i]){
                case '+':
                    ans = b + a;
                    break;
                case '-':
                    ans = b - a;
                    break;
                case '*':
                    ans = b * a;
                    break;
                case '/':
                    ans = b / a;
                    break;
                case '^':
                    ans = b ^ a;
                    break;
                case '$':
                    ans = b ^ a;
                    break;
                default:
                    cout<<"Invalid Expression!"<<endl;
            }
            push(ans);
        }
    }
    int finalAnswer = pop();
    cout<<"Answer of postfix expression is: "<<finalAnswer<<endl;
}
void push(int num){
    top+=1;
    stack[top] = num;
}
int pop(){
    return stack[top--];
}
bool isDigit(char c){
    if(c>='0' && c<='9'){
        return true;
    } else {
        return false;
    }
}
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c=='$'){
        return true;
    } else {
        return false;
    }
}





