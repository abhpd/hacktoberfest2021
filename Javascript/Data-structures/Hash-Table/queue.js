//queue implementation core Class
class Queue {
  constructor() {
    this.items = [];
    this.front = null;
    this.back = null;
  }
//checks if the the queue is empty 
  isEmpty() {
    return this.items.length == 0;
  }

  getFront() {
    if (this.items.length != 0) {
      return this.items[0];
    } else return null;
  }
// returns the size of the queue
  size() {
    return this.items.length;
  }
//appends the element 
  enqueue(element) {
    this.items.push(element);
  }
//removes the element
  dequeue() {
    if (this.items.length == 0) {
      return null;
    } else {
      return this.items.shift();
    }
  }
}
//core function
function findBin(n) {
  let result = [];
  let myQueue = new Queue();
  var s1, s2;
  myQueue.enqueue("1");
  for (var i = 0; i < n; i++) {
    result.push(myQueue.dequeue());
    s1 = result[i] + "0";
    s2 = result[i] + "1";

    myQueue.enqueue(s1);
    myQueue.enqueue(s2);
  }

  return result;
}
//enter the number of binary digits to be displayed 
console.log(findBin(10));
