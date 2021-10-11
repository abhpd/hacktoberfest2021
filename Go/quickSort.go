package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)


func main()  {
	fmt.Println("Please input numbers(separate with space):")
	br := bufio.NewReader(os.Stdin)
	a, _, _ := br.ReadLine()
	ns := strings.Split(string(a), " ")
	var values []int
	for _, s := range(ns) {
		n, _ := strconv.Atoi(s)
		values = append(values, n)
	}
	QuickSort(values)
	fmt.Println(values)
}

func QuickSort(arr []int) []int {
	return QuickSortUtil(arr, 0, len(arr) - 1);
}

func QuickSortUtil(arr []int, low, high int) []int {
	if low < high {
		var p int
		arr, p = Partition(arr, low, high)
		arr = QuickSortUtil(arr, low, p-1)
		arr = QuickSortUtil(arr, p+1, high)
	}
	return arr
}

func Partition(arr []int, low, high int) ([]int, int) {
	pivot := arr[high]
	i := low
	for j := low; j < high; j++ {
		if arr[j] < pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}
	arr[i], arr[high] = arr[high], arr[i]
	return arr, i
}