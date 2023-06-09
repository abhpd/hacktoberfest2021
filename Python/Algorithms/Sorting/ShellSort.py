nums = [50, 34, 78, 44, 8, 90, 21, 1, 30]

n = len(nums)
gap = int(n//2)

while gap > 0:
    i = 0
    j = gap
    
    while j < n:
        if nums[j] < nums[i]:
            nums[i],nums[j] = nums[j],nums[i]
        i = i + 1
        j = j + 1
        
        t = i
        while t - gap > -1:
            if nums[t - gap] > nums[t]:
                    nums[t - gap],nums[t] = nums[t],nums[t - gap]
            t = t - 1
    gap //= 2
    
print(nums)