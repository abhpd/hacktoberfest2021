/**
 * PalindromeLinkedList
 */
import java.util.*;
class Node {
    int data;
    Node next;
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}
class LinkedList {
    Node head;
    public void add(int val) {
        Node node = new Node(val);
        if(head==null) {
            head = node;
        }
        else {
            node.next = head;
            head = node;
        }
    }
    public void display() {
        Node temp = head;
        while(temp!=null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }
    public boolean palindrome() {
        if(head==null)
            return true;
        StringBuilder sb = new StringBuilder("");
        Node temp = head;
        while(temp!=null) {
            sb.append(temp.data);
            temp = temp.next;
        }
        String org = sb.toString();
        String rev = sb.reverse().toString();
        System.out.println(org + " " + rev);
        return rev.equals(org);
    }
}
public class PalindromeLinkedList {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.add(11);
        ll.add(22);
        ll.add(33);
        ll.add(44);
        ll.add(55);
        // ll.display();

        System.out.println("The linked list is a palindrome:- " + ll.palindrome());
    }
}
