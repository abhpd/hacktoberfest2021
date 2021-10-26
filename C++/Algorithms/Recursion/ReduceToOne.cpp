/*
Title: Recursion
       Given a number N, the task is to reduce it to 1 in the minimum number of steps using recursion. 
       Operation 1: If the number is even then you can divide the number by 2. 
       Operation 2: If the number is odd then you are allowed to perform either (n+1) or (n-1).

Author: Sharmila
*/

#include <bits/stdc++.h>

using namespace std;

int stepsHelper(int N, int steps){
    if(N == 1){
        return steps;
    }
    if(N%2 = 0){
        return stepsHelper(N/2, steps + 1);
    }
     else{
        return min(stepsHelper(N+1, steps + 1), stepsHelper(N-1, steps + 1));
    }
}

int minStepsToOne(int N) {
    int steps = 0;
    if(N == 1){
        return steps;
    }
    return stepsHelper(N, steps);
}

int main()
{
    int value;
    cout << "Enter a number to perfome reduce to 1: ";
    cin >> value;
    
    int result = minStepsToOne(value);
    cout << "Minimum number of steps required to reduce the "<< value <<" to 1: " << result <<endl;
    return 0;
}

/* Sample output:

Enter a number to perfomr reduce to 1: 15                                                                                                                                                               
Total number of steps: 5  

Note that if we instead start with - 1, it needs 6 steps: 15 - 1 = 14 / 2 = 7 - 1 = 6 / 2 = 3 - 1 = 2 - 1 = 1
*/
