def count_sort(arr): 
    max_element = int(max(arr)) 
    min_element = int(min(arr)) 
    range_of_elements = max_element - min_element + 1
    count_arr = [0 for _ in range(range_of_elements)] 
    output_arr = [0 for _ in range(len(arr))] 
  
    for i in range(0, len(arr)): 
        count_arr[arr[i]-min_element] += 1
  
    for i in range(1, len(count_arr)): 
        count_arr[i] += count_arr[i-1] 
  
    for i in range(len(arr)-1, -1, -1): 
        output_arr[count_arr[arr[i] - min_element] - 1] = arr[i] 
        count_arr[arr[i] - min_element] -= 1

    for i in range(0, len(arr)): 
        arr[i] = output_arr[i] 
  
    return arr 
  

arr = list(map(int,input("\nEnter the numbers : ").strip().split()))
ans = count_sort(arr) 
print("Sorted character array is " + str(ans))
