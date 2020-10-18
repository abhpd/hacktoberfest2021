// Recursive Fibonacci algorithm.

#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    std::cout << "Type a number: ";
    std::cin >> n;
    int res = fibonacci(n);
    std::cout << "Fibonacci(" << n << ") = " << res << std::endl;
    return 0;
}
