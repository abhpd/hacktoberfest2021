# Inserion Sort in Python 
  
def insertionSort(arr): 
    for i in range(1, len(arr)): 
  
        key = arr[i] 
  
        # Move elementsone postion ahead as long as they're greater than key
        j = i-1
        while j >=0 and key < arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        # Insert key
        arr[j+1] = key 


def print_array(arr):
    print ("Sorted array is:", *arr) 

  
# Driver code

n = int(input("Enter number of elements : ")) 
# Use map function to take input array  
arr = list(map(int,input("Enter the elements : ").strip().split()))[:n] 

insertionSort(arr) 
print_array(arr)
