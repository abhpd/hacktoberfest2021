def insertion_sort(arr):
   for i in range(1, len(arr)):
      j = i-1
      nxt_element = arr[i]

   while (arr[j] > nxt_element) and (j >= 0):
      arr[j+1] = arr[j]
      j=j-1
   arr[j+1] = nxt_element


if __name__ == "__main__":
  list = [19,2,31,45,30,11,121,27]
  insertion_sort(list)
  print(list)
