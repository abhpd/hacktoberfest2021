# Converting array to heap
def arr_heap(arr, s, i):
    # To find the largest element among a root and children
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < s and arr[i] < arr[l]:
        largest = l

    if r < s and arr[largest] < arr[r]:
        largest = r

    # Replace the root if it is not the largest, then continue with the heap algorithm
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        arr_heap(arr, s, largest)

# Heap sort algorithm
def heapsort(arr):
    s = len(arr)

    # Making the Max heap
    for i in range(s//2, -1, -1):
        arr_heap(arr, s, i)

    for i in range(s-1, 0, -1):
        # replace
        arr[i], arr[0] = arr[0], arr[i]

    # Transform root element into Heap
        arr_heap(arr, i, 0)


arr = [1, 12, 9, 5, 6, 10]
heapsort(arr)
n = len(arr)
print("Array after Heap Sort is:")
print(arr)
