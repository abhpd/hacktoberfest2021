package main

import "fmt"

func binary_search(numbers []int, left int, right int, target int) int {
  if left > right {
    return -1
  }
  mid := left + (right - left) / 2
  if numbers[mid] > target {
    return binary_search(numbers, left, mid - 1, target)
  }
  if numbers[mid] < target {
    return binary_search(numbers, mid + 1, right, target)
  }
  return mid
}

func main() {
  // Get inputs
  input_length := 0
  fmt.Println("Enter the number of inputs:")
  fmt.Scanln(&input_length)
  fmt.Println("Enter the inputs[Sorted]:")
  numbers := make([]int, input_length)
  for i := 0; i < input_length; i++ {
      fmt.Scanln(&numbers[i])
  }

  // Get search number
  target := 0
  fmt.Println("Search number:")
  fmt.Scanln(&target)

  // Binary search
  result := binary_search(numbers, 0, input_length - 1, target)

  if result == -1 {
    fmt.Println("Target not found")
  } else {
    fmt.Println("Target", target, "is at position", result)
  }
}