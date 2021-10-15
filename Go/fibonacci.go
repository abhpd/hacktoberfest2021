package main

func GetFibonacci(n int) int {
	if n == 0 {
		return 0
	}

	var n1, n2 int = 0, 1
	for i := 1; i < n; i++ {
		n3 := n2 + n1
		n1 = n2
		n2 = n3
	}

	return n2
}
