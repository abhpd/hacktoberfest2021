/*
  ==About Me==
  Name = Aakash Jain
  I have written code to implement queue ds using linkedlist, and properly commented it so it can help others too.
*/

import java.util.LinkedList;

public class queueUsingLL {
    public static class queue{
        private LinkedList<Integer> ll = new LinkedList<>();

        public int size(){
            return this.ll.size();// we will think our queue as linkedlist therefore stck size = linkedlist size
        }
        public boolean isEmpty(){
            return this.ll.isEmpty();
        }
        public void add(int data){
            ll.addLast(data);// addFirst is o(1) and easy to implement if asked in interview without using STL
        }
        public int remove(){
            return ll.removeFirst();// removeFirst is o(1) and easy to implement if asked in interview without using STL
        }
        public int peek(){
            return ll.getFirst();// getFirst is o(1) and easy to implement if asked in interview without using STL
        }
    }
    public static void main(String[] args){
        queue que = new queue();
        que.add(40);
        System.out.println(que.peek());

    }
}
