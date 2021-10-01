'''
Window Sliding Technique

The technique can be best understood with the window pane in bus, consider a window of length n and the pane which is fixed in it of length k. Consider, initially the pane is at extreme left i.e., at 0 units from the left. Now, co-relate the window with array arr[] of size n and pane with current_sum of size k elements. Now, if we apply force on the window such that it moves a unit distance ahead. The pane will cover next k consecutive elements. 
Consider an array arr[] = {5, 2, -1, 0, 3} and value of k = 3 and n = 5
Applying sliding window technique : 

We compute the sum of first k elements out of n terms using a linear loop and store the sum in variable window_sum.
Then we will graze linearly over the array till it reaches the end and simultaneously keep track of maximum sum.
To get the current sum of block of k elements just subtract the first element from the previous block and add the last element of the current block .
'''

# ------------------------- VARIANT 1 -------------------------

"""

Time Complexity: O(n)
Algo's Objective: Maximum/Minimum Sum of K size subarray

1. windowsum: Store the sum of elements of current window
2. maximum: Store the maximum sum while iterating through windows
3. While running the for loop, we are removing the 1st element of the current window and adding the rightmost element (not included) of the window.

"""

def slidingwindow(arr, k):
    windowsum = sum(arr[:k])
    maximum = windowsum
    n = len(arr)

    for i in range(n-k):
        windowsum = windowsum - arr[i] + arr[i+k]
        maximum = max(windowsum, maximum)
    return maximum

arr = [1, 4, 2, 10, 2, 3, 1, 0, 20]
k = 3
print(slidingwindow(arr, k))




# ------------------------- VARIANT 2 -------------------------

"""

Time Complexity: O(n²)
Algo's Objective: Smallest subarray with given Sum

1. windowsum: Store the sum of elements of current window
2. maximum: Store the maximum sum while iterating through windows
3. While running the for loop, we are removing the 1st element of the current window and adding the rightmost element (not included) of the window.

"""

def slidingwindow(arr, target):
    windowsum = 0              #Current window sum
    j = 0                      #Window Start
    jsize = max(arr)           #Current Window Size

    for i in range(len(arr)):
        windowsum = windowsum + arr[i]

        while windowsum >= target:
            jsize = min(jsize, i - j + 1)
            windowsum = windowsum - arr[j]
            j = j + 1
    return jsize


arr = [4, 2, 2, 7, 8, 1, 2, 8, 1, 0]
target = 8
print(slidingwindow(arr, target))