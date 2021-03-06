package main

import "fmt"

type rect struct {
	height, width int
}

func (r *rect) area() int {
	return r.width * r.height
}

func (r rect) perim() int {
	return 2*r.width + 2*r.height
}

func main() {
	r := rect{40, 100}
	fmt.Println("area:", r.area())
	fmt.Println("perim:", r.perim())

	r = rect{90, 10}
	fmt.Println("area:", r.area())
	fmt.Println("perim:", r.perim())

}
