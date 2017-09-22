package main

import "fmt"

type person struct {
	name string
	age int
}

func main() {
	fmt.Println(person{"Bob", 25})
	fmt.Println(person{name: "Bob", age: 25})
	fmt.Println(person{name: "Bob"})
	fmt.Println(person{name: "Bob"})
	fmt.Println(&person{name: "Bob"})

	p := person{"zwt", 27}
	fmt.Println("name:", p.name)

	sp := &p
	fmt.Println("name:", sp.name)

	sp.name = "xxxx"
	fmt.Println("name:", sp.name)
}
