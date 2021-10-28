import random

def check_sorted(arr):
    """
    Check to see if the list is sorted in lexiographical order

    Args:
        arr (list): the list to sort

    Returns:
        boolean: True if sorted, False otherwise
    """
    curr_num = arr[0]
    for num in arr:
        if num < curr_num:
            return False
        curr_num = num
    return True

def bogo_sort(arr):
    """
    An implementation of bogosort, a very inefficient sorting algorithm with 
    an average time complexity of O(n*n!)

    Args:
        arr (list): the list to bogosort

    Returns:
        list: the inefficiently sorted with bogosort list
    """
    if not check_sorted(arr):
        random.shuffle(arr)
        return bogo_sort(arr)
    else:
        return arr

arr = [3, 1, 2]
print(f"Sorted list: {bogo_sort(arr)}")