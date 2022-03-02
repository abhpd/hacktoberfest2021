def heapify(array, a, b):
	largest = b 
	l = 2 * b + 1
	root = 2 * b + 2	 

	if l < a and array[b] < array[l]:
		largest = l

	if root < a and array[largest] < array[root]:
		largest = root

	# Change root
	if largest != b:
	    array[b], array[largest] = array[largest], array[b]
	    heapify(array, a, largest)

# sort an array of given size
def Heap_Sort(array):
	a = len(array)

	# maxheap..
	for b in range(a // 2 - 1, -1, -1):
		heapify(array, a, b)

	# extract elements
	for b in range(a-1, 0, -1):
		array[b], array[0] = array[0], array[b] # swap
		heapify(array, b, 0)

# Driver code 
array = [ 7, 2, 5, 6, 3, 1, 8, 4]
print("The original array is: ", array)
Heap_Sort(array)
a = len(array)
print ("Array after sorting is: ", array)
