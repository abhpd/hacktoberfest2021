def merge(arr, l, m, r):
    len1 = m - l + 1
    len2 = r - m

    Left = [0] * (len1)
    Right = [0] * (len2)

    for i in range(0, len1):
        Left[i] = arr[l + i]
    
    for j in range(0, len2):
        Right[j] = arr[m + 1 + j]

    i = 0
    j = 0
    k = l

    while i < len1 and j < len2:
        if Left[i] <= Right[j]:
            arr[k] = Left[i]
            i += 1
        else:
            arr[k] = Right[j]
            j += 1
        k += 1

    while i < len1:
        arr[k] = Left[i]
        i += 1
        k += 1
    
    while j < len2:
        arr[k] = Right[j]
        j += 1
        k += 1


def mergeSort(arr, l, r):
    if l < r:

        m = l+(r-l)//2

        mergeSort(arr, l, m)
        mergeSort(arr, m+1, r)
        merge(arr, l, m, r)


arr=[]
n = int(input('Enter the number of elements'))

for i in range(n):
    arr.append(int(input()))

print("Given array is")
print(*arr)
mergeSort(arr, 0, n-1)
print("\nSorted array is")
print(*arr)
