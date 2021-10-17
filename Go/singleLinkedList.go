package main

import "fmt"

// HEADPOSITION in the starting index in the linked list
const HEADPOSITION = 1

// Node represents an individual node in the linked list
type Node struct {
	Value    int32
	NextNode *Node
}

// LinkedList represents a linked list object
type LinkedList struct {
	Head *Node
}

func main() {
	var nums = []int32{1, 2, 3, 4, 5}
	// 1 -> 2 -> 3 -> 4 -> 5
	list := CreateNewList(nums)
	list.Print()

	// 6 -> 1 -> 2 -> 3 -> 4 -> 5
	list.InsertFirst(6)
	list.Print()

	// 6 -> 1 -> 2 -> 3 -> 4 -> 5 -> 7
	list.InsertLast(7)
	list.Print()

	// 6 -> 1 -> 8 -> 2 -> 3 -> 4 -> 5 -> 7
	list.InsertPosition(8, 3)
	list.Print()

	// 1 -> 8 -> 2 -> 3 -> 4 -> 5 -> 7
	list.RemoveFirst()
	list.Print()

	// 1 -> 8 -> 2 -> 3 -> 4 -> 5
	list.RemoveLast()
	list.Print()

	// 1 -> 8 -> 3 -> 4 -> 5
	list.RemovePosition(3)
	list.Print()
}

// CreateNewList creates a new linked list object
func CreateNewList(input []int32) *LinkedList {
	var newList = &LinkedList{}
	for _, num := range input {
		newList.InsertLast(num)
	}
	return newList
}

// NewNode returns a pointer to a new node in the linked list
func NewNode(value int32) *Node {
    return &Node{
        Value: value,
        NextNode: nil,
    }
}

// InsertFirst inserts a node at the start of the linked list
func (ll *LinkedList) InsertFirst(value int32) {
	newNode := NewNode(value)
	if ll.Head == nil {
		ll.Head = newNode
		return
	}
	newNode.NextNode = ll.Head
	ll.Head = newNode
}

// InsertLast inserts a node at the end of the linked list
func (ll *LinkedList) InsertLast(value int32) {
	if ll.Head == nil {
		ll.Head = NewNode(value)
		return
	}
	node := ll.Head
	for node.NextNode != nil {
		node = node.NextNode
	}
	node.NextNode = NewNode(value)
}

// InsertPosition inserts a node at a particular position in the linked list
func (ll *LinkedList) InsertPosition(value int32, position int32) {
	if ll.Head == nil {
		ll.Head = NewNode(value)
		return
	}
	node := ll.Head
	prevNode := ll.Head
	var count int32 = HEADPOSITION
	for node.NextNode != nil {
		if count == position {
			newNode := NewNode(value)
			if position == HEADPOSITION {
				ll.InsertFirst(value)
				break
			} else {
				newNode.NextNode = prevNode.NextNode
				prevNode.NextNode = newNode
				break
			}
		}
		count++
		prevNode = node
		node = node.NextNode
	}
}

// RemoveFirst removes a node from the start of the linked list
func (ll *LinkedList) RemoveFirst() {
	if ll.Head == nil {
		return
	}
	ll.Head = ll.Head.NextNode
}

// RemoveLast removes a node from the end of the linked list
func (ll *LinkedList) RemoveLast() {
	if ll.Head == nil {
		return
	}
	node := ll.Head
	prevNode := ll.Head
	for node.NextNode != nil {
		prevNode = node
		node = node.NextNode
	}
	prevNode.NextNode = nil
}

// RemovePosition removes a node from a particular position in the linked list
func (ll *LinkedList) RemovePosition(position int32) {
	if ll.Head == nil {
		return
	}
	node := ll.Head
	prevNode := ll.Head
	var count int32 = HEADPOSITION
	for node.NextNode != nil {
		if count == position {
			if position == HEADPOSITION {
				ll.RemoveFirst()
				break
			} else {
				prevNode.NextNode = node.NextNode
				break
			}
		}
		count++
		prevNode = node
		node = node.NextNode
	}
}

// Print prints the entire linked list
func (ll *LinkedList) Print(){
	node := ll.Head
	for node.NextNode != nil {
		fmt.Printf("%d -> ", node.Value)
		node = node.NextNode
	}
	fmt.Printf("%d\n", node.Value)
}
