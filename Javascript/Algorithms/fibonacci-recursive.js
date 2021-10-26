// Input is length of fibonacci sequence
// Output is the number found at that position
// This algorithm is the recursive solution
function fibonacci(n) {
    if (n == 0 || n == 1){
      return 1;
    }
    else {
      return fibonnaci(n-1) + fibonnaci(n-2);
    }
}