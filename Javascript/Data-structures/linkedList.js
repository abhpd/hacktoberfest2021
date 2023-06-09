// List Class
class LinkedList {
  constructor(head = null) {
      this.head = head
  }
  // method to know the length of the linked list
  size() {
    let count = 0; 
    let node = this.head;
    while (node) {
        count++;
        node = node.next
    }
    return count;
  }
  // method to clear the head of the linked list
  clear() {
    this.head = null;
  }
  // method to get the last node in the linked list
  getLast() {
    let lastNode = this.head;
    if (lastNode) {
        while (lastNode.next) {
            lastNode = lastNode.next
        }
    }
    return lastNode
  }
  // method to get the first noe in the linked list
  getFirst() {
    return this.head
  }
}

// Node Class
class ListNode {
  constructor(data) {
      this.data = data
      this.next = null                
  }
}

// Creating Nodes
let node1 = new ListNode(2)
let node2 = new ListNode(5)
node1.next = node2

// Creating List
let list = new LinkedList(node1)

// Return 5
console.log(list.head.next.data)

