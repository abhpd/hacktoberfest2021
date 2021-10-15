class Queue {
    // Array is used to implement a Queue
    constructor() {
        this.arr = [];
    }

    // Functions to be implemented
    push(i) {
        this.arr.push(i);
    }
    pop() {
        let deleteditem = this.arr[0];
        for (let i = 1; i < this.arr.length; i++)
            this.arr[i - 1] = this.arr[i];
        this.arr.pop();
        return deleteditem;
    }
    size() {
        return this.arr.length;
    }
    list() {
        return this.arr;
    }

    isEmpty() {
        return this.arr.length == 0;
    }
    clear() {
        this.arr = [];
    }
}