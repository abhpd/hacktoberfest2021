// Named fib in order to fix conflicting function name error
function fib(n: number): number {
    if (n <= 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}