
def partition(arr, low, high):
    index_smaller = (low - 1)
    pivot = arr[high]

    for j in range(low, high):
        if arr[j] <= pivot:
            index_smaller += 1
            arr[index_smaller], arr[j] = arr[j], arr[index_smaller]

    arr[index_smaller + 1], arr[high] = arr[high], arr[index_smaller + 1]

    return index_smaller + 1


def quicksort_iteractive(arr, start, end):
    size = (end - start) + 1 
    stack = [0] * size

    top = -1

    top += 1
    stack[top] = start
    top += 1
    stack[top] = end

    while top >= 0:
        end = stack[top]
        top -= 1
        start = stack[top]
        top -= 1

        p = partition(arr, start, end)

        if p - 1 > start:
            top += 1
            stack[top] = start
            top += 1
            stack[top] = p - 1

        if p + 1 < end:
            top += 1
            stack[top] = p + 1
            top += 1
            stack[top] = end

def quicksort_recursive(arr, start, end):
    if start < end:
        p = partition(arr, start, end)

        quicksort_recursive(arr, start, p-1)
        quicksort_recursive(arr, p+1, end)


