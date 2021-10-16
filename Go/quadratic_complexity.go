//an algorithm of quadratic complexity if the processing time is
//proportional to the square of the number of input elements.
//the complexity of this algorithm is 10*10 = 100
package main

import (
	"fmt"
)
//func for O(n**2) for multiplication table of n elements
func main() {
	var k, l int
	for k = 1; k <= 10; k ++ {
		fmt.Println(" Multiplication Table ", k)
		for l = 1; l<= 10; l ++ {
			var x int = l * k
			fmt.Println(x)
		}
	}
}
