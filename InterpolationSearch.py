'''
Psuedo code
A → Array list
N → Size of A
X → Target Value

Procedure Interpolation_Search()

   Set Lo  →  0
   Set Mid → -1
   Set Hi  →  N-1

   until x didnt match
   
      if Lo equals to Hi OR A[Lo] equals to A[Hi]
         return -1
      end if
      
      Set Mid = Lo + ((Hi - Lo) / (A[Hi] - A[Lo])) * (X - A[Lo]) 

      if A[Mid] = X
         return mid
      else 
         if A[Mid] < X
            Set Lo to Mid+1
         else if A[Mid] > X
            Set Hi to Mid-1
         end if
      end if
    if no return done till now return -1
End Procedure

Implementation done below
arr -> array
n -> length of array
key -> value to find
'''
def interpolationsea(arr,n,key):
    lo=0
    mid=-1
    hi=n-1
    while(arr[hi] !=arr[lo] and key>=arr[lo] and key<=arr[hi]):
        mid=int(lo+((hi-lo)/(arr[hi]-arr[lo]))*(key-arr[lo]))
        if(arr[mid]==key):
            return mid
        else:
            if(arr[mid]<key):
                lo=mid+1
            elif(arr[mid]>key):
                hi=mid-1
    return -1
arrsize=int(input("Enter length: "))
arr=list(map(int,input("\nEnter the numbers : ").strip().split()))[:arrsize]
key=int(input("input number to find: "))
arr.sort()
print("\n")
print(interpolationsea(arr, len(arr), key))