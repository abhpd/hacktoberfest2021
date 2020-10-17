package main

import "fmt"

func merge_sort(numbers []int, input_length int, left int, right int) {
  if left < right {
    // Merge Sort
    middle := (left + right) / 2
    merge_sort(numbers, input_length, left, middle)
    merge_sort(numbers, input_length, middle + 1, right)

    // Merge
    result := make([]int, input_length)
    idx := 0
    ridx := 0
    lidx := 0
    for lidx <= middle - left && ridx <= right - middle - 1{
      if numbers[left + lidx] <= numbers[middle + 1 + ridx]{
        result[idx] = numbers[left + lidx]
        lidx++
        idx++
      } else {
        result[idx] = numbers[middle + 1 + ridx]
        ridx++
        idx++
      }
    }
    if lidx <= middle - left {
      copy(result[idx:], numbers[left+lidx:middle+1])
    }
    if ridx < right - middle {
      copy(result[idx:], numbers[middle+1+ridx:right+1])
    }
    for i := 0; i <= right-left; i++{
      numbers[left + i] = result[i]
    }
  }
}

func main() {
  // Get inputs
  input_length := 0
  fmt.Println("Enter the number of inputs:")
  fmt.Scanln(&input_length)
  fmt.Println("Enter the inputs:")
  numbers := make([]int, input_length)
  for i := 0; i < input_length; i++ {
      fmt.Scanln(&numbers[i])
  }

  // linear search
  merge_sort(numbers, input_length, 0, input_length - 1)
  
  fmt.Println("Merge Sort", numbers)
}