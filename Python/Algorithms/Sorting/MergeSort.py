import random,time

#merge sort
def merge(a):
  if len(a)>1:
    l=a[:len(a)//2]
    r=a[len(a)//2:]
    merge(l)
    merge(r) 

    i=j=k=0
    #simple merge
    while i<len(l) and j<len(r):
      if l[i]>r[j]:
        a[k]=r[j]
        j+=1
        k+=1
      else:
        a[k]=l[i]
        i+=1
        k+=1

    #append remaining elements in merged array
    if i<len(l):
      while i<len(l):
        a[k]=l[i]
        i+=1
        k+=1
    else:
      while j<len(r):
        a[k]=r[j]
        j+=1
        k+=1

#insertion sort     
def ins(a):
  for i in range(1,len(a),1):
    j=i-1
    temp=a[i]
    while(j>=0 and temp<a[j]):
      j-=1
    a.pop(i)
    a.insert(j+1,temp)
    
#Generate Random elements
n=100
arr=[]
for i in range(n):
  arr.append(random.randint(0,100))
#print("Initial array:\n"+str(arr))
arr1=arr[:]
print(arr)
print()

#time calculation
start=time.time()
merge(arr)
end=time.time()
print("Sorted array: "+str(arr))
print("\nTime taken by merge sort: "+str((end-start)*1000)+"ms\n")

start=time.time()
ins(arr1)
end=time.time()
print("Time taken by insertion sort: "+str((end-start)*1000)+"ms")