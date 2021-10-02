def merge(A, aux, left, middle, right):
    for k in range(left, right + 1):
        aux[k] = A[k]
    i = left
    j = middle + 1
    for k in range(left, right + 1):
        if i > middle:
            A[k] = aux[j]
            j += 1
        elif j > right:
            A[k] = aux[i]
            i += 1
        elif aux[j] < aux[i]:
            A[k] = aux[j]
            j += 1
        else:
            A[k] = aux[i]
            i += 1


def mergesort(A, aux, left, right):
    if right <= left:
        return
    middle = (left + right) // 2

    mergesort(A, aux, left, middle)

    mergesort(A, aux, middle + 1, right)

    merge(A, aux, left, middle, right)



# Example:

A = arr = [0,19,22,75,13,16,12,123,55,2,1,64]
aux = [0] * len(A)
mergesort(A, aux, 0, len(A) - 1)
print("Result:", A)