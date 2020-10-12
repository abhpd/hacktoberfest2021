package main

import "fmt"

func linear_search(numbers []int, input_length int, target int) int {
  for idx := 0; idx < input_length; idx++ {
    if numbers[idx] == target {
      return idx
    }
  }
  return -1
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

  // Get search number
  target := 0
  fmt.Println("Search number:")
  fmt.Scanln(&target)

  // linear search
  result := linear_search(numbers, input_length, target)

  if result == -1 {
    fmt.Println("Target not found")
  } else {
    fmt.Println("Target", target, "is at position", result)
  }
}