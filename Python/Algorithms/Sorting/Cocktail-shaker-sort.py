# Python program for implementation of Cocktail Sort

def cocktailSort(arr):
	n = len(arr)
	moved = True
	beg = 0
	end = n-1 
	while (moved==True):

		# set the moved flag to true 
        # on entering each iteration of the loop
		moved = False

		# loop from start to finish same as in bubble sort
		for i in range (beg, end):
			if (arr[i] > arr[i+1]) :
				arr[i], arr[i+1]= arr[i+1], arr[i]
				moved=True

		# if nothing moved, then the array is sorted.
		if (moved==False):
			break

		# else continue and reset the moved flag to false
		moved = False

		# decrement the end point back by one, because
		# item at the end is at the correct position
		end = end-1

		# from right to left, do the same
		# comparison as in the previous stage
		for i in range(end-1, beg-1,-1):
			if (arr[i] > arr[i+1]):
				arr[i], arr[i+1] = arr[i+1], arr[i]
				moved = True

		# increment the starting point beg by 1, because
		# the last stage would have moved the next
		# smallest number to its correct position.
		beg = beg + 1

# Driver code to test above
arr = [25, 32, 44, 68, 12, 19, 20]
cocktailSort(arr)
print("Sorted array is:")
for i in range(len(arr)):
	print (arr[i])
