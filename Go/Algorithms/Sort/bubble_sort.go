package main

import (
	"fmt"
)


func bubbleSort(arr []int) {
	for { 
		sorted := true 
		for i := 0; i < len(arr)-1; i++ { 
			if arr[i] > arr[i+1] { 
				tmp := arr[i] 
				arr[i] = arr[i+1] 
				arr[i+1] = tmp 
				sorted = false 
			} 
		} 
		if sorted == true { break } 
		} 
} 

func main() { 
	arr := []int{10, 61, 25, 36, 26, 66, 13, 41, 9, 1} 
	fmt.Print("elements: ", arr, "\n", "In ascending order: [ ") 
	bubbleSort(arr) 
	for i := 0; i < len(arr); i++ { 
		if i != (len(arr)-1){
			fmt.Print(arr[i], ", ")
		}else{
			fmt.Print(arr[i]) 
		}
	} 
	fmt.Print("]\n") 
} 