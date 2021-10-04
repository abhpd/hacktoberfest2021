# get number of digits in largest item
def num_digits(arr):
    maxDigit = 0
    for num in arr:
        maxDigit = max(maxDigit, num)
    return len(str(maxDigit))
 
 
# flatten into a 1D List
from functools import reduce
def flatten(arr):
    return reduce(lambda x, y: x + y, arr)
 
 
def radix(arr):
    digits = num_digits(arr)
    for digit in range(0, digits):
        temp = [[] for i in range(10)]
        for item in arr:
            num = (item // (10 ** digit)) % 10
            temp[num].append(item)
        arr = flatten(temp)
    return arr
 
 
array = [55, 45, 3, 289, 213, 1, 288, 53, 2]
array = radix(array)
print(array)