class Queue {
    constructor() {
        this.queue = [];
    }

    enqueue = (number) => this.queue.unshift(number);

    dequeue = () => this.queue.pop();

    isEmpty = () => !this.queue.length;

    size = () => this.queue.length;

    front = () => this.queue[this.queue.length - 1];

    rear = () => this.queue[0];

    display = () => console.log(this.isEmpty() ? 'QUEUE IS EMPTY' : '(Rear) ' + this.queue.join(' ⟶ ') + ' (Front)');

    weave = (queue1, queue2) => {
        while (!queue1.isEmpty() || !queue2.isEmpty()) {
            if (!queue1.isEmpty())
                this.enqueue(queue1.dequeue());
            if (!queue2.isEmpty())
                this.enqueue(queue2.dequeue());
        }
    }
}

const queue = new Queue();
[1, 2, 3, 4].forEach(i => queue.enqueue(i));
queue.display(); // (Rear) 4 ⟶ 3 ⟶ 2 ⟶ 1 (Front)
queue.dequeue();
console.log(queue.isEmpty()); // false
queue.dequeue();
queue.display(); // (Rear) 4 ⟶ 3 (Front)
console.log(queue.isEmpty()); // false