package main

import "fmt"

func mergeSort(items []int) []int {
	n := len(items)

	if n == 1 {
		return items
	}

	mid := int(n / 2)

	left, right := make([]int, mid), make([]int, n-mid)
	for i := 0; i < n; i++ {
		if i < mid {
			left[i] = items[i]
		} else {
			right[i-mid] = items[i]
		}
	}

	return merge(mergeSort(left), mergeSort(right))
}

func merge(left, right []int) []int {
	v := make([]int, len(left)+len(right))

	i := 0
	for len(left) > 0 && len(right) > 0 {
		if left[0] < right[0] {
			v[i] = left[0]
			left = left[1:]
		} else {
			v[i] = right[0]
			right = right[1:]
		}

		i++
	}

	for j := 0; j < len(left); j++ {
		v[i] = left[j]
		i++
	}

	for j := 0; j < len(right); j++ {
		v[i] = right[j]
		i++
	}

	return v
}

func main() {
	values := []int{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
	values = mergeSort(values)

	for i, v := range values {
		fmt.Printf("%v: %v\n", i, v)
	}
}
