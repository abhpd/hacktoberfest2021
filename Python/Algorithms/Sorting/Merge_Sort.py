def merge_sort(array, left, right):
    if left >= right:
        return

    middle = (left + right)//2
    merge_sort(array, left, middle)
    merge_sort(array, middle + 1, right)
    merge(array, left, right, middle)


def merge(array, left, right, middle):
    # Make copies of both arrays we're trying to merge
    left_copy = array[left:middle + 1]
    right_copy = array[middle+1:right+1]

    left_copy_index = 0
    right_copy_index = 0
    sorted_index = left

    # Go through both copies until we run out of elements in one
    while left_copy_index < len(left_copy) and right_copy_index < len(right_copy):
        '''
         If our left_copy has the smaller element, put it in the sorted
         part and then move forward in left_copy (by increasing the pointer)
         '''
        if left_copy[left_copy_index] <= right_copy[right_copy_index]:
            array[sorted_index] = left_copy[left_copy_index]
            left_copy_index = left_copy_index + 1
        else:
            array[sorted_index] = right_copy[right_copy_index]
            right_copy_index = right_copy_index + 1

        sorted_index = sorted_index + 1

    '''
    We ran out of elements either in left_copy or right_copy
    so we will go through the remaining elements and add them
    '''
    while left_copy_index < len(left_copy):
        array[sorted_index] = left_copy[left_copy_index]
        left_copy_index = left_copy_index + 1
        sorted_index = sorted_index + 1

    while right_copy_index < len(right_copy):
        array[sorted_index] = right_copy[right_copy_index]
        right_copy_index = right_copy_index + 1
        sorted_index = sorted_index + 1


array = [210, 14, 6, 78, 456, 88, 4, 60]
merge_sort(array, 0, len(array) - 1)
print(array)

# Output -> [4, 6, 14, 60, 78, 88, 210, 456]
