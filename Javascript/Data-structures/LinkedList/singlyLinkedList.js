class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

// linkedlist class
class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
}

// adds a node to the end of the list
push = (val) => {
  //make a new Node
  const newNode = new Node(val);
  //if list is empty, make node head and tail
  if (!this.head) {
    this.head = newNode;
    this.tail = newNode;
    //otherwise add node to the end of the list
  } else {
    this.tail.next = newNode;
    this.tail = newNode;
  }
  //add 1 to the length
  this.length++;
  //return list
  return this;
};

unshift = (val) => {
  const newNode = new Node(val);
  //if list is empty, make node head and tail
  if (!this.head) {
    this.head = newNode;
    this.tail = newNode;
    //add current head pointer to new head(new node), and make new node new head
  } else {
    newNode.next = this.head;
    this.head = newNode;
  }
  //add 1 to the length
  this.length++;
  //return list
  return this;
};

// removes first item in list
shift = () => {
  //if list is empty, return false
  if (!this.head) {
    return false;
  }
  //get shifted node
  const shiftNode = this.head;
  //get new head (could be NULL if list is length 2)
  const newHead = this.head.next;
  //if newHead is null, reassign tail to newHead(null)
  if (!newHead) {
    this.tail = newHead;
  }
  //assign new head
  this.head = newHead;
  //remove 1 from length
  this.length--;
  //return shifted node
  return shiftNode;
};

//return node at given index
getNodeAtIndex = (index) => {
  //if index is not within list return null
  if (index >= this.length || index < 0) {
    return null;
  }
  //iterate through list until finding the one at index
  let currentNode = this.head;
  let currentIndex = 0;
  while (currentIndex !== index) {
    currentNode = currentNode.next;
    currentIndex++;
  }
  return currentNode;
};

// removes a node from the end of the list
pop = () => {
  //if list is empty(has no tail) return false
  if (!this.tail) {
    return false;
  }
  //get removed node
  const poppedNode = this.tail;
  // if list has more than 1 node
  if (this.head !== this.tail) {
    //find new tail
    const newTail = this.getNodeAtIndex(this.length - 2);
    //remove newtail's reference to poppedNode
    newTail.next = null;
    //make it new tail
    this.tail = newTail;
    //otherwise establish list is empty
  } else {
    this.head = null;
    this.tail = null;
  }
  //subtract 1 from length
  this.length--;
  //return poppedNode
  return poppedNode;
};

//change the node at the given index
setNodeAtIndex = (val, index) => {
  //find the node using already built method
  const foundNode = this.getNodeAtIndex(index);
  //if the node is found update and return
  if (foundNode) {
    foundNode.value = val;
    return foundNode;
  }
  //else return null
  return null;
};

//insert a new node at the index with the given value
insertAtIndex = (index, val) => {
  //if index not valid return false
  if (index < 0 || index > this.length) {
    return false;
  }
  //if index is zero use already built unshift
  if (index === 0) {
    return this.unshift(val);
  }
  //if index is at end of list, use already built push
  if (index === this.length) {
    return this.push(val);
  }
  // make a new node, find the nodes before and after it, make before's next the new node, and the newNode's next the after
  const newNode = new Node(val);
  const after = this.getNodeAtIndex(index);
  const before = this.getNodeAtIndex(index - 1);
  newNode.next = after;
  before.next = newNode;

  this.length++;
  return this;
};

// remove node from index
removeFrom = (index) => {
  //if index is invalid return false
  if (index < 0 || index >= this.length) {
    return false;
  }
  //if index is at beginning use already built shift
  if (index === 0) return this.shift();
  //if index is at end use already built pop
  if (index === this.length - 1) return this.pop();
  //get before and after, set before's next to after and remove after's reference from removed Node
  const before = this.getNodeAtIndex(index - 1);
  const removedNode = this.getNodeAtIndex(index);
  before.next = removedNode.next;
  removedNode.next = null;

  this.length--;
  return removedNode;
};

printList = () => {
  console.log(list);
  if (this.head) {
    let current = this.head;
    while (current.next) {
      console.log(current);
      current = current.next;
    }
    console.log(current);
  } else {
    console.log("empty list");
  }
};
