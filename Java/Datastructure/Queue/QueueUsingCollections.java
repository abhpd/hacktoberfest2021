package com.company;

import java.util.ArrayDeque;
import java.util.Queue;

public class QueueUsingCollections {
    public static void main(String[] args) {
        Queue<Integer> q = new ArrayDeque<Integer>();
        q.offer(10);
        q.offer(15);
        q.offer(20);
        System.out.println(q.poll());
        System.out.println(q.size());
        System.out.println(q.peek());
        System.out.println(q);
        System.out.println(q.peek());
        System.out.println(q.poll());
        System.out.println(q.peek());
    }
}
