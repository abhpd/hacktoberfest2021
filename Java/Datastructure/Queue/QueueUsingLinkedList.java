package com.company;

class Node{
    int key;
    Node next;

    public Node(int key){
        this.key=key;
        this.next=null;
    }
}

class Queue{
    Node front, rear;

    public Queue(){
        this.front=this.rear=null;
    }

    void enQueue(int key){
        Node temp = new Node(key);
        if (this.rear==null){
            this.rear=this.front=temp;
            return;
        }
        this.rear.next=temp;
        this.rear=temp;
    }

    void Dequeue(){
        if (this.front==null){
            System.out.println("Queue is empty");
            return;
        }
        Node temp = this.front;
        this.front=this.front.next;
        if (this.front==null){
            this.rear=null;
        }
    }



}


public class QueueUsingLinkedList {
    public static void main(String[] args) {
        Queue q = new Queue();
        q.enQueue(5);
        q.enQueue(85);
        q.enQueue(54);
        q.enQueue(52);
        q.enQueue(7);

        q.Dequeue();

        System.out.println("Queue front : "+ q.front.key);
        System.out.println("Queue rear : "+ q.rear.key);


    }
}
