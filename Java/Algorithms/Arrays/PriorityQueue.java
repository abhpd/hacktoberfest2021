//Added the code for a Priority Queue using an array in Java

//
public class PriorityQueue {
    private int[] items = new int[5];
    private int count;

    public PriorityQueue() {

// Add a new item to the priority Queue
    public void add(int item) {
        if (this.isFull()) {
            throw new IllegalStateException();
        } else {
            int i = this.shiftItemsToInsert(item);
            this.items[i] = item;
            ++this.count;
        }
    }

//To check if the array is full
    public boolean isFull() {
        return this.count == this.items.length;
    }

//Shifting the Items from the end to the beginning and insert new item
    private int shiftItemsToInsert(int item) {
        int i;
        for(i = this.count - 1; i >= 0 && this.items[i] > item; --i) {
            this.items[i + 1] = this.items[i];
        }

        return i + 1;
    }

//Remove an item
    public int remove() {
        if (this.isEmpty()) {
            throw new IllegalStateException();
        } else {
            return this.items[--this.count];
        }
    }

//To check if the array is empty
    public boolean isEmpty() {
        return this.count == 0;
    }

    public String toString() {
        return Arrays.toString(this.items);
    }
}
