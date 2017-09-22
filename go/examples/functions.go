package main

import "fmt"

func plus(a int, b int) int {
	return a + b
}

func plusPlus(a, b, c int) int {
	return a + b + c
}

func main() {
	res := plus(3, 4)
	fmt.Println("3 + 4 =", res)

	res = plusPlus(3, 4, 5)
	fmt.Println("3 + 4 + 5=", res)
}
