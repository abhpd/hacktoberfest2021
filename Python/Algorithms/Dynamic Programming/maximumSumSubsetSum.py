def minSubsetSumDiff(n, arr):
    summ = sum(arr)

    dp = [[0]*(summ + 1) for i in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = 1
    
    for i in range(n + 1):
        for j in range(summ + 1):
            if arr[i - 1] <= j:
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - arr[i - 1]]
            else:
                dp[i][j] = dp[i - 1][j]
    minn = float('inf')
    for i in range(summ + 1):
        if dp[n][i] == 1:
            if minn > abs(summ - 2*i):
                minn = abs(summ - 2*i)
                print(i)


    return minn

########## Driver Code
arr = [3, 1, 4, 2, 3, 1, 7, 2, 1]
n = len(arr)
print(minSubsetSumDiff(n, arr))
##########