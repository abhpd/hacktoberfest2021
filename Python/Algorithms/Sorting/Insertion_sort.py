def insertion(arr,n):
    for i in range(1,n):
        current=arr[i]
        j=i-1
        while(arr[j]>current and j>=0):
            arr[j+1]=arr[j]
            j-=1
        arr[j+1]=current
    return arr

arr=[5,6,1,2,4,3]
n=len(arr)
print(insertion(arr,n))
