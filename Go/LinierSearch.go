package main

import "fmt"

func main() {
	number := []int{15, 68, 16, 28, 11, 98, 99, 216, 211}
	fmt.Println(LinearSearch(number, 216))
}

func LinearSearch(list []int, id int) bool {
	for _, item := range list {
		if item == id {
			return true
		}
	}
	return false
}
