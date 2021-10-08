/*
Implementation of a queue data structure. 
The queue will be a class with methods 'add' and 'remove'
The queue will also have a peek method which returns the next element to be removed (without actually removing it)

Note: Queue operates on FIFO basis (First-In-First-Out)
*/

class Queue {
  constructor() {
    this.data = []
  }

  add(record) {
    this.data.unshift(record)
  }

  remove() {
    return this.data.pop();
  }

  peek() {
    return this.data[this.data.length - 1]
  }
}


//Sample Data to check queue instantiation
const q = new Queue()
q.add(1)
q.add(5)
q.add(7)
q.add(10)

console.log(q.remove()) //Returns 1 as it is the first element which entered the queue

console.log(q.peek()) //Returns 5 as it is the next element which is up for removal



