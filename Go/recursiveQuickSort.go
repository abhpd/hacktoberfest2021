package main

import (
	"fmt"
	"math/rand"
	"time"
)

// function to generate random array of numbers from 0 to 29
func randarray() []int{

	rand.Seed(time.Now().Unix())

	arr := rand.Perm(30)

	return arr
}

func quicksort(array []int, first int, last int) {

	if first < last {

		i := first
		j := last
		pivot := array[first] // Taking the pivot as the first element of the array

		for i < j {

			for array[i] <= pivot && i < last {
				i += 1
			}

			for array[j] >= pivot && j > first {
				j -= 1
			}

			if i < j {

				// swapping i th element with the j th element
				temp := array[i]
				array[i] = array[j]
				array[j] = temp
			}
		}

		temp := array[j]
		array[j] = array[first]
		array[first] = temp

		quicksort(array, first, j-1)
		quicksort(array, j+1, last)
	}
}

func main() {

	array := randarray()

	fmt.Println("\nBefore sort:")
	fmt.Println(array)

	quicksort(array, 0, 29) // since I have fixed the size of the random array as 9

	fmt.Println("\nAfter sort:")
	fmt.Println(array)
}