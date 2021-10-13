def insertion_sort(v):
    n = len(v)
    for i in range(1, n):
        j = i
        while j >= 1 and v[j-1] > v[j]:  
            v[j], v[j-1] = v[j-1], v[j]
            j -= 1
        print("i={}, {}".format(i, v))
    return(v)

# Example
a = [1,5,7,4,3,9,8,6,2]
insertion_sort(a)
