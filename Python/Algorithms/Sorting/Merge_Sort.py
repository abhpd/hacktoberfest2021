#give input like this :[2,4,32,1]
def mergesort(lst):
    n = len(lst)
    if n == 1 or n == 0:
        return lst
    else:
        length = n//2
        A = lst[:length]
        B = lst[length:]
        A = mergesort(A)
        B = mergesort(B)
        i, j = 0, 0
        lst = []
        while i < len(A) and j < len(B):
            if A[i] < B[j]:
                lst.append(A[i])
                i += 1
            else:
                lst.append(B[j])
                j += 1
        if i == len(A):
            lst += B[j:]
        else:
            lst += A[i:]
        return lst
        
list = eval(input("Enter the list of numbers:"))
list = mergesort(list)
print("Your sorted list is", list)