package main

import (
	"errors"
	"fmt"
	"log"
)

type Stack []interface{}

func main() {
	var stack Stack

	stack.Push("shirt")
	stack.Push("free")	
	stack.Push("my")
	stack.Push("is")
	stack.Push("where")

	for len(stack) > 0 {
		value, err := stack.Pop()
		if err != nil{
			log.Fatal(err.Error())
		}else{
			fmt.Println(value)
		}
	}
}

func (s *Stack) Push(value interface{}) {
	*s = append(*s, value)
}

func (s *Stack) Pop() (interface{}, error) {
	if len(*s) == 0 {
		return "", errors.New("cannot pop from empty stack")
	} else {
		index := len(*s) - 1
		element := (*s)[index]
		*s = (*s)[:index]
		return element, nil
	}
}