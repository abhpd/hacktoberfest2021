def mergeSort(arr):
    """
    Recursive sorting algorithm that divides the list and compares values of sublists.

    Returns a sorted list from smallest to largest.

    O(n log(n))

    arr = [7, 4, 5, 6, 9, 1]

    > mergeSort(arr)

    [1, 4, 5, 6, 7, 9]
    """
    if len(arr) > 1:

        # Finds the exact middle of the array
        mid = len(arr) // 2

        # Left side of array
        L = arr[:mid]

        # Right side of array
        R = arr[mid:]

        # Sorts right side of array
        mergeSort(L)

        # Sorts left side of array
        mergeSort(R)

        i = j = k = 0

        # Goes through each list and compares the smallest
        # Assigns smaller value to that value in the array
        while i < len(L) and j < len(R):
            if L[i] < R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
        
        # Verifies there are no values left over in each list
        
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1

        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1