 
def merge(a: list,low: int,mid: int,high: int) ->None:

  """
  The merge function merges and sorts the sub arrays

  """
  n1=mid-low+1  
  n2=high-mid
  b=[]
  c=[]
  for i in range(n1):
    b.append(a[low+i])    #b array now consists elements of the first subarray
  for i in range(n2):
    c.append(a[mid+1+i])  #c consists elements of the second subarray
  
  i=j=0                   #index positions of the main array and the sub arrays
  k=low
  while i<n1 and j<n2:    #Till we run out of elements in one subarray, we copy elements which are smaller to main array
    if b[i]<=c[j]:        
      a[k]=b[i]
      i+=1
    else:
      a[k]=c[j]
      j+=1
    k+=1
  while i<n1:             #remaining elements(if any) of the first sub array is copied to the main array
    a[k]=b[i]
    i+=1
    k+=1
  while j<n2:
    a[k]=c[j]
    k+=1
    j+=1


  

def merge_sort(a: list,low: int,high: int) ->None:
    """

    This function divides arrays into sub arrays
    
    """
  if(low<high):
    mid=(low+high)//2  #the array is divided into two halves with mid as the center
    merge_sort(a,low,mid)
    merge_sort(a,mid+1,high)
    merge(a,low,mid,high)  #merging the sub arrays
  else: 
    return
   
a=[]
n=int(input("enter the number of elements: ").strip())
print("Enter the elements of the array one by one: ")
for i in range(n): 
  b=int(input())
  a.append(b)
merge_sort(a,0,n-1)
print(a)
