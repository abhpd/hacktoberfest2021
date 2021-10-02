def ternarysearch(arr,lo,hi,key):
    if(hi>=lo):
        mid1 = int(lo+ (hi-lo)/3)
        mid2 = int(hi -  (hi-lo)/3)
        if(arr[mid1] == key):
            return mid1
        if(arr[mid2] == key):
            return mid2
        if(key<arr[mid1]):
            return ternarysearch(arr,lo,mid1-1,key)
        elif(key>arr[mid2]):
            return ternarysearch(arr,mid2+1,hi,key)
        else:
            return ternarysearch(arr,mid1+1,mid2-1,key)
    return -1
arrsize=int(input("Enter length: "))
arr=list(map(int,input("\nEnter the numbers : ").strip().split()))[:arrsize]
key=int(input("input number to find: "))
arr.sort()
print("\n")
print(ternarysearch(arr, 0,len(arr)-1, key))