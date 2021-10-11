A=[]  #number array
for v in range(10):    #limit - 6 numbers
    A.append(int(input('Enter your numbers: ')))
print(A)    

#insertion sort
#define a function
def insertionSort(A):
    for j in range(1,len(A)):
        key = A[j]
        i = j-1
        while(i >=0 and A[i]>key):
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key

#implement insertion code and call it.
insertionSort(A)        
print('Sorted number array: ')
print(A)
