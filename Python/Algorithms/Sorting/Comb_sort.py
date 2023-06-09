#comb sort (variation of bubble sort)
def comb_sort(inputArray):
    swap = True
    gap = len(inputArray)
    while gap >1 or swap:
        gap = max(1, int(gap/1.3))
        swap = False
        for i in range(len(inputArray) - gap):
            if inputArray[i] > inputArray[i+gap]:
                inputArray[i],inputArray[i+gap] = inputArray[i+gap], inputArray[i]
                swap = True

inputArray = input('Enter the list space seperated that needs to be sorted: ')
inputArray = [int(i) for i in inputArray.split()]
comb_sort(inputArray)
print('Final sorted list is:',inputArray)