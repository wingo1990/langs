package main

import "fmt"

func sum(nums ...int) {
	fmt.Println("nums:", nums)
	tatol := 0
	for num := range nums {
		tatol += num;
	}
	fmt.Println("total:", tatol);
}

func main() {
	sum(1, 2)

	sum(2,3,4,5)

	nums := []int{1,2,3,4,5,6}
	sum(nums...)
}
