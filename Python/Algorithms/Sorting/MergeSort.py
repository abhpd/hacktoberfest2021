def merge(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    # initialize L and R
    L = [0 for i in range(0, n1+1)]
    R = [0 for i in range(0, n2+1)]
    for i in range(0, n1):
        L[i] = A[p+i]
    for j in range(0, n2):
        R[j] = A[q+j+1]
    L[n1] = float("inf")
    R[n2] = float("inf")

    # simplify this?
    i = 0
    j = 0
    k = p

    while i < n1 and j < n2:
        if R[j] < L[i]:
            A[k] = R[j]
            k += 1
            j += 1
        else:
            A[k] = L[i]
            k += 1
            i += 1

    while i < n1:
        A[k] = L[i]
        k += 1
        i += 1
    while j < n2:
        A[k] = R[j]
        k += 1
        j += 1

def mergesort(A, p, r):
    if p < r:
        q = (p + r) // 2
        mergesort(A, p, q)
        mergesort(A, q+1, r)
        merge(A, p, q, r)

list = [5, 4, 3, 2, 1]
mergesort(list, 0, 4)
print(list)
