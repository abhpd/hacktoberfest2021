/**
 * Author:  Pavara Manupriya
 * Date:    12.10.2021
 */

public class QueueArrayImplementation {
    public static void main(String[] args) {

        QueueArray z = new QueueArray(6); // Calling QueueArray constructor by passing a value

        try{
            z.display();
            z.enqueue(34);
            z.enqueue(67);
            z.enqueue(98);
            z.enqueue(23);
            z.enqueue(65);
            z.display();
            z.dequeue();
            z.display();
            System.out.println("Peek is :"+z.peek());
        }catch(Exception e){
            System.out.println(e.toString());
        }
    }
}

class QueueArray {

    private int maxSize; // maximum number of elements can be contained
    private int[] queArray; //array for storing the Queue elements
    private int front; // points the front element of the Queue
    private int rear; // points the last elements of the Queue
    private int nItems; // current size of the Queue

    public QueueArray(int s){
        this.queArray= new int [s]; // Creating Queue array according to the provided value
        this.maxSize=s;  //The size of the Queue can't exceed the provided value
        this.front=0;
        this.rear=-1;
        this.nItems=0;
    }

    public boolean isEmpty(){
        //If the Queue is empty, there are no elements in the queue.
        return this.nItems==0;
    }

    public boolean isFull(){
        //If the Queue is full, current number of elements should be equal to the maximum size.
        return this.nItems== this.maxSize;
    }

    public int size(){
        return this.nItems;
    }

    //Method to add a value to the Queue.
    public void enqueue(int value){
        //checking overflow
        if(isFull()){
            System.out.println("Queue is Full. Cannot enqueue");
            return;
        }

        rear = (rear+1)%maxSize;
        this.queArray[rear]=value;
        this.nItems++;

    }

    //Method to remove the front element from the Queue
    public int dequeue() throws Exception{
        //checking underflow
        if(isEmpty()){
            throw new Exception("Queue is empty cannot removed");
        }
        int removedItem = this.queArray[front];
        front=(front+1)%maxSize;
        nItems--;
        return removedItem;
    }

    //Method to find the front element
    public int peek() throws Exception{
        if(isEmpty()){
            throw new Exception("Queue is Empty cannot get peek value");
        }
        return this.queArray[this.front];
    }

    //Method to retrieve all the values in the Queue
    public void display(){
        if(isEmpty()){
            System.out.println("Queue is Empty. Nothing to print");
            return;
        }
        int i  = this.front;
        while(i!=rear){
            System.out.print(this.queArray[i]+" ");
            if(i==maxSize-1){
                i=0;
            }
            else{
                i++;
            }
        }
        System.out.print(this.queArray[rear]);
        System.out.println();

    }
}