'''

Given an array a[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.

Input:
N = 5 a[] = {2,3,1,2,3}

Output:
2 3

Step 1: First check all the values that are present in an array then go to that values as indexes and increment by the size of array. Step 2: Now check which value exists more than once by dividing with the size of array.

'''

def printRepeating(arr, n):
 
    for i in range(0, n):
        index = arr[i] % n
        arr[index] += n
 
    for i in range(0, n):
        if (arr[i]/n) >= 2:
            print(i)