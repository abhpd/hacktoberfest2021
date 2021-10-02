'''
Insertion Sort

In Insertion Sort We  start iterating from the second element of array till last element and for every element we insert it at its correct position in the subarray before it.

'''

def insertionSort(arr):
    for i in range(1, len(arr)):  #iterating from the second element of array till last element 
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
arr = [34, 5, 19, 2, 71,45,55]
insertionSort(arr)
print ("Resultant array")
for i in range(len(arr)):
    print (arr[i])


'''
Time Complexity: O(n^2) 
Auxiliary Space: O(1)

In-place and stable

Input: 
An array [34, 5, 19, 2, 71,45,55]

Output: 
Resultant array
2
5
19
34
45
55
71

'''