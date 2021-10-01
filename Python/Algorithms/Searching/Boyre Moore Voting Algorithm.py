'''
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Input:
arr = [1 , 1, 1, 3, 3 , 2, 2, 2]

Output:
[1, 2]

Explanation:

Step 1: This is Boyre Moore Voting Algorithm
Step 2: As n/3 only gives 2 as maximum remainder so there must be at max 2 majority elements in an array that have counts greater tha n/3.
Step 3: Instead of ele now there will be num1, num2, c1, c2 to store two elements.

'''

def majorityElement(arr):
    num1 = -1
    num2 = -1
    c1 = 0
    c2 = 0

    for i in range(len(arr)):
        if arr[i] == num1:
            c1 += 1
        elif arr[i] == num2:
            c2 += 1
        elif c1 == 0:
            num1 = arr[i]
            c1 = 1
        elif c2 == 0:
            num2 = arr[i]
            c2 = 1
        else:
            c1 -= 1
            c2 -= 1

    temp = []
    c1 = 0
    c2 = 0
    for i in range(len(arr)):
        if arr[i] == num1:
            c1 += 1
        if arr[i] == num2:
            c2 += 1
        
    if c1 > len(arr)//3:
        temp.append(num1)
    if (c2 > len(arr)//3) and (num1 != num2):
        temp.append(num1)
    return temp

