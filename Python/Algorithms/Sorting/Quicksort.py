from random import randint

def quicksort(array):

    if len(array) < 2:

        return array

    low, same, high = [], [], []

    pivot = array[randint(0, len(array) - 1)]

    for item in array:

        if item < pivot:

            low.append(item)

        elif item == pivot:

            same.append(item)

        elif item > pivot:

            high.append(item)

    return quicksort(low) + same + quicksort(high)

    

arr = list(map(int,input().split()))

print(quicksort(arr))

