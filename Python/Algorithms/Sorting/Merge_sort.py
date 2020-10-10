# Merge Sort Algorithm
def merge_sort(input_list, left, right):
    if left < right:
        # Calculate middle
        middle = (left + right) / 2
        # Sort left
        merge_sort(input_list, left, middle)
        # Sort right
        merge_sort(input_list, middle + 1, right)
        
        # Merge left and right
        sort_result = list()
        ridx = 0
        lidx = 0
        while lidx <= middle-left and ridx <= right-middle-1:
            if input_list[left+lidx] <= input_list[middle+1+ridx]:
                sort_result.append(input_list[left+lidx])
                lidx += 1
            else:
                sort_result.append(input_list[middle+1+ridx])
                ridx += 1

        if lidx <= middle-left:
            sort_result.extend(input_list[left+lidx:middle+1])
        if ridx < right-middle:
            sort_result.extend(input_list[middle+1+ridx:right+1])

        for idx in range(len(sort_result)):
            input_list[left+idx] = sort_result[idx]

if __name__ == "__main__":
    # input example: "[1,2,3,4]"
    input_list = input('Enter the list of objects: ')
    print("Input List:", input_list)
    merge_sort(input_list, 0, len(input_list)-1)
    print("Merge Sort:", input_list)
