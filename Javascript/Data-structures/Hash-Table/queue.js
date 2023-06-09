class Queue
{
    // Array is used to implement a Queue
    constructor() //Surprisingly, constructor name is not the same as that of the class.
    {
        this.items = [];
    }
    push(element) //Pushes or Enqueues elements in queue.
    {
        this.items.push(element);
    }
    pop()// pops or dequeues elements from the queue. Returns a string if queue is empty.
    {
        if(this.isEmpty())
            return "Empty. Can't Pop";
        return this.items.shift();
        //Find out more about shift function here https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/shift
    }
    front() //Returns the front of the queue (Zeroth index of the queue).
    {
        if(this.isEmpty())
            return "No elements in Queue";
        return this.items[0];
    }
  isEmpty() //Returns whether the queue is empty or not.
    {
        return this.items.length == 0;
    }
    print() //Returns a string of elements present in the queue.Appends elements one by one into the string.
    {
        var str = "";
        for(var i = 0; i < this.items.length; i++)
            str += this.items[i] +" ";
        return str;
    }
}

let queue = new Queue();
console.log(queue.pop());
console.log(queue.isEmpty());
queue.push(10);
queue.push(20);
queue.push(30);
queue.push(40);
queue.push(50);
queue.push(60);
console.log(queue.isEmpty());
console.log(queue.front());
console.log(queue.pop());
console.log(queue.front());
console.log(queue.pop());
console.log(queue.print());
