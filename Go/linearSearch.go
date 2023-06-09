package main 

import (
	"fmt"
	"strconv"
)

func main(){
	numbers := []int{5, 7, 8, 10, 45, 66};
	fmt.Println(linearSearch(numbers, 45)); //returns Target 45 is found at index 4
	fmt.Println(linearSearch(numbers, 1));  //returns Target 1 not found at the list
}

func linearSearch(input []int, target int) string{
	for key, value := range input {
		if value == target {
			res := "Target " + strconv.Itoa(target) + " is found at index " + strconv.Itoa(key) 
			return res;
		}
	}
	return "Target " + strconv.Itoa(target) + " not found at the list"
}