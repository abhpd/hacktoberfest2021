class Node {
  constructor(data, next = null) {
    this.data = data;
    this.next = next;
  }
}

class LinkedList {
  constructor(head = null) {
    this.head = head;
  }

  insert(node) {
    if (this.head === null) {
      this.head = node;
      return;
    }
    let curr = this.head;
    while (curr.next) {
      curr = curr.next;
    }
    curr.next = node;
  }

  display() {
    let curr = this.head;
    while (curr) {
      console.log(curr.data);
      curr = curr.next;
    }
  }

  deleteNode(data) {
    let curr = this.head;
    if (curr && curr.data === data) {
      this.head = curr.next;
      return;
    }
    while (curr.next) {
      if (curr.next.data === data) {
        curr.next = curr.next.next;
        return;
      }
      curr = curr.next;
    }
  }
}

let arr = [1, 2, 3, 4, 5, 6];

const ll = new LinkedList();

for (let i of arr) {
  const newNode = new Node(i);
  ll.insert(newNode);
}

ll.display();
ll.deleteNode(1);
ll.display();
