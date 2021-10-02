def shellsort(arr):
    gap = len(arr) // 2 #intialize gap
    while gap > 0:
        i = 0
        j = gap
        while j < len(arr):
            if arr[i] >arr[j]:
                arr[i],arr[j] = arr[j],arr[i]
            i += 1
            j += 1
            #swap values which are not in right order
            k = i
            while k - gap > -1:
                if arr[k - gap] > arr[k]:
                    arr[k-gap],arr[k] = arr[k],arr[k-gap]
                k -= 1
        gap = pow(2, k)-1
        print(gap)
arrsize=int(input("Enter length\n"))
arr=list(map(int,input("\nEnter the numbers : ").strip().split()))[:arrsize]
shellsort(arr)
print("\n")
print(arr)