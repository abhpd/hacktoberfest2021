#include <bits/stdc++.h>
using namespace std;
class sstack
{
private:
    int top;
    int a[5];

public:
    sstack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            a[i] = 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "overflow condition" << endl;
        }
        else
        {
            top++;
            a[top] = val;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow condition"
                 << endl;
        }
        else
        {
            cout << a[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            for (int i = 0; i <= top; i++)
            {
                cout << a[i] << endl;
            }
        }
    }
    void peep()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << a[top] << endl;
        }
    }

    void change(int pos, int val)
    {
        a[pos] = val;
        cout << "value has been changed" << endl;
    }

    void count()
    {
        cout << top + 1;
    }
};
int main()
{
    sstack s1;
    s1.push(5);
    s1.pop();
    s1.count();
    return 0;
}