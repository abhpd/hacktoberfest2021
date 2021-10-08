package com.company;
import java.io.*;
import java.util.*;
public class StackUsingArrayList {


    static class MyStack{

        ArrayList<Integer> al=new ArrayList<>();
        void push(int x){
            al.add(x);
        }

        int pop(){
            int res=al.get(al.size()-1);
            al.remove(al.size()-1);
            return res;
        }

        int peek(){
            return al.get(al.size()-1);
        }

        int size(){
            return al.size();
        }

        boolean isEmpty(){
            return al.isEmpty();
        }
    }

        public static void main (String[] args)
        {
            StackUsingArrayList.MyStack s=new StackUsingArrayList.MyStack();
            s.push(5);
            s.push(10);
            s.push(20);
            System.out.println(s.pop());
            System.out.println(s.size());
            System.out.println(s.peek());
            System.out.println(s.isEmpty());
        }

}
