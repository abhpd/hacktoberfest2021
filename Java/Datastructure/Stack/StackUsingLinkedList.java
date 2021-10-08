package com.company;

public class StackUsingLinkedList {
    Node root;

    public static class Node{
        int data;
        Node next;
        Node(int d){
           data = d;
            next=null;
        }
    }

    public boolean isEmpty(){
        return root==null;
    }

    public void push(int data){
        Node newNode = new Node(data);
        if (root==null){
            root=newNode;
        }else {
            Node temp = root;
            root = newNode;
            newNode.next=temp;
        }
    }

    public int pop(){
        int popped = Integer.MIN_VALUE;
        if (root==null){
            System.out.println("Stack is empty");
        }else {

            popped=root.data;
            root=root.next;
        }
        return popped;
    }

    public int peek(){
        if (root==null){
            System.out.println("Stack is empty");
            return Integer.MIN_VALUE;
        }else {
            return root.data;
        }
    }


    public static void main(String[] args) {
        StackUsingLinkedList sll = new StackUsingLinkedList();
//        System.out.println(sll.pop());
        sll.push(10);
        sll.push(20);
        sll.push(30);

        System.out.println(sll.pop() + " is popped");

        System.out.println("top element is "+ sll.peek());


    }
}
