import sys

def sum(arr, i, j):
    result = 0
    while i > 0:
        result += arr[i][j]
        i -= i & -i

    return result

def update(arr , i, j, value):
    while (i < len(arr)):
        arr[i][j] += value
        i += i & (-i)

n, k = list(map(lambda x: int(x), input().split()))

bit = [[0] * 11 for i in range(n+1)]
result = 0
    
for x in range(n):
    i = int(input())
    update(bit, i, 0, 1)
    j = 1
    while (j < k):
        update(bit, i, j, sum(bit, i-1, j-1))
        j += 1
        result += sum(bit, i-1, k-1)

if (k == 0):
    print(n)
    sys.exit(0)

print(result)
#print(sum(bit, n, k+1))
