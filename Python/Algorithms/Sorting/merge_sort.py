'''
Python Program to implement Merge Sort algorithm

'''

def merge_sort(nums):
  def merge(left_list, right_list):
    sorted_list = []
    left_list_index = right_list_index = 0
    left_list_length, right_list_length = len(left_list), len(right_list)
    
    for _ in range(left_list_length + right_list_length):
      if left_list_index < left_list_length and right_list_index < right_list_length:
        if left_list[left_list_index] <= right_list[right_list_index]:
          sorted_list.append(left_list[left_list_index])
          left_list_index += 1
        else:
          sorted_list.append(right_list[right_list_index])
          right_list_index += 1
      elif left_list_index == left_list_length:
        sorted_list.append(right_list[right_list_index])
        right_list_index += 1
      elif right_list_index == right_list_length:
        sorted_list.append(left_list[left_list_index])
        left_list_index += 1
    return sorted_list
  
  def merge_sorter(nums):
    if len(nums) <= 1:
      return nums
    mid = len(nums) // 2
    left_list = merge_sorter(nums[:mid])
    right_list = merge_sorter(nums[mid:])
    return merge(left_list, right_list)
  
  return merge_sorter(nums)
  

if __name__ == "__main__":
  print(merge_sort([45,65,23,89,18]))
