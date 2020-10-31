package main

import "fmt"

func main() {
	var x, y, z int
	var is_inverted = false
	fmt.Printf("Digite os 3 valores: ")
	fmt.Scanf("%d %d %d\n", &x, &y, &z)

	a, b, c := x, y, z

	collum_q := make([]int, 1, 10)
	collum_q[0] = -1
	collum_xy := make([]int, 1, 10)
	collum_xy[0] = 1
	x_y := []int{}

	eucl_result := eucl(a, b, &is_inverted)

	for i := len(eucl_result) - 2; i > 0; i-- {
		collum_q = append(collum_q, eucl_result[i])
	}

	collum_xy = append(collum_xy, collum_q[1])

	for i := 2; i < len(collum_q); i++ {
		collum_xy = append(collum_xy, collum_q[i]*collum_xy[i-1]+collum_xy[i-2])
	}

	// Salvando em x e y
	x_y = append(x_y, collum_xy[len(collum_xy)-2])
	x_y = append(x_y, collum_xy[len(collum_xy)-1])

	// Verificando quem é negativo
	if (len(collum_q)-1)%2 == 0 {
		x_y[0] = x_y[0] * (-1)
	}
	if (len(collum_q)-1)%2 != 0 {
		x_y[1] = x_y[1] * (-1)
	}

	// Verificando se devem ser invertidos

	if is_inverted {
		x_y = []int{x_y[1], x_y[0]}
	}

	// Verificando se é diafontina negativa

	if x < 0 {
		x_y[0] = x_y[0] * (-1)
	}
	if y < 0 {
		x_y[1] = x_y[1] * (-1)
	}

	// Multiplicando por c / mdc (a,b)
	x_y[0] = int(x_y[0] * (c / mdc(a, b)))
	x_y[1] = int(x_y[1] * (c / mdc(a, b)))

	// Printando os resultados
	fmt.Printf("Valor de X: %d \nValor de Y: %d\n", x_y[0], x_y[1])
	fmt.Println("Colunas")
	fmt.Println("Q -> ", collum_q)
	fmt.Println("xy -> ", collum_xy)
	fmt.Println("Equações")
	fmt.Printf("Equação geral de X -> %d + %dt\n", x_y[0], y/mdc(a, b))
	fmt.Printf("Equação geral de Y -> %d - %dt\n", x_y[1], x/mdc(a, b))

}

func mdc(x int, y int) int {
	if y > x {
		x, y = y, x
	}

	resto := y

	for resto != 0 {
		y = resto
		resto = x % y
		x = y
	}
	return y
}

func eucl(x int, y int, is_inverted *bool) []int {
	resto := 1
	resultados := []int{}
	*is_inverted = false
	maior := x
	menor := y

	if x < y {
		maior, menor = x, y
		*is_inverted = true
	}

	for resto != 0 {
		resultados = append(resultados, maior/menor)
		resto = maior % menor
		maior = menor
		menor = resto
	}

	return resultados
}
