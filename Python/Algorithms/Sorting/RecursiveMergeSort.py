#recursive merge sort for pyhton
def merge_sort(array):
    if len(array) > 1:
        mid = len(array)//2
        left = array[:mid]
        right = array[mid:]
        left = merge_sort(left)
        right = merge_sort(right)
        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                array[k] = left[i]
                i += 1
            else:
                array[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            array[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            array[k] = right[j]
            j += 1
            k += 1    
        return array
    return array
        

unsorted_array = [60, 170, 30, 2, 11, 19, 24, 50, 60, 3, 100]
sorted_array = merge_sort(unsorted_array)
print(sorted_array)