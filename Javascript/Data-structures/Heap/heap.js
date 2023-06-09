class minHeap{
    constructor(){
        this.heap = [null];
        }

    getMin(){
        return this.heap[1];
    }

    insert(data){
        this.heap.push(data);

        if (this.heap.length > 1){
            let current = this.heap.length - 1;

            while (current > 1 && this.heap[Math.floor(current/2)] > this.heap[current]){

                [this.heap[Math.floor(current/2)], this.heap[current]] = [this.heap[current], this.heap[Math.floor(current/2)]]
            }
        }
    }

    remove(){
        let n = this.heap.length;
        if (n === 1)
            return null;
        else if (n === 2)
            this.heap.pop();
        else if(n === 3){
            this.heap[1] = this.heap[2];
            this.heap.pop();
        }
        else{
            [this.heap[n-1], this.heap[1]] = [this.heap[1], this.heap[n-1]];
            this.heap.pop();

            let current = 1;
            let leftChild = 2*current;
            let rightChild = 2*current + 1;

            while(this.heap[leftChild] && this.heap[rightChild] && (this.heap[current] > this.heap[leftChild] || this.heap[current] > this.heap[rightChild])){

                if (this.heap[leftChild] < this.heap[rightChild]){
                    [this.heap[current], this.heap[leftChild]] = [this.heap[leftChild], this.heap[current]];
                    current = leftChild;
                }
                else{
                    [this.heap[rightChild], this.heap[current]] = [this.heap[current], this.heap[rightChild]];
                    current = rightChild;
                }

                leftChild = 2*current;
                rightChild = 2*current + 1;
            }
        }
    }
}

let arr = [1,8,10,4,81,5,48,3,2,84,9]

let mheap = new minHeap();

for(let i of arr)
    mheap.insert(i);

console.log(mheap.heap);
mheap.remove();
console.log(mheap.heap);
mheap.remove();
console.log(mheap.heap);
mheap.remove();
console.log(mheap.heap);
mheap.remove();
console.log(mheap.heap);
