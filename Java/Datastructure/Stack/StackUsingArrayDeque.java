package com.company;


import java.util.Stack;

public class StackUsingArrayDeque {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.add(5);
        s.add(45);
        s.add(4);
        s.add(25);
        System.out.println(s.size());
        System.out.println(s.pop());
        System.out.println(s.isEmpty());
        System.out.println(s.peek());
    }
}
