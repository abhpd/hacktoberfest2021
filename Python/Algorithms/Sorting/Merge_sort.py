#Runtine is O(nlogn)
def merge(arr, l, m, r):
    temp_arr = []
    i = l
    j = m
    while i < m and j < r:
        if arr[i] > arr[j]:
            temp_arr.append(arr[j])
            j += 1
        elif arr[i] < arr[j]:
            temp_arr.append(arr[i])
            i += 1
        else:
            temp_arr.append(arr[i])
            i += 1
            temp_arr.append(arr[j])
            j += 1
    temp_arr.extend(arr[i:m])
    temp_arr.extend(arr[j:r])
    for i in range(len(temp_arr)):
        arr[l+i] = temp_arr[i]
        
def Merge_Sort(arr, l, r):
    length = r - l + 1
    if length == 2:
        if arr[l] > arr[r]:
            arr[l], arr[r] = arr[r], arr[l]
    elif length > 2: 
        Merge_Sort(arr, l, length//2 + l)
        Merge_Sort(arr, length//2 + l + 1, r)
        merge(arr, l, length//2 + l + 1, r+1)

array = list(map(int, input().split()))
Merge_Sort(array)
