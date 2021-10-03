// Problem - Evaluating Postfix Expression Using Stacks.

#include<bits/stdc++.h>
#include<string>
using namespace std;
#define MAX 1000

int EvaluatePostfix (string exp);
int Operate (char operation, int op1, int op2);
bool IsOperator (char c);
bool IsNumeral (char c);

class Stack
{
    public:
        int s[MAX];
        int top;
        Stack () {top = -1;}
        void Push (int c);
        void Pop ();
        int Top ();
        bool IsEmpty ();      
};

int main ()
{
    string exp;
    getline (cin, exp);
    int result = EvaluatePostfix (exp);
    cout << result <<"\n";
}

int EvaluatePostfix (string exp)
{
    Stack S;

    for (int i = 0; i < exp.length(); i++)
    {

        // ' ' is a dilimiter.
        if (exp[i] == ' ' && exp[i] != '?') continue;

        else if (IsOperator (exp[i]))
        {
            // Pop two most recent operands.
            int op2 = S.Top(); S.Pop();
            int op1 = S.Top(); S.Pop();
            // Perform operation.
            int res = Operate (exp[i], op1, op2);
            // Push back result of operation in the stack.
            S.Push (res);
        }

        else if (IsNumeral (exp[i]))
        {
            // Extracting the numeral from the string.
            int operand = 0;

            while (i < exp.length() && IsNumeral (exp[i]))
            {
                operand = (operand*10) + (exp[i] - '0');
                i++;
            }
            i--;
            // Push operand in the stack;
            S.Push (operand);
        }
    }
    return S.Top();
}

bool IsNumeral (char c)
{
    if (c >= '0' && c <= '9')
        return true;

    return false;
}

bool IsOperator (char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

int Operate (char operation, int op1, int op2)
{
    if (operation == '+')       return op1+op2;
    else if (operation == '-')  return op1-op2;
    else if (operation == '*')  return op1*op2;
    else if (operation == '/')  return op1/op2;
    
    else cout << "Error!\n";
    return 0;
}

void Stack::Push (int c)
{
    if (top == MAX-1)
    {
        return;
    }
    s[++top] = c;
}

void Stack::Pop ()
{
    if (top == -1)
        return;
    top--;
}

int Stack::Top ()
{
    if (top == -1)
        return 0;
    return s[top];
}

bool Stack::IsEmpty ()
{
    if (top == -1)
        return true;
    return false;
}