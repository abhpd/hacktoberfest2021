/*
  ==About Me==
  Name = Aakash Jain
  I have written code to implement stack ds using linkedlist, and properly commented it so it can help others too.
*/

import java.util.LinkedList;

public class stackUsingLL {
    public static class stack{
        private LinkedList<Integer> ll = new LinkedList<>();

        public int size(){
            return this.ll.size();  // we will think our stack as linkedlist therefore stck size = linkedlist dize
        }
        public boolean isEmpty(){
            return this.ll.isEmpty();
        }
        public void push(int data){
            ll.addFirst(data); // addFirst is o(1) and easy to implement if asked in interview without using STL
        }
        public int top(){
            return ll.getFirst();// removeFirst is o(1) and easy to implement if asked in interview without using STL
        }
        public int pop(){
            return ll.removeFirst();// getFirst is o(1) and easy to implement if asked in interview without using STL
        }
    }
    public static void main(String[] args){
        stack st = new stack();
        st.push(40);
        System.out.println(st.top());

    }
}
