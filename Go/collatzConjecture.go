package main

import (
	"fmt"
	"os"
)

var x uint64

func isEven() bool {

	if x%2 == 0 {
		return true
	} else {
		return false
	}
}

func checkNum()  {
	if x<1 {
		fmt.Println("Number less than 1")
		os.Exit(0)
	}
}

func main() {

	fmt.Println("\nFor info on Collatz Conjecture go to https://en.wikipedia.org/wiki/Collatz_conjecture")
	fmt.Printf("\nOn reaching 1 program terminates. Don't enter number < 1.\n\n")

	fmt.Println("Enter a number: ")
	fmt.Scan(&x)

	checkNum()

	fmt.Printf("%d -> ", x)

	for x != 1 {
		if isEven() {
			x /= 2
		} else {
			x = 3*x + 1
		}
		fmt.Printf("%d -> ", x)
	}

	fmt.Printf("END")
}
